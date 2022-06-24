/*
 * ======================================================================
 * DFG.cpp
 * ======================================================================
 * DFG implementation.
 *
 * Author : Cheng Tan
 *   Date : July 16, 2019
 */

#include <fstream>
#include "json.hpp"
#include "DFG.h"
#include "MapResult.h"
using nlohmann::json;

DFG::DFG(DFG &old): m_function(old.m_function) {
	m_num = old.m_num;
	m_targetFunction = old.m_targetFunction;

	m_targetLoops = old.m_targetLoops;
	m_orderedNodes = old.m_orderedNodes;
	m_CDFGFused = old.m_CDFGFused;
	m_cycleNodeLists = new list<list<DFGNode*>*>();
	m_precisionAware = old.m_precisionAware;

	m_initExecLatency = old.m_initExecLatency;
	m_initPipelinedOpt = old.m_initPipelinedOpt;

	// TODO --- construct from the other DFG's
	// node list, not the random crap here.
	construct(old.m_function);
  // if (t_heterogeneity) { I added this function, (JCW) and we
	// always use heterogeneity :)
    calculateCycles();
//    combine("phi", "add");
    // combine("and", "xor");
//    combine("br", "phi");
//    combine("add", "icmp");
//    combine("xor", "add");
    // combineCmpBranch();
    // combine("icmp", "br");
    // combine("getelementptr", "load");
    tuneForPattern();

//    calculateCycles();
////    combine("icmp", "br");
//    combine("xor", "add");
//    tuneForPattern();
  // }
//  trimForStandalone();
  initExecLatency(m_initExecLatency);
  initPipelinedOpt(m_initPipelinedOpt);
}

// Lots of stuff left empty in this definition, trying to only capture what really needs to be captured.
DFG::DFG(list<DFGNode *> nodes, list<DFGEdge*> edges): m_function(nullptr), nodes(nodes), m_DFGEdges(edges) {
  m_num = 0;
  // can these be null?
  m_targetFunction = true;
  m_targetLoops = nullptr;
  m_orderedNodes = NULL;
  m_CDFGFused = false;
  m_cycleNodeLists = new list<list<DFGNode*>*>();
  // TODO -- get these from the config file.
  m_precisionAware = false;
  m_initPipelinedOpt = new list<string>();
  m_initExecLatency = new map<string, int>();
}

DFG::DFG(std::string filename) {
  cout << "Loading DFG From File\n";
  std::ifstream i(filename);
  json j;
  i >> j;

  // These arent needed --- they are from the CGRA mapper pass to allow it
  // to extract from the llvm function --- if we are already in a DFG then there's
  // not an issue.
  m_orderedNodes = nullptr;
  m_targetFunction = true;
  m_targetLoops = nullptr;
  m_orderedNodes = NULL;
  m_CDFGFused = false;
  m_cycleNodeLists = new list<list<DFGNode*>*>();
  // TODO -- get these from the config file.
  m_precisionAware = false;
  m_initPipelinedOpt = new list<string>();
  m_initExecLatency = new map<string, int>();

  // Map to let us build the edges.
  map<string, DFGNode*> node_name_lookup;

  // Get the nodes:
  cout << "Loading Nodes\n";
  int id = 0;
  for (json node : j["nodes"]) {
    std::string node_name = node["name"].get<std::string>();
    DFGNode *n = new DFGNode(id ++, false, nullptr, node["operation"].get<std::string>(), node_name);
    nodes.push_back(n);
    node_name_lookup.insert({node_name, n});
  }

  cout << "Loading Edges\n";
  // Get the edges.
  for (json edge : j["edges"]) {
    cout << "Loading edge" << edge["to"].get<std::string>();
    DFGNode *tnode = node_name_lookup.at(edge["to"].get<std::string>());
    DFGNode *fnode = node_name_lookup.at(edge["from"].get<std::string>());

    DFGEdge *thisEdge = new DFGEdge(id++, fnode, tnode);
    tnode->addInEdge(thisEdge);
    fnode->addOutEdge(thisEdge);
    m_DFGEdges.push_back(thisEdge);
    // todo --- The Json file has a "type" field to distinguish between
    // control edges and data edges.  Need to handle that.
  }
}

DFG::DFG(Function *t_F, list<Loop*>* t_loops, bool t_targetFunction,
         bool t_precisionAware, bool t_heterogeneity,
         map<string, int>* t_execLatency, list<string>* t_pipelinedOpt): m_function(t_F) {
  m_num = 0;
  m_targetFunction = t_targetFunction;
  m_targetLoops = t_loops;
  m_orderedNodes = NULL;
  m_CDFGFused = false;
  m_cycleNodeLists = new list<list<DFGNode*>*>();
  m_precisionAware = t_precisionAware;
  m_initPipelinedOpt = t_pipelinedOpt;
  m_initExecLatency = t_execLatency;

  construct(t_F);
//  tuneForBranch();
//  tuneForBitcast();
//  tuneForLoad();
  if (t_heterogeneity) {
    calculateCycles();
//    combine("phi", "add");
    // combine("and", "xor");
//    combine("br", "phi");
//    combine("add", "icmp");
//    combine("xor", "add");
    // combineCmpBranch();
    // combine("icmp", "br");
    // combine("getelementptr", "load");
    tuneForPattern();

//    calculateCycles();
////    combine("icmp", "br");
//    combine("xor", "add");
//    tuneForPattern();
  }
//  trimForStandalone();
  initExecLatency(t_execLatency);
  initPipelinedOpt(t_pipelinedOpt);

}

std::string DFG::asString() {
	std::string graph = "Graph (" + std::to_string(nodes.size()) + " nodes): ";
	for (DFGNode *n : nodes) {
		if (n != nullptr)
			graph = graph + n->asString() + ", ";
		else
			graph = graph + " null, ";
	}

	return graph;
}

// FIXME: only combine operations of mul+alu and alu+cmp for now,
//        since these two are the most common patterns across all
//        the kernels.
void DFG::tuneForPattern() {

  // reconstruct connected DFG by modifying m_DFGEdge
  list<DFGNode*>* removeNodes = new list<DFGNode*>();
  for (DFGNode* dfgNode: nodes) {
    if (dfgNode->hasCombined()) {
      if (dfgNode->isPatternRoot()) {
        for (DFGNode* patternNode: *(dfgNode->getPatternNodes())) {
          if (hasDFGEdge(dfgNode, patternNode))
            m_DFGEdges.remove(getDFGEdge(dfgNode, patternNode));
          for (DFGNode* predNode: *(patternNode->getPredNodes())) {
            if (predNode == dfgNode or
                predNode->isOneOfThem(dfgNode->getPatternNodes())) {
              deleteDFGEdge(predNode, patternNode);
              continue;
            }
            DFGNode* newPredNode = NULL;
            if (predNode->hasCombined())
              newPredNode = predNode->getPatternRoot();
            else
              newPredNode = predNode;
            replaceDFGEdge(predNode, patternNode, newPredNode, dfgNode);
          }
          for (DFGNode* succNode: *(patternNode->getSuccNodes())) {
            if (succNode == dfgNode or
                succNode->isOneOfThem(dfgNode->getPatternNodes())) {
              deleteDFGEdge(patternNode, succNode);
              continue;
            }
            DFGNode* newSuccNode = NULL;
            if (succNode->hasCombined())
              newSuccNode = succNode->getPatternRoot();
            else
              newSuccNode = succNode;
            replaceDFGEdge(patternNode, succNode, dfgNode, newSuccNode);
          }

        }
      } else {
        removeNodes->push_back(dfgNode);
      }
    }
  }
  for (DFGNode* dfgNode: *removeNodes) {
    nodes.remove(dfgNode);
  }
}

void DFG::removeNode(DFGNode *node) {
	nodes.remove(node);
}

void DFG::removeNodes(list<DFGNode*> *nodes) {
	for (DFGNode * n : *nodes) {
		removeNode(n);
	}
}

void DFG::combineCmpBranch() {
  // detect patterns (e.g., cmp+branch)
  DFGNode* addNode = NULL;
  DFGNode* cmpNode = NULL;
  DFGNode* brhNode = NULL;
  bool found = false;
  for (DFGNode* dfgNode: nodes) {
    if (dfgNode->isAdd() and !dfgNode->hasCombined()) {
      found = false;
      for (DFGNode* succNode: *(dfgNode->getSuccNodes())) {
        if (succNode->isCmp() and !succNode->hasCombined()) {
          for (DFGNode* succSuccNode: *(succNode->getSuccNodes())) {
            if (succSuccNode->isBranch() and !succSuccNode->hasCombined() and
                succSuccNode->isSuccessorOf(dfgNode)) {
              addNode = dfgNode;
              addNode->setCombine();
              cmpNode = succNode;
              addNode->addPatternPartner(cmpNode);
              cmpNode->setCombine();
              brhNode = succSuccNode;
              addNode->addPatternPartner(brhNode);
              brhNode->setCombine();
              found = true;
              break;
            }
          }
        }
        if (found) break;
      }
    }
  }
}

void DFG::combineMulAdd() {
  // detect patterns (e.g., mul+alu)
  DFGNode* mulNode = NULL;
  DFGNode* addNode = NULL;
  bool found = false;
  for (DFGNode* dfgNode: nodes) {
    if (dfgNode->isMul() and dfgNode->isCritical() and !dfgNode->hasCombined()) {
      for (DFGNode* succNode: *(dfgNode->getSuccNodes())) {
        if (succNode->isAdd() and succNode->isCritical() and !succNode->hasCombined()) {
          mulNode = dfgNode;
          mulNode->setCombine();
          addNode = succNode;
          mulNode->addPatternPartner(addNode);
          addNode->setCombine();
          break;
        }
      }
    }
  }
}

void DFG::combine(string t_opt0, string t_opt1) {
  DFGNode* opt0Node = NULL;
  DFGNode* opt1Node = NULL;
  bool found = false;
  for (DFGNode* dfgNode: nodes) {
//    if (dfgNode->isOpt(t_opt0) and dfgNode->isCritical() and !dfgNode->hasCombined()) {
    if (dfgNode->isOpt(t_opt0) and !dfgNode->hasCombined()) {
      for (DFGNode* succNode: *(dfgNode->getSuccNodes())) {
        if (succNode->isOpt(t_opt1) and !succNode->hasCombined()) {
          opt0Node = dfgNode;
          opt0Node->setCombine();
          opt1Node = succNode;
          opt0Node->addPatternPartner(opt1Node);
          opt1Node->setCombine();
          break;
        }
      }
    }
  }
}

bool DFG::shouldIgnore(Value* t_value) {
  if (m_targetFunction) {
    return false;
  }
  if (!isa<Instruction> (t_value)) {
	  // We don't ingnore constants?  IDK what to do here.
	  return false;
  }
  Instruction *t_inst = cast<Instruction>(t_value);
  if (m_targetLoops->size() == 0)
    return false;
  for (Loop* current_loop: *m_targetLoops) {
	  bool contains = current_loop->contains(t_inst);
	  std::string str;
	llvm::raw_string_ostream rso(str);
	t_inst->print(rso);
	  cout << "Looking at membership for instruction " << str << "\n;" << "result is " << contains << "\n";
    if (contains) {
      return false;
    }
  }
  return true;
}

list<DFGNode*>* DFG::getDFSOrderedNodes() {
  if (m_orderedNodes != NULL)
    return m_orderedNodes;
  m_orderedNodes = new list<DFGNode*>();
  list<DFGNode*> tempNodes;
  while (m_orderedNodes->size() < nodes.size()) {
    DFGNode* startNode = NULL;
    int curWithMaxSucc = 0;
    for (DFGNode* dfgNode: nodes) {
      if (find(m_orderedNodes->begin(), m_orderedNodes->end(), dfgNode) ==
          m_orderedNodes->end()) {
        if (dfgNode->getSuccNodes()->size() > curWithMaxSucc) {
          curWithMaxSucc = dfgNode->getSuccNodes()->size();
          startNode = dfgNode;
        }
      }
    }
    if (startNode != NULL) {
      assert( find(m_orderedNodes->begin(), m_orderedNodes->end(), startNode) ==
          m_orderedNodes->end() );
      tempNodes.push_back(startNode);
      m_orderedNodes->push_back(startNode);
    }
//    for (DFGNode* dfgNode: nodes) {
//      if (find(m_orderedNodes->begin(), m_orderedNodes->end(), dfgNode) ==
//          m_orderedNodes->end()) {
//        tempNodes.push_back(dfgNode);
//        m_orderedNodes->push_back(dfgNode);
//        break;
//      }
//    }
    DFGNode* currentNode;
    while (tempNodes.size() != 0) {
      currentNode = tempNodes.back();
      list<DFGNode*>* succNodes = currentNode->getSuccNodes();
      bool canPop = true;
      for (DFGNode* succNode: *succNodes) {
        if (find(m_orderedNodes->begin(), m_orderedNodes->end(), succNode) ==
            m_orderedNodes->end()) {
          tempNodes.push_back(succNode);
          canPop = false;
          m_orderedNodes->push_back(succNode);
          break;
        }
      }
      if (canPop) {
        tempNodes.pop_back();
      }
    }
  }
  errs()<<"\nordered nodes: \n";
  for (DFGNode* dfgNode: *m_orderedNodes) {
    errs()<<dfgNode->getID()<<"  ";
  }
  errs()<<"\n";
  errs()<<"\nedges:\n";
  errs()<<"\n noes:\n";
  for (DFGNode *node : nodes) {
	  errs()<<node->getID()<<" ";
	  for (DFGEdge *edge : *node->getInEdges()) {
		  errs() << "Edge: " << edge->asString();
	  }
  }
  errs()<<"\n";
  assert(m_orderedNodes->size() == nodes.size());
  return m_orderedNodes;
}

list<DFGNode*>* DFG::getBFSOrderedNodes() {
  if (m_orderedNodes != NULL)
    return m_orderedNodes;
  m_orderedNodes = new list<DFGNode*>();
  list<DFGNode*> tempNodes;
  while (m_orderedNodes->size() < nodes.size()) {
    for (DFGNode* dfgNode: nodes) {
      if (find(m_orderedNodes->begin(), m_orderedNodes->end(), dfgNode) ==
            m_orderedNodes->end()) {
        tempNodes.push_back(dfgNode);
        m_orderedNodes->push_back(dfgNode);
        break;
      }
    }
    DFGNode* currentNode;
    while (tempNodes.size() != 0) {
      currentNode = tempNodes.front();
      tempNodes.pop_front();
      for (DFGNode* succNode: *currentNode->getSuccNodes()) {
        if (find(m_orderedNodes->begin(), m_orderedNodes->end(), succNode) ==
            m_orderedNodes->end()) {
          tempNodes.push_back(succNode);
          m_orderedNodes->push_back(succNode);
        }
      }
    }
  }
  errs()<<"\nordered nodes: \n";
  for (DFGNode* dfgNode: *m_orderedNodes) {
    errs()<<dfgNode->getID()<<"  ";
  }
  errs()<<"\n";
  assert(m_orderedNodes->size() == nodes.size());
  return m_orderedNodes;
}

// extract DFG from specific function
void DFG::construct(Function *t_F) {

  m_DFGEdges.clear();
  nodes.clear();
  m_ctrlEdges.clear();

  int nodeID = 0;
  int ctrlEdgeID = 0;
  int dfgEdgeID = 0;

  errs()<<"*** current function: "<<t_F->getName()<<"\n";

  // FIXME: eleminate duplicated edges.
  for (Function::iterator BB=t_F->begin(), BEnd=t_F->end();
      BB!=BEnd; ++BB) {
    BasicBlock *curBB = &*BB;
    errs()<<"*** current basic block: "<<*curBB->begin()<<"\n";
    for (BasicBlock* sucBB : successors(curBB)) {
      errs()<<"   ****** succ bb: "<<*sucBB->begin()<<"\n";
    }

     // Construct DFG nodes.
    for (BasicBlock::iterator II=curBB->begin(),
        IEnd=curBB->end(); II!=IEnd; ++II) {
      Instruction* curII = &*II;

      // Ignore this IR if it is out of the scope.
      if (shouldIgnore(curII)) {
        errs()<<*curII<<" *** ignored by pass due to that the BB is out "<<
            "of the scope (target loop)\n";
        continue;
      }
	  errs() << "Loading node " << curII << "\n";
      errs()<<*curII << "\n";
      DFGNode* dfgNode;
      if (hasNode(curII)) {
        dfgNode = getNode(curII);
      } else {
        dfgNode = new DFGNode(nodeID++, m_precisionAware, curII, curII->getOpcodeName(), getValueName(curII));
        nodes.push_back(dfgNode);

		// If there are any constant arguments to this DFG Node,
		// we need to add those to the graph --- I think this
		// model of CGRA assumes that we can just load these
		// into ALUs, which seems reasonable, but the egraphs
		// rewriter needs them.
		int numOperands = curII->getNumOperands();
		for (int i = 0; i < numOperands; i ++) {
			Value *op = curII->getOperand(i);
			if (isa<Constant>(op)) {
				errs() << "Loaded a constant argument\n";
				// It would be good to actually load this constant
				// in... as some rules no doubt will require
				// the actual value to apply.
				DFGNode *cnode = new DFGNode(nodeID ++, m_precisionAware, op, "Constant", "Constant");
				nodes.push_back(cnode);
			}
		}

      }
	  errs() << "Got DFGNode " << dfgNode->asString() << "\n";
      errs()<<" (ID: "<<dfgNode->getID()<<")\n";
    }
	errs() << "Getting terminator\n";
    Instruction* terminator = curBB->getTerminator();
	errs() << "Terminator is " << terminator << "\n";

    if (shouldIgnore(terminator))
      continue;
//    DFGNode* dfgNodeTerm = new DFGNode(nodeID++, terminator, getValueName(terminator));
    for (BasicBlock* sucBB : successors(curBB)) {
      // TODO: get the live-in nodes rather than front() and connect them
      for (BasicBlock::iterator II=sucBB->begin(),
          IEnd=sucBB->end(); II!=IEnd; ++II) {
        Instruction* inst = &*II;

        // Ignore this IR if it is out of the scope.
        if (shouldIgnore(inst))
          continue;

        if (isLiveInInst(sucBB, inst)) {
          errs()<<" check inst: "<<*inst<<"\n";

          DFGNode* dfgNode;
          if (hasNode(inst)) {
            dfgNode = getNode(inst);
          } else {
            dfgNode = new DFGNode(nodeID++, m_precisionAware, inst, inst->getOpcodeName(), getValueName(inst));
            nodes.push_back(dfgNode);
          }
    //      Instruction* first = &*(sucBB->begin());
    //      if (!getNode(inst)->isPhi()) {
    //
    //        errs()<<"!!!!!!! [avoid as a phi] construct ctrl flow: "<<*terminator<<"->"<<*inst<<"\n";
    //        continue;
    //      }
    
          errs()<<"!!!!!!! construct ctrl flow: "<<*terminator<<"->"<<*inst<<"\n";
    
          // Construct contrl flow edges.
          DFGEdge* ctrlEdge;
          if (hasCtrlEdge(getNode(terminator), dfgNode)) {
			  errs() << "Built edge for node " << dfgNode->asString() << "\n";
            ctrlEdge = getCtrlEdge(getNode(terminator), dfgNode);
          }
          else {
            ctrlEdge = new DFGEdge(ctrlEdgeID++, getNode(terminator), dfgNode, true);
			  errs() << "Built and added edge for node " << dfgNode->asString() << "\n";
            m_ctrlEdges.push_back(ctrlEdge);
          }
		  errs() << "Created edge " << ctrlEdge->asString() << "\n";

        }
      }
    }
  }

//      Instruction* inst = &(sucBB->front());
////    for (Instruction* inst: sucBB) {
//      // Ignore this IR if it is out of the scope.
//      if (shouldIgnore(inst))
//        continue;
//      DFGNode* dfgNode;
//      if (hasNode(inst)) {
//        dfgNode = getNode(inst);
//      } else {
//        dfgNode = new DFGNode(nodeID++, inst, getValueName(inst));
//        nodes.push_back(dfgNode);
//      }
////      Instruction* first = &*(sucBB->begin());
////      if (!getNode(inst)->isPhi()) {
////
////        errs()<<"!!!!!!! [avoid as a phi] construct ctrl flow: "<<*terminator<<"->"<<*inst<<"\n";
////        continue;
////      }
//
//      errs()<<"!!!!!!! construct ctrl flow: "<<*terminator<<"->"<<*inst<<"\n";
//
//      // Construct contrl flow edges.
//      DFGEdge* ctrlEdge;
//      if (hasCtrlEdge(getNode(terminator), dfgNode)) {
//        ctrlEdge = getCtrlEdge(getNode(terminator), dfgNode);
//      }
//      else {
//        ctrlEdge = new DFGEdge(ctrlEdgeID++, getNode(terminator), dfgNode);
//        m_ctrlEdges.push_back(ctrlEdge);
//      }
//    }
//  }
 
//      for (BasicBlock::iterator II=sucBB->begin(),
//          IEnd=sucBB->end(); II!=IEnd; ++II) {
//        Instruction* inst = &*II;
////      for (Instruction* inst: sucBB) {
//        // Ignore this IR if it is out of the scope.
//        if (shouldIgnore(inst))
//          continue;
//        DFGNode* dfgNode;
//        if (hasNode(inst)) {
//          dfgNode = getNode(inst);
//        } else {
//          dfgNode = new DFGNode(nodeID++, inst, getValueName(inst));
//          nodes.push_back(dfgNode);
//        }
////        Instruction* first = &*(sucBB->begin());
//        if (!getNode(inst)->isPhi()) {
//
//          errs()<<"!!!!!!! [avoid as a phi] construct ctrl flow: "<<*terminator<<"->"<<*inst<<"\n";
//          continue;
//        }
//
//        errs()<<"!!!!!!! construct ctrl flow: "<<*terminator<<"->"<<*inst<<"\n";
//
//        // Construct contrl flow edges.
//        DFGEdge* ctrlEdge;
//        if (hasCtrlEdge(getNode(terminator), dfgNode)) {
//          ctrlEdge = getCtrlEdge(getNode(terminator), dfgNode);
//        }
//        else {
//          ctrlEdge = new DFGEdge(ctrlEdgeID++, getNode(terminator), dfgNode);
//          m_ctrlEdges.push_back(ctrlEdge);
//        }
//      }
//    }
//  }

//  // Construct contrl flow forward edges.
//  for (list<DFGNode*>::iterator nodeItr=nodes.begin();
//      nodeItr!=nodes.end(); ++nodeItr) {
//    list<DFGNode*>::iterator next = nodeItr;
//    ++next;
//    if (next != nodes.end()) {
//      DFGEdge* ctrlEdge;
//      if (hasCtrlEdge(*nodeItr, *next))
//        ctrlEdge = getCtrlEdge(*nodeItr, *next);
//      else {
//        ctrlEdge = new DFGEdge(ctrlEdgeID++, *nodeItr, *next);
//        m_ctrlEdges.push_back(ctrlEdge);
//      }
//    }
//  }

  // Construct data flow edges.
  for (DFGNode* node: nodes) {
//    nodes.push_back(Node(curII, getValueName(curII)));
	  if (node->isInst()) {
		Instruction* curII = node->getInst();
		assert(node == getNode(curII));
		switch (curII->getOpcode()) {
		  // The load/store instruction is special
		  case llvm::Instruction::Load: {
			LoadInst* linst = dyn_cast<LoadInst>(curII);
			Value* loadValPtr = linst->getPointerOperand();

			// Parameter of the loop or the basic block, invisible in DFG.
			if (!hasNode(loadValPtr))
			  break;
			DFGEdge* dfgEdge;
			if (hasDFGEdge(getNode(loadValPtr), node))
			  dfgEdge = getDFGEdge(getNode(loadValPtr), node);
			else {
			  dfgEdge = new DFGEdge(dfgEdgeID++, getNode(loadValPtr), node);
			  m_DFGEdges.push_back(dfgEdge);
			}
	//        getNode(loadValPtr)->setOutEdge(dfgEdge);
	//        (*nodeItr)->setInEdge(dfgEdge);
			break;
		  }
		  case llvm::Instruction::Store: {
			StoreInst* sinst = dyn_cast<StoreInst>(curII);
			Value* storeValPtr = sinst->getPointerOperand();
			Value* storeVal = sinst->getValueOperand();
			DFGEdge* dfgEdge1;
			DFGEdge* dfgEdge2;

			// TODO: need to figure out storeVal and storeValPtr
			if (hasNode(storeVal)) {
			  if (hasDFGEdge(getNode(storeVal), node))
				dfgEdge1 = getDFGEdge(getNode(storeVal), node);
			  else {
				dfgEdge1 = new DFGEdge(dfgEdgeID++, getNode(storeVal), node);
				m_DFGEdges.push_back(dfgEdge1);
			  }
	//          getNode(storeVal)->setOutEdge(dfgEdge1);
	//          (*nodeItr)->setInEdge(dfgEdge1);
			}
			if (hasNode(storeValPtr)) {
	//          if (hasDFGEdge(*nodeItr, getNode(storeValPtr)))
			  if (hasDFGEdge(getNode(storeValPtr), node))
	//            dfgEdge2 = getDFGEdge(*nodeItr, getNode(storeValPtr));
				dfgEdge2 = getDFGEdge(getNode(storeValPtr), node);
			  else {
	//            dfgEdge2 = new DFGEdge(dfgEdgeID++, *nodeItr, getNode(storeValPtr));
				dfgEdge2 = new DFGEdge(dfgEdgeID++, getNode(storeValPtr), node);
				m_DFGEdges.push_back(dfgEdge2);
			  }
	//          getNode(storeValPtr)->setOutEdge(dfgEdge2);
	//          (*nodeItr)->setInEdge(dfgEdge2);
	//          (*nodeItr)->setOutEdge(dfgEdge2);
	//          getNode(storeValPtr)->setInEdge(dfgEdge2);
			}
			break;
		  }
		  default: {
			for (Instruction::op_iterator op = curII->op_begin(), opEnd = curII->op_end(); op != opEnd; ++op) {
			  Value* tempInst = cast<Value>(*op);
			  errs() << "Looking at inst " << *tempInst << "\n";
			  if (tempInst and !shouldIgnore(tempInst)) {
	//            if(node->isBranch()) {
	//              errs()<<"  the real branch's pred: "<<*tempInst<<"\n";
	//              int numSuccs = tempInst->getNumSuccessors();
	//            }
				DFGEdge* dfgEdge;
				if (hasNode(tempInst)) {
				  if (hasDFGEdge(getNode(tempInst), node))
					dfgEdge = getDFGEdge(getNode(tempInst), node);
				  else {
					dfgEdge = new DFGEdge(dfgEdgeID++, getNode(tempInst), node);
					m_DFGEdges.push_back(dfgEdge);
				  }
	//              getNode(tempInst)->setOutEdge(dfgEdge);
	//              (*nodeItr)->setInEdge(dfgEdge);
				}
			  } else {
				// Original Branch node will take three
				// predecessors (i.e., condi, true, false).
				if(!node->isBranch())
				  node->addConst();
			  } 
			}
	//        if(node->isBranch()) {
	//          int numSuccs = curII->getNumSuccessors();
	//          errs()<<"the succ of the branch: "<<*curII<<"; ("<<numSuccs<<")\n";
	//          for(int i=0; i<numSuccs; ++i) {
	//            BasicBlock* bb
	//          }
	//        }
			break;
		  }
		}
	  } else {
		  // Node is a constant node
		  // what to do?
		  errs() << "Constant node";
	  }
  }
  connectDFGNodes();

  calculateCycles();

  // The mapping algorithm works on the DFG that is ordered in ASAP.
  // reorderInASAP();
  // The mapping algorithm works on the DFG that is ordered in ALAP.
  // reorderInALAP();
  // The mapping algorithm works on the DFG that is ordered along with the longest path.
  reorderInLongest();
  
}


bool DFG::isMinimumAndHasNotBeenVisited(set<DFGNode*>* t_visited, map<DFGNode*, int>* t_map, DFGNode* t_node) {
  if (t_visited->find(t_node) != t_visited->end()) {
    return false;
  }
  for (DFGNode* e_node: nodes) {
    if (e_node != t_node and t_visited->find(e_node) == t_visited->end() and (*t_map)[e_node] < (*t_map)[t_node]) {
      return false;
    }
  }
  return true;
}

// Reorder the DFG nodes based on the longest path.
void DFG::reorderInLongest() {
  list<DFGNode*>* longestPath = new list<DFGNode*>();
  list<DFGNode*>* currentPath = new list<DFGNode*>();
  set<DFGNode*>* visited = new set<DFGNode*>();
  map<DFGNode*, int> indegree;
  for (DFGNode* node: nodes) {
    indegree[node] = node->getPredNodes()->size();
    currentPath->clear();
    visited->clear();
    reorderDFS(visited, longestPath, currentPath, node);
  }

  visited->clear();
  int level = 0;
  for (DFGNode* node: *longestPath) {
    node->setLevel(level);
    visited->insert(node);
    //cout<<"check longest path node: "<<node->getID()<<endl;
    for (DFGNode* succNode: *(node->getSuccNodes())) {
      indegree[succNode] -= 1;
    }
    level += 1;
  }
  int maxLevel = level;

  while (visited->size() < nodes.size()) {
    for (DFGNode* node: nodes) {
      if (isMinimumAndHasNotBeenVisited(visited, &indegree, node)) {
        level = 0;
        for (DFGNode* preNode: *(node->getPredNodes())) {
          if (level < preNode->getLevel() + 1) {
            level = preNode->getLevel() + 1;
          }
        }
        node->setLevel(level);
        visited->insert(node);
        for (DFGNode* succNode: *(node->getSuccNodes())) {
          indegree[succNode] -= 1;
        }
      }
    }
  }

  list<DFGNode*> tempNodes;
  for (int l=0; l<maxLevel+1; ++l) {
    for (DFGNode* node: nodes) {
      if (node->getLevel() == l) {
        tempNodes.push_back(node);
      }
    }
  }

  nodes.clear();
  errs()<<"[reorder DFG along with the longest path]\n";
  for (DFGNode* node: tempNodes) {
    nodes.push_back(node);
    errs()<<"("<<node->getID()<<") "<<(node->asString())<<", level: "<<node->getLevel()<<"\n";
  }

}

void DFG::reorderDFS(set<DFGNode*>* t_visited, list<DFGNode*>* t_targetPath,
                     list<DFGNode*>* t_curPath, DFGNode* targetDFGNode) {

  t_visited->insert(targetDFGNode);
  t_curPath->push_back(targetDFGNode);

  // Update target longest path if current one is longer.
  if (t_curPath->size() > t_targetPath->size()) {
    t_targetPath->clear();
    for (DFGNode* node: *t_curPath) {
      t_targetPath->push_back(node);
    }
  }

  for (DFGNode* succNode: *(targetDFGNode->getSuccNodes())) {
    if (t_visited->find(succNode) == t_visited->end()) { // not visited yet
      reorderDFS(t_visited, t_targetPath, t_curPath, succNode);
      t_visited->erase(succNode);
      t_curPath->pop_back();
    }
  }

}

void DFG::initExecLatency(map<string, int>* t_execLatency) {
  set<string> targetOpt;
  for (map<string, int>::iterator iter=t_execLatency->begin();
      iter!=t_execLatency->end(); ++iter) {
    targetOpt.insert(iter->first);
  }
  for (DFGNode* node: nodes) {
	  cout << "Looking at node " << node->getOpcodeName() << "\n";
    if (t_execLatency->find(node->getOpcodeName()) != t_execLatency->end()) {
      string opcodeName = node->getOpcodeName();
      node->setExecLatency((*t_execLatency)[opcodeName]);
      targetOpt.erase(opcodeName);
    }
  }
  if (!targetOpt.empty()) {
    cout<<"\033[0;31mPlease check the operations targeting multi-cycle execution in <param.json>:\"\033[0m";
    for (set<string>::iterator it = targetOpt.begin(); it != targetOpt.end(); ++it) {
      cout<<" "<<*it<<" "; // Note the "*" here
    }
    cout<<"\033[0;31m\".\033[0m"<<endl;
  }
}

void DFG::initPipelinedOpt(list<string>* t_pipelinedOpt) {
  set<string> targetOpt;
  for (string opt: *t_pipelinedOpt) {
    targetOpt.insert(opt);
  }
  for (DFGNode* node: nodes) {
    list<string>::iterator it;
    it = find(t_pipelinedOpt->begin(), t_pipelinedOpt->end(), node->getOpcodeName());
    if(it != t_pipelinedOpt->end()) {
      string opcodeName = node->getOpcodeName();
      node->setPipelinable();
      targetOpt.erase(opcodeName);
    }
  }
  if (!targetOpt.empty()) {
    cout<<"\033[0;31mPlease check the pipelinable operations in <param.json>:\"\033[0m";
    for (set<string>::iterator it = targetOpt.begin(); it != targetOpt.end(); ++it) {
      cout<<" "<<*it<<" "; // Note the "*" here
    }
    cout<<"\033[0;31m\".\033[0m"<<endl;
  }
}

bool DFG::isLiveInInst(BasicBlock* t_bb, Instruction* t_inst) {
  if (t_inst == &(t_bb->front())) {
    errs()<<"ctrl to: "<<*t_inst<<"; front: "<<(t_bb->front())<<"; ";
    return true;
  }
  for (Instruction::op_iterator op = t_inst->op_begin(), opEnd = t_inst->op_end(); op != opEnd; ++op) {
    Instruction* tempInst = dyn_cast<Instruction>(*op);
    if (tempInst and !containsInst(t_bb, tempInst)) {
      errs()<<"ctrl to: "<<*t_inst<<"; containsInst(t_bb, tempInst): "<<containsInst(t_bb, tempInst)<<"; ";
      return true;
    }
  }

  // The first (lower ID) IR with only in-block dependency is also treated as live-in.
  for (Instruction::op_iterator op = t_inst->op_begin(), opEnd = t_inst->op_end(); op != opEnd; ++op) {
    Instruction* tempInst = dyn_cast<Instruction>(*op);
    if (tempInst and getInstID(t_bb, t_inst) > getInstID(t_bb, tempInst)) {
      return false;
    }
  }

  errs()<<"ctrl to: "<<*t_inst<<"; ";
  return true;
}

bool DFG::containsInst(BasicBlock* t_bb, Value* t_inst) {

  for (BasicBlock::iterator II=t_bb->begin(),
       IEnd=t_bb->end(); II!=IEnd; ++II) {
    Instruction* inst = &*II;
    if ((inst) == (t_inst)) {
      return true;
    }
  }
  return false;
}

int DFG::getInstID(BasicBlock* t_bb, Value* t_inst) {

  int id = 0;
  for (BasicBlock::iterator II=t_bb->begin(),
       IEnd=t_bb->end(); II!=IEnd; ++II) {
    Instruction* inst = &*II;
    if ((inst) == (t_inst)) {
      return id;
    }
    id += 1;
  }
  // This never gonna happen.
  assert(false);
  return -1;
}

void DFG::addEdge(DFGEdge *edge) {
	m_DFGEdges.push_back(edge);
}

void DFG::addNode(DFGNode *node) {
	nodes.push_back(node);
}

void DFG::connectDFGNodes() {
  for (DFGNode* node: nodes)
    node->cutEdges();

  // Incorporate ctrl flow into data flow.
  if (!m_CDFGFused) {
    for (DFGEdge* edge: m_ctrlEdges) {
      m_DFGEdges.push_back(edge);
    }
    m_CDFGFused = true;
  }

  for (DFGEdge* edge: m_DFGEdges) {
    DFGNode* left = edge->getSrc();
    DFGNode* right = edge->getDst();
    left->setOutEdge(edge);
    right->setInEdge(edge);
  }

//  for (DFGEdge* edge: m_ctrlEdges) {
//    DFGNode* left = edge->getSrc();
//    DFGNode* right = edge->getDst();
////    errs()<<"... connectDFGNodes() for inst (left): "<<*(left->getInst())<<", (right): "<<*(right->getInst())<<"\n";
//    left->setOutEdge(edge);
//    right->setInEdge(edge);
//  }

}

void DFG::generateJSON() {
  ofstream jsonFile;
  jsonFile.open("dfg.json");
  jsonFile<<"[\n";
  int node_index = 0;
  int node_size = nodes.size();
  for (DFGNode* node: nodes) {
    jsonFile<<"  {\n";
    jsonFile<<"    \"fu\"         : \""<<node->getFuType()<<"\",\n";
    jsonFile<<"    \"id\"         : "<<node->getID()<<",\n";
    jsonFile<<"    \"org_opt\"    : \""<<node->getOpcodeName()<<"\",\n";
    jsonFile<<"    \"JSON_opt\"   : \""<<node->getJSONOpt()<<"\",\n";
    jsonFile<<"    \"in_const\"   : [";
    int const_size = node->getNumConst();
    for (int const_index=0; const_index < const_size; ++const_index) {
      jsonFile<<const_index;
      if (const_index < const_size - 1)
        jsonFile<<",";
    }
    jsonFile<<"],\n";
    jsonFile<<"    \"pre\"         : [";
    int in_size = node->getPredNodes()->size();
    int in_index = 0;
    for (DFGNode* predNode: *(node->getPredNodes())) {
      jsonFile<<predNode->getID();
      in_index += 1;
      if (in_index < in_size)
        jsonFile<<",";
    }
    jsonFile<<"],\n";
    jsonFile<<"    \"succ\"       : [[";
    int out_size = node->getSuccNodes()->size();
    int out_index = 0;
    for (DFGNode* succNode: *(node->getSuccNodes())) {
      jsonFile<<succNode->getID();
      out_index += 1;
      if (out_index < out_size)
        jsonFile<<",";
    }
    jsonFile<<"]]\n";
    node_index += 1;
    if (node_index < node_size)
      jsonFile<<"  },\n";
    else
      jsonFile<<"  }\n";
  }
  jsonFile<<"]\n";
}

void DFG::generateDot(Function *t_F, bool t_isTrimmedDemo) {

  error_code error;
//  sys::fs::OpenFlags F_Excl;
  string func_name = t_F->getName().str();
  string file_name = func_name + ".dot";
  StringRef fileName(file_name);
  raw_fd_ostream file(fileName, error, sys::fs::OF_None);

  file << "digraph \"DFG for'" + t_F->getName() + "\' function\" {\n";

  //Dump DFG nodes.
  for (DFGNode* node: nodes) {
//    if (dyn_cast<Instruction>((*node)->getInst())) {
    if (t_isTrimmedDemo) {
      file << "\tNode" << node->getID() << node->getOpcodeName() << "[shape=record, label=\"" << "(" << node->getID() << ") " << node->getOpcodeName() << "\"];\n";
    } else {
      file << "\tNode" << node->getInst() << "[shape=record, label=\"" <<
          changeIns2Str(node->getInst()) << "\"];\n";
    }
  }
  /*
    if(dyn_cast<Instruction>(node->first))
      file << "\tNode" << node->first << "[shape=record, label=\"" << *(node->first) << "\"];\n";
      file << "\tNode" << (*node)->getInst() << "[shape=record, label=\"" << ((*node)->getID()) << "\"];\n";
    else {
      file << "\tNode" << (*node)->getInst() << "[shape=record, label=\"" << (*node)->getStringRef() << "\"];\n";
    }
            file << "\tNode" << node->first << "[shape=record, label=\"" << node->second << "\"];\n";
  */


  // Dump control flow.
  file << "edge [color=blue]" << "\n";
  for (DFGEdge* edge: m_ctrlEdges) {
    // Distinguish data and control flows. Don't show the ctrl flows that are optimzied out from the data flow optimization.
    if (find(m_DFGEdges.begin(), m_DFGEdges.end(), edge) != m_DFGEdges.end()) {
      if (t_isTrimmedDemo) {
        file << "\tNode" << edge->getSrc()->getID() << edge->getSrc()->getOpcodeName() << " -> Node" << edge->getDst()->getID() << edge->getDst()->getOpcodeName() << "\n";
      } else {
        file << "\tNode" << edge->getSrc()->getInst() << " -> Node" << edge->getDst()->getInst() << "\n";
      }
    }
  }

  // Dump data flow.
  file << "edge [color=red]" << "\n";
  for (DFGEdge* edge: m_DFGEdges) {
    // Distinguish data and control flows. Make ctrl flow invisible.
    if (find(m_ctrlEdges.begin(), m_ctrlEdges.end(), edge) == m_ctrlEdges.end()) {
      if (t_isTrimmedDemo) {
        file << "\tNode" << edge->getSrc()->getID() << edge->getSrc()->getOpcodeName() << " -> Node" << edge->getDst()->getID() << edge->getDst()->getOpcodeName() << "\n";
      } else {
        file << "\tNode" << edge->getSrc()->getInst() << " -> Node" << edge->getDst()->getInst() << "\n";
      }
    }
  }
//  errs() << "Write data flow done.\n";
  file << "}\n";
  file.close();

}

void DFG::DFS_on_DFG(DFGNode* t_head, DFGNode* t_current,
    list<DFGNode*>* t_visitedNodes, list<DFGEdge*>* t_erasedEdges,
    list<DFGEdge*>* t_currentCycle, list<list<DFGEdge*>*>* t_cycles) {
  for (DFGEdge* edge: m_DFGEdges) {
    if (find(t_erasedEdges->begin(), t_erasedEdges->end(), edge) != t_erasedEdges->end())
      continue;
    // check whether the IR is equal
    if (edge->getSrc() == t_current) {
      // skip the visited nodes/edges:
      if (find(t_currentCycle->begin(), t_currentCycle->end(), edge) != t_currentCycle->end()) {
        continue;
      }
      t_currentCycle->push_back(edge);

//      errs() << ".. add current cycle edge: {" << *edge->getSrc()->getInst() << "  } -> {"<< *edge->getDst()->getInst() << "  } ("<<edge->getSrc()->getID()<<" -> "<<edge->getDst()->getID()<<")\n";
      if (edge->getDst() == t_head) {
        errs() << "==================================\n";
        errs() << "[detected one cycle] head: "<<*(t_head->getInst())<<"\n";
        list<DFGEdge*>* temp_cycle = new list<DFGEdge*>();
        for (DFGEdge* currentEdge: *t_currentCycle) {
          temp_cycle->push_back(currentEdge);
          // break the cycle to avoid future repeated detection
          errs() << "cycle edge: {" << *(currentEdge)->getSrc()->getInst() << "  } -> {"<< *(currentEdge)->getDst()->getInst() << "  } ("<<currentEdge->getSrc()->getID()<<" -> "<<currentEdge->getDst()->getID()<<")\n";
        }
        t_erasedEdges->push_back(edge);
        t_cycles->push_back(temp_cycle);
        t_currentCycle->remove(edge);
      } else {
        if (find(t_visitedNodes->begin(), t_visitedNodes->end(), edge->getDst()) == t_visitedNodes->end()) {
          t_visitedNodes->push_back(edge->getDst());
          // Only continue when the path size is less than the node count.
          if (t_currentCycle->size() <= nodes.size()) {
            DFS_on_DFG(t_head, edge->getDst(), t_visitedNodes, t_erasedEdges, t_currentCycle, t_cycles);
          }
        } else {
          t_currentCycle->remove(edge);
        }
      }
    }
  }
  if (t_currentCycle->size()!=0) {
    t_currentCycle->pop_back();
  }
}

list<list<DFGEdge*>*>* DFG::calculateCycles() {
  list<list<DFGEdge*>*>* cycleLists = new list<list<DFGEdge*>*>();
  list<DFGEdge*>* currentCycle = new list<DFGEdge*>();
  list<DFGNode*>* visitedNodes = new list<DFGNode*>();
  list<DFGEdge*>* erasedEdges = new list<DFGEdge*>();
  cycleLists->clear();
  for (DFGNode* node: nodes) {
    currentCycle->clear();
    visitedNodes->clear();
    visitedNodes->push_back(node);
    DFS_on_DFG(node, node, visitedNodes, erasedEdges, currentCycle, cycleLists);
  }
  int cycleID = 0;
  m_cycleNodeLists->clear();
  for (list<DFGEdge*>* cycle: *cycleLists) {
    list<DFGNode*>* nodeCycle = new list<DFGNode*>();
    for (DFGEdge* edge: *cycle) {
      edge->getDst()->setCritical();
      edge->getDst()->addCycleID(cycleID);
      nodeCycle->push_back(edge->getDst());
    }
    m_cycleNodeLists->push_back(nodeCycle);
    cycleID += 1;
  }
  return cycleLists;
}

list<list<DFGNode*>*>* DFG::getCycleLists() {
  return m_cycleNodeLists;
}

void DFG::showOpcodeDistribution() {

  map<string, int> opcodeMap;
  for (DFGNode* node: nodes) {
    opcodeMap[node->getOpcodeName()] += 1;
  }
  for (map<string, int>::iterator opcodeItr=opcodeMap.begin();
      opcodeItr!=opcodeMap.end(); ++opcodeItr) {
    errs() << (*opcodeItr).first << " : " << (*opcodeItr).second << "\n";
  }
  errs() << "DFG node count: "<<nodes.size()<<"; DFG edge count: "<<m_DFGEdges.size()<<"\n";
}

int DFG::getID(DFGNode* t_node) {
  int index = 0;
  return t_node->getID();
}

DFGNode* DFG::getNode(Value* t_value) {
  for (DFGNode* node: nodes) {
    if (node->getValue() == t_value) {
      return node;
    }
  }
  assert("ERROR cannot find the corresponding DFG node.");
  return NULL;
}

bool DFG::hasNode(Value* t_value) {
  for (DFGNode* node: nodes) {
    if (node->getValue() == t_value) {
      return true;
    }
  }
  return false;
}

DFGEdge* DFG::getCtrlEdge(DFGNode* t_src, DFGNode* t_dst) {
  for (DFGEdge* edge: m_ctrlEdges) {
    if (edge->getSrc() == t_src and
        edge->getDst() == t_dst) {
      return edge;
    }
  }
  assert("ERROR cannot find the corresponding Ctrl edge.");
  return NULL;
}

bool DFG::hasCtrlEdge(DFGNode* t_src, DFGNode* t_dst) {
  for (DFGEdge* edge: m_ctrlEdges) {
    if (edge->getSrc() == t_src and
        edge->getDst() == t_dst) {
      return true;
    }
  }
  return false;
}

DFGEdge* DFG::getDFGEdge(DFGNode* t_src, DFGNode* t_dst) {
  for (DFGEdge* edge: m_DFGEdges) {
    if (edge->getSrc() == t_src and
        edge->getDst() == t_dst) {
      return edge;
    }

  }
  assert("ERROR cannot find the corresponding DFG edge.");
  return NULL;
}

void DFG::replaceDFGEdge(DFGNode* t_old_src, DFGNode* t_old_dst,
                         DFGNode* t_new_src, DFGNode* t_new_dst) {
  DFGEdge* target = NULL;
  errs()<<"replace edge: [delete] "<<t_old_src->getID()<<"->"<<t_old_dst->getID()<<" [new] "<<t_new_src->getID()<<"->"<<t_new_dst->getID()<<"\n";
  for (DFGEdge* edge: m_DFGEdges) {
    if (edge->getSrc() == t_old_src and
        edge->getDst() == t_old_dst) {
      target = edge;
      break;
    }
  }
  if (target == NULL)
    assert("ERROR cannot find the corresponding DFG edge.");
  m_DFGEdges.remove(target);
  DFGEdge* newEdge = new DFGEdge(target->getID(), t_new_src, t_new_dst);
  m_DFGEdges.push_back(newEdge);
}

void DFG::deleteDFGEdge(DFGNode* t_src, DFGNode* t_dst) {
  if (!hasDFGEdge(t_src, t_dst)) return;
  m_DFGEdges.remove(getDFGEdge(t_src, t_dst));
}

bool DFG::hasDFGEdge(DFGNode* t_src, DFGNode* t_dst) {
  for (DFGEdge* edge: m_DFGEdges) {
    if (edge->getSrc() == t_src and
        edge->getDst() == t_dst) {
      return true;
    }
  }
  return false;
}

string DFG::changeIns2Str(Value* t_ins) {
  string temp_str;
  raw_string_ostream os(temp_str);
  t_ins->print(os);
  return os.str();
}

//get value's name or inst's content
StringRef DFG::getValueName(Value* t_value) {
  string temp_result = "val";
  if (t_value->getName().empty()) {
    temp_result += to_string(m_num);
    m_num++;
  }
  else {
    temp_result = t_value->getName().str();
  }
  StringRef result(temp_result);
//  errs() << "" << result;
  return result;
}

int DFG::getNodeCount() {
  return nodes.size();
}

void DFG::tuneForBitcast() {
  list<DFGNode*> unnecessaryDFGNodes;
  list<DFGEdge*> replaceDFGEdges;
  list<DFGEdge*> newDFGEdges;
  for (DFGNode* dfgNode: nodes) {
    if (dfgNode->isBitcast()) {
      unnecessaryDFGNodes.push_back(dfgNode);
      list<DFGNode*>* predNodes = dfgNode->getPredNodes();
      for (DFGNode* predNode: *predNodes) {
        replaceDFGEdges.push_back(getDFGEdge(predNode, dfgNode));
      }
      list<DFGNode*>* succNodes = dfgNode->getSuccNodes();
      for (DFGNode* succNode: *succNodes) {
        replaceDFGEdges.push_back(getDFGEdge(dfgNode, succNode));
        for (DFGNode* predNode: *predNodes) {
          DFGEdge* bypassDFGEdge = new DFGEdge(predNode->getID(),
              predNode, succNode);
          newDFGEdges.push_back(bypassDFGEdge);
        }
      }
    }
  }

  for (DFGNode* dfgNode: unnecessaryDFGNodes)
    nodes.remove(dfgNode);

  for (DFGEdge* dfgEdge: replaceDFGEdges)
    m_DFGEdges.remove(dfgEdge);

  for (DFGEdge* dfgEdge: newDFGEdges)
    m_DFGEdges.push_back(dfgEdge);

  connectDFGNodes();
}

// Note that this is not a member function of the class, but just a helper (static) function.
void splitEdge(DFGEdge *r, int *nodeCounter, list<DFGNode*> *nodesToAdd, list<DFGEdge *> *edgesToAdd) {
	errs() << "Splitting over edge " << r->asString() << "\n";
	// Add in the replacement edge --- need a pair of un-connected dummy nodes.
	int joinName = *nodeCounter;
	DFGNode *tempSource = new DFGNode(*nodeCounter, false, nullptr, "DummySource" + std::to_string(joinName), "");
	(*nodeCounter) ++;
	DFGNode *tempTarget = new DFGNode(*nodeCounter, false, nullptr, "DummyTarget" + std::to_string(joinName), "");
	(*nodeCounter) ++;

	errs() << "Created nodes " << *nodeCounter << "\n";

	// Now, create the edges
	// I don't think these have to have unique IDs --- we need
	// to make sure we dont' skip over nodes --- the rust
	// converter assumes those are not skipping around.
	DFGEdge *first_edge = new DFGEdge(1, tempSource, r->getDst());
	DFGEdge *other_edge = new DFGEdge(1, r->getSrc(), tempTarget);

	errs() << "Created edges \n";
	errs() << "Edges are " << first_edge->asString();
	errs() << " And " << other_edge->asString();
	errs() << "\n";

	// I think these are the right way around --- need to keep
	// the edges in the right order.
	r->getDst()->getInEdges()->push_back(first_edge);
	tempSource->getOutEdges()->push_back(first_edge);

	errs() << "Set edges source\n";
	errs() << "Before, have " << r->getSrc()->getOutEdges()->size() << " edges\n";

	r->getSrc()->getOutEdges()->push_back(other_edge);
	tempTarget->getInEdges()->push_back(other_edge);

	errs() << "After, have " << r->getSrc()->getOutEdges()->size() << " edges\n";
	errs() << "Set edges target\n";

	edgesToAdd->push_back(first_edge);
	edgesToAdd->push_back(other_edge);

	nodesToAdd->push_back(tempSource);
	nodesToAdd->push_back(tempTarget);

	errs() << "setup the to add stacks";
}

int DFG::getMaxNodeNumber() {
	int max_node = -1;
	for (DFGNode *node : nodes) {
		int id = node->getID();
		if (max_node < id) {
			max_node = id;
		}
	}

	return max_node;
}

// Take the cycles that were broken in breakCycles
// and rejoin them --- to do this, we do a search for
// the nodes that have names DummyTargetX and DummySourceX
// and then create edges across those gaps.
void DFG::rejoinCycles() {
	// Keep the source nodes ina  list so we can iterate
	vector<DFGNode*> sourceNodes;
	vector<int> sourceNodeNumbers;
	// Keep the target nodes in a map so we can get them
	// easily.
	map<int, DFGNode*> targetNodes;

	errs() << "Starting to join cycles in the graph.\n";
	for (DFGNode *node : nodes) {
		//
		errs() << "Node: " << node->asString() << "\n";
		// Check the node operation name:
		std::string opname = node->getOpcodeName();

		if (opname.find("Dummy") != std::string::npos) {
			// Figure out if this is a source or a target:
			if (opname.find("Source") != std::string::npos) {
				// This is a source, get the numebr in the name
				int number = std::stoi(opname.substr(11));

				sourceNodeNumbers.push_back(number);
				sourceNodes.push_back(node);
			} else {
				// This is a "Target" node.
				int number = std::stoi(opname.substr(11));

				targetNodes[number] = node;
			}
		}
	}

	// Now, go through these nodes.
	// We need to (a) create a new edge between the pred nodes
	// of the dummy source and the succ nodes of the dummy target
	// and (b) delete the dummy nodes and edges from the graph.

	// Part (a)
	// Keep track of edges and nodes to delete.
	list<DFGNode *> nodesToDelete;
	list<DFGEdge *> edgesToDelete;

	for (int i = 0; i < sourceNodes.size(); i ++) {
		DFGNode *sourceNode = sourceNodes[i];
		int nodeNumber = sourceNodeNumbers[i];
		DFGNode *targetNode = targetNodes.at(nodeNumber);

		// TODO --- do we need to preserve order? (Answer is yes if we want to really run the code,
		// but we can get correct compilation stats w/out preserving
		// the order)

		// Get the inserted edges -- note by construction each
		// of these is going to have a single edge.
		DFGEdge *sourceEdge = (*sourceNode->getInEdges()).front();
		DFGEdge *destEdge = (*targetNode->getOutEdges()).front();
		errs() << "Source node is " << sourceNode->asString();
		errs() << "Number of in edges to the source node is " << sourceNode->getInEdges()->size() << "\n";
		errs() << "Target node is " << targetNode->asString();
		errs() << "Number of out edges to the target node is " << targetNode->getOutEdges()->size() << "\n";


		// New edge: (IIRC the edge IDs don't matter?)
		DFGEdge *newEdge = new DFGEdge(0, sourceEdge->getSrc(), destEdge->getDst());

		// Put this edge into the nodes:
		sourceNode->addOutEdge(newEdge);
		targetNode->addInEdge(newEdge);

		// Now, delete the nodes:
		nodesToDelete.push_back(sourceNode);
		nodesToDelete.push_back(targetNode);
		// And the edges they are attached to
		edgesToDelete.push_back(sourceEdge);
		edgesToDelete.push_back(destEdge);
	}

	// Part (b)
	// Now, remove all the nodes from the nodes list:
	removeNodes(&nodesToDelete);
	// remove all nodes from the edges list:
	for (DFGEdge *edge : edgesToDelete) {
		m_DFGEdges.remove(edge);

		// Need to clear the edge from the nodes it was
		// attached to also:
		DFGNode *src = edge->getSrc();
		src->removeOutEdge(edge);
		DFGNode *dst = edge->getDst();
		dst->removeInEdge(edge);
	}
}

void DFG::breakCycles() {
	// This introduces dummy nodes -- to keep track of them
	// We need to add them to the DFG when we are done.
	list<DFGEdge *> edgesToAdd;
	list<DFGNode *> nodesToAdd;

	// This has to be done out here because the node numbers
	// are not updated until the end of this loop.
	int dummyNodeCounter = getMaxNodeNumber() + 1;
	// Break cycles to pass to the egraphs rewriter.
	// To break the cycles, we introduce dummy nodes --- the dummy nodes
	// can be rejoined with the joinCycles operation.
	for (DFGNode * dfgNode : nodes) {
		// TODO --- I think it may be possible to do this by
		// only breaking the control flow edges?
		// The cycles here seem to be centered around a 'br' node.
		// So, we just go through and find any edges that go into a 'br' node,
		// and any edges that come out of a 'br' node and break those.
		// We also check that there is only one br node --- not 100% sure how
		// to pick the right one if there is more than one right now.  Can cross
		// that bridge if required.

		list<DFGEdge *> inEdgesToRemove;
		list<DFGEdge *> tempEdges;
		list<DFGNode *> tempNodes;

		DFGNode *brnode = nullptr;
		for (DFGEdge *edge : *dfgNode->getInEdges()) {
			DFGNode *srcnode = edge->getSrc();
			DFGNode *dstnode = edge->getDst();
			if (edge->isCtrlEdge()) {
				inEdgesToRemove.push_back(edge);
			} else if (dstnode->isPhi()) {
				inEdgesToRemove.push_back(edge);
			} else if (srcnode->isBr()) {
				inEdgesToRemove.push_back(edge);

				if (brnode) {
					// TODO -- more intelligent logic to figure out which of these is the loop br.
					if (brnode != srcnode) {
						// We choose the last one?
						cout << "Expected a different brnode!\n";
						cout << "Brnode is " << brnode->asString() << "\n";
						cout << "Dstnode is "<< srcnode->asString() << "\n";
						brnode = srcnode;
						inEdgesToRemove.clear();
						inEdgesToRemove.push_back(edge);
						// assert(0);
					}
				} else {
					brnode = srcnode;
				}
			}
		}

		list<DFGEdge *> outEdgesToRemove;
		for (DFGEdge *edge : *dfgNode->getOutEdges()) {
			DFGNode *dstnode = edge->getDst();
			DFGNode *srcnode = edge->getSrc();
			// Also remove all incoming edges to each phi node --- these need to be added back in before scheduling.
			if (edge->isCtrlEdge()) {
				outEdgesToRemove.push_back(edge);
			} else if (srcnode->isPhi()) {
				outEdgesToRemove.push_back(edge);
			} else if (dstnode->isBr()) {
				outEdgesToRemove.push_back(edge);

				if (brnode) {
					if (brnode != dstnode) {
						cout << "Expected a different brnode!\n";
						cout << "Brnode is " << brnode->asString() << "\n";
						cout << "Dstnode is "<< dstnode->asString() << "\n";
						// We use the last one --- assume it's a looping BR
					}
				} else {
					brnode = dstnode;
				}
			}
		}

		cout << "Before removing, have " << dfgNode->getInEdges()->size() << "edges in\n";
		cout << "Before removing, have " << dfgNode->getOutEdges()->size() << "edges out\n";
		// Clear the edges:
		for (DFGEdge * r: inEdgesToRemove) {
			cout << "Removing edge " << r->asString() << "\n";
			dfgNode->getInEdges()->remove(r);

			splitEdge(r, &dummyNodeCounter, &nodesToAdd, &edgesToAdd);
		}

		for (DFGEdge * r: outEdgesToRemove) {
			cout << "Removing edge  " << r->asString() << "\n";
			dfgNode->getOutEdges()->remove(r);

			splitEdge(r, &dummyNodeCounter, &nodesToAdd, &edgesToAdd);
		}

		cout << "After removing, have " << dfgNode->getInEdges()->size() << "edges in\n";
		cout << "After removing, have " << dfgNode->getOutEdges()->size() << "edges out\n";
		// Clear the cahced info for this node.
		dfgNode->clearCachedNodes();
	}

	// Now, we need to add the dummy nodes and edges to the DFG.
	// Needs to be done outside the node iteration.
	for (DFGNode *node : nodesToAdd) {
    assert (node->getInEdges()->size() > 0 || node->getOutEdges()->size() > 0);
		addNode(node);
	}

	for (DFGEdge *edge : edgesToAdd) {
		addEdge(edge);
	}
}

void DFG::tuneForLoad() {
  list<DFGNode*> unnecessaryDFGNodes;
  list<DFGEdge*> removeDFGEdges;
  list<DFGEdge*> newDFGEdges;
  for (DFGNode* dfgNode: nodes) {
    if (dfgNode->isGetptr()) {
      list<DFGNode*>* succNodes = dfgNode->getSuccNodes();
      DFGNode* firstLoadNode = NULL;
      for (DFGNode* succNode: *succNodes) {
        if (firstLoadNode == NULL and succNode->isLoad()) {
          firstLoadNode = succNode;
        } else if (firstLoadNode != NULL and succNode->isLoad()) {
          unnecessaryDFGNodes.push_back(succNode);
          removeDFGEdges.push_back(getDFGEdge(dfgNode, succNode));
          for (DFGNode* succOfLoad: *(succNode->getSuccNodes())) {
            DFGEdge* removeEdge = getDFGEdge(succNode, succOfLoad);
            removeDFGEdges.push_back(removeEdge);
            DFGEdge* newDFGEdge = new DFGEdge(removeEdge->getID(),
                firstLoadNode, succOfLoad);
            newDFGEdges.push_back(newDFGEdge);
          }
        }
      }
    }
  }

  for (DFGNode* dfgNode: unnecessaryDFGNodes)
    nodes.remove(dfgNode);

  for (DFGEdge* dfgEdge: removeDFGEdges)
    m_DFGEdges.remove(dfgEdge);

  for (DFGEdge* dfgEdge: newDFGEdges)
    m_DFGEdges.push_back(dfgEdge);

  connectDFGNodes();
}

// This is necessary to handle the control flow.
// Each one would have their own implementation about control
// flow handling. We simply connect 'br' to the entry ('phi')
// of the corresponding basic blocks (w/o including additional
// DFG nodes).
void DFG::tuneForBranch() {
  list<DFGNode*> processedDFGBrNodes;
  list<DFGEdge*> replaceDFGEdges;
  list<DFGEdge*> newBrDFGEdges;
  int newDFGEdgeID = m_DFGEdges.size();
  for (DFGEdge* dfgEdge: m_ctrlEdges) {
    DFGNode* left = dfgEdge->getSrc();
    DFGNode* right = dfgEdge->getDst();
    assert(left->isBranch());
    assert(right->isPhi());
    if (find(processedDFGBrNodes.begin(), processedDFGBrNodes.end(), left) ==
        processedDFGBrNodes.end()) {
      processedDFGBrNodes.push_back(left);
    } else {
      DFGNode* newDFGBrNode = new DFGNode(nodes.size(), m_precisionAware, left->getInst(), left->getOpcodeName(),
          getValueName(left->getInst()));
      for (DFGNode* predDFGNode: *(left->getPredNodes())) {
        DFGEdge* newDFGBrEdge = new DFGEdge(newDFGEdgeID++,
            predDFGNode, newDFGBrNode);
        m_DFGEdges.push_back(newDFGBrEdge);
      }
      nodes.push_back(newDFGBrNode);
      left = newDFGBrNode;
    }
    list<DFGNode*>* predNodes = right->getPredNodes();
    for (DFGNode* predNode: *predNodes) {
      DFGEdge* replaceDFGEdge = getDFGEdge(predNode, right);
      DFGEdge* brDataDFGEdge = new DFGEdge(replaceDFGEdge->getID(), predNode, left);
      DFGEdge* brCtrlDFGEdge = new DFGEdge(newDFGEdgeID++, left, right);
      // FIXME: Only consider one predecessor for 'phi' node for now.
      //        Need to care about true/false and make proper connection.
      replaceDFGEdges.push_back(replaceDFGEdge);
      newBrDFGEdges.push_back(brDataDFGEdge);
      newBrDFGEdges.push_back(brCtrlDFGEdge);
      break;
    }
  }
  for (DFGEdge* dfgEdge: replaceDFGEdges) {
    m_DFGEdges.remove(dfgEdge);
  }
  for (DFGEdge* dfgEdge: newBrDFGEdges) {
    m_DFGEdges.push_back(dfgEdge);
  }

  connectDFGNodes();
//    DFGEdge* brCtrlDFGEdge = new DFGEdge(m_DFGEdges.size(), left, right);
//    DFGEdge* replaceDFGEdge;
//    for (list<DFGNode*>::iterator predNodeItr=predNodes->begin();
//        predNodeItr!=predNodes->end(); ++predNodeItr) {
//      DFGNode* predNode = *predNodeItr;
//      list<DFGNode*>* visitedNodes = new list<DFGNode*>();
//      // Found one predNode is one the same control/data path as the 'br'.
//      if (searchDFS(left, predNode, visitedNodes)) {
//        replaceDFGEdge = getDFGEdge(predNode, right);
//        DFGEdge* brDataDFGEdge = new DFGEdge(replaceDFGEdge->getID(), predNode, left);
//        m_DFGEdges.remove(replaceDFGEdge);
//        m_DFGEdges.push_back(brDataDFGEdge);
//        break;
//      }
//    }
//    m_DFGEdges.push_back(brCtrlDFGEdge);
//  }
}

void DFG::trimForStandalone() {
  list<DFGNode*> removeNodes;
  for (DFGNode* dfgNode: nodes)
    if (dfgNode->getPredNodes()->size() == 0 and
        dfgNode->getSuccNodes()->size() == 0)
      removeNodes.push_back(dfgNode);

  for (DFGNode* dfgNode: removeNodes)
    nodes.remove(dfgNode);
}

bool DFG::searchDFS(DFGNode* t_target, DFGNode* t_head,
    list<DFGNode*>* t_visitedNodes) {
  for (DFGNode* succNode: *t_head->getSuccNodes()) {
    if (t_target == succNode) {
      return true;
    }
    // succNode is not yet visited.
    if (find(t_visitedNodes->begin(), t_visitedNodes->end(), succNode) ==
          t_visitedNodes->end()) {
      t_visitedNodes->push_back(succNode);
      if (searchDFS(t_target, succNode, t_visitedNodes)) {
        return true;
      }
    }
  }
  return false;
}

// TODO: This is necessary for inter-iteration data dependency
//       checking (ld/st dependency analysis on base address).
void DFG::detectMemDataDependency() {

}

// TODO: Certain opcode can be eliminated, such as bitcast, etc.
void DFG::eliminateOpcode(string t_opcodeName) {

}

OperationNumber DFG::getOperation() {
  /// return IntAdd;
  // return std::string("fadd");
  // cout<<"*** current function: "<<m_function.getName().data()<<"\n";
  return m_function->getName().data();
}
