/*
 * ======================================================================
 * DFGNode.cpp
 * ======================================================================
 * DFG node implementation.
 *
 * Author : Cheng Tan
 *   Date : Feb 12, 2020
 */

#include "DFGNode.h"
#include "OperationMap.h"
#include <iostream>
#include <string>

DFGNode::DFGNode(int t_id, bool t_precisionAware, Instruction* t_inst, std::string opcodeName,
                 StringRef t_stringRef) {
  m_id = t_id;
  m_precisionAware = t_precisionAware;
  m_inst = t_inst;
  m_stringRef = t_stringRef;
  m_predNodes = NULL;
  m_succNodes = NULL;
  m_opcodeName = opcodeName;
  m_isMapped = false;
  m_numConst = 0;
  m_optType = "";
  m_combined = false;
  m_isPatternRoot = false;
  m_patternRoot = NULL;
  m_critical = false;
  m_cycleID = new list<int>();
  m_level = 0;
  m_execLatency = 1;
  m_pipelinable = false;
  m_isPredicatee = false;
  m_predicatees = NULL;
  m_isPredicater = false;
  m_patternNodes = new list<DFGNode*>();
  initType();
}

void DFGNode::setInstruction(Instruction *inst, StringRef name) {
	m_opcodeName = inst->getOpcodeName();
	m_stringRef = name;
	m_inst = inst;
}

int DFGNode::getID() {
  return m_id;
}

std::string DFGNode::asString() {
	std::string node_string =
		"Node " + m_opcodeName + "(" + std::to_string(getID()) + ") with edges (in: ";
	for (DFGEdge *e : m_inEdges) {
		node_string.append(e->asString());
	}
	node_string.append("), (out: ");
	for (DFGEdge *e : m_outEdges) {
		node_string.append(e->asString());
	}
	node_string.append(")");
	return node_string;
}

void DFGNode::setID(int t_id) {
  m_id = t_id;
}

void DFGNode::setLevel(int t_level) {
  m_level = t_level;
}

int DFGNode::getLevel() {
  return m_level;
}

void DFGNode::setCritical() {
  m_critical = true;
}

void DFGNode::addCycleID(int t_cycleID) {
  m_cycleID->push_back(t_cycleID);
}

list<int>* DFGNode::getCycleIDs() {
  return m_cycleID;
}

bool DFGNode::shareSameCycle(DFGNode* t_node) {
  cout<<"[Tan] in shareSameCycle node "<<t_node->getID()<<endl;
  list<int>* my_list = t_node->getCycleIDs();
  for (int cycleID: *m_cycleID) {
    bool found = (find(my_list->begin(), my_list->end(), cycleID) != my_list->end());
    if (found) {
      return true;
    }
  }
  return false;
}

bool DFGNode::isCritical() {
  return m_critical;
}

void DFGNode::setPredicatee() {
  m_isPredicatee = true;
}

bool DFGNode::isPredicatee() {
  return m_isPredicatee;
}

bool DFGNode::isPredicater() {
  return m_isPredicater;
}

void DFGNode::addPredicatee(DFGNode* t_node) {
  m_isPredicater = true;
  if (m_predicatees == NULL) {
    m_predicatees = new list<DFGNode*>();
  }
  m_predicatees->push_back(t_node);
  t_node->setPredicatee();
}

list<DFGNode*>* DFGNode::getPredicatees() {
  return m_predicatees;
}

bool DFGNode::isMapped() {
  return m_isMapped;
}

void DFGNode::setMapped() {
  m_isMapped = true;
}

void DFGNode::clearMapped() {
  m_isMapped = false;
}

Instruction* DFGNode::getInst() {
  if (m_inst == nullptr) {
	  assert(false); // To make egraphs easier, we don't generate Instruction nodes.
	  // only do that if you have to.
  }
  return m_inst;
}

StringRef DFGNode::getStringRef() {
  return m_stringRef;
}

bool DFGNode::isCall() {
  if (m_opcodeName.compare("call") == 0)
    return true;
  return false;
}

bool DFGNode::isLoad() {
  if (m_opcodeName.compare("load") == 0)
    return true;
  return false;
}

bool DFGNode::isConst() {
	if (m_opcodeName.rfind("const_") == 0)
		return true;
	return false;
}

// Not all nodes actually require any compute resources.
bool DFGNode::isTransparentOp() {
	if (m_opcodeName.compare("sitofp") == 0
			|| m_opcodeName.compare("ret") == 0
			|| m_opcodeName.compare("phi") == 0
			|| m_opcodeName.compare("bitcast") == 0
			|| m_opcodeName.compare("trunc") == 0
			// These ones are not so much 'transparent'
			// as "I'm not 100% sure that they
			// are really different from load/store.  Perhaps
			// we should just include these with them.
			|| m_opcodeName.compare("getelementptr") == 0
			|| m_opcodeName.compare("extractelement") == 0
			|| m_opcodeName.compare("insertelement") == 0
			// I don't understand why CGRA-mapper would ever
			// produce a loop mapping w/out these, but it
			// does sometimes, so give them a free pass,
			// as it's compeltely reasonable to require that
			// ld/st operations exist!
			|| m_opcodeName.compare("load") == 0
			|| m_opcodeName.compare("store") == 0
			)
		return true;
	return false;
}

bool DFGNode::isReturn() {
  if (m_opcodeName.compare("ret") == 0)
    return true;
  return false;
}

bool DFGNode::isStore() {
  if (m_opcodeName.compare("store") == 0)
    return true;
  return false;
}

bool DFGNode::isBranch() {
  if (m_opcodeName.compare("br") == 0)
    return true;
  return false;
}

bool DFGNode::isPhi() {
  if (m_opcodeName.compare("phi") == 0)
    return true;
  return false;
}

bool DFGNode::isOpt(string t_opt) {
  if (m_opcodeName.compare(t_opt) == 0)
    return true;
  return false;
}

bool DFGNode::isMul() {
  if (m_opcodeName.compare("fmul") == 0 or
      m_opcodeName.compare("mul") == 0)
    return true;
  return false;
}

bool DFGNode::isAdd() {
  if (m_opcodeName.compare("getelementptr") == 0 or
      m_opcodeName.compare("add") == 0  or
      m_opcodeName.compare("fadd") == 0 or
      m_opcodeName.compare("sub") == 0  or
      m_opcodeName.compare("fsub") == 0)
    return true;
  return false;
}

bool DFGNode::isBr() {
	if (m_opcodeName.compare("br") == 0) {
		return true;
	}

	return false;
}

bool DFGNode::isIntSub() {
	cout << m_opcodeName << endl;
	if (m_opcodeName.compare("sub") == 0) // or
			//m_opcodeName.compare("fsub") == 0)
		return true;
	return false;
}

bool DFGNode::isCmp() {
  if (m_opcodeName.compare("icmp") == 0 or m_opcodeName.compare("cmp") == 0)
    return true;
  return false;
}

bool DFGNode::isBitcast() {
  if (m_opcodeName.compare("bitcast") == 0)
    return true;
  return false;
}

bool DFGNode::isGetptr() {
  if (m_opcodeName.compare("getelementptr") == 0)
    return true;
  return false;
}

bool DFGNode::hasCombined() {
  return m_combined;
}

void DFGNode::setCombine() {
  m_combined = true;
}

void DFGNode::addPatternPartner(DFGNode* t_patternNode) {
  m_isPatternRoot = true;
  m_patternRoot = this;
  m_patternNodes->push_back(t_patternNode);
  t_patternNode->setPatternRoot(this);
  m_opcodeName += t_patternNode->getOpcodeName();
}

list<DFGNode*>* DFGNode::getPatternNodes() {
  return m_patternNodes;
}

void DFGNode::setPatternRoot(DFGNode* t_patternRoot) {
  m_patternRoot = t_patternRoot;
}

DFGNode* DFGNode::getPatternRoot() {
  return m_patternRoot;
}

bool DFGNode::isPatternRoot() {
  return m_isPatternRoot;
}

string DFGNode::getOpcodeName() {

  if (not m_precisionAware) {
    if (m_opcodeName.compare("fadd") == 0) {
      return "add";
    } else if (m_opcodeName.compare("fsub") == 0) {
      return "sub";
    } else if (m_opcodeName.compare("fmul") == 0) {
      return "mul";
    } else if (m_opcodeName.compare("fcmp") == 0) {
      return "cmp";
    } else if (m_opcodeName.compare("icmp") == 0) {
      return "cmp";
    } else if (m_opcodeName.compare("fdiv") == 0) {
      return "div";
    }
  }

  return m_opcodeName;
}

string DFGNode::getFuType() {
  return m_fuType;
}

string DFGNode::getJSONOpt() {

  int numPred = 0;
  for (DFGEdge* edge: m_inEdges) {
    if (!edge->isCtrlEdge()) {
      numPred += 1;
    }
  }

  if (numPred < 2) {
    if (isPhi() or isCmp() or isGetptr() or m_opcodeName.compare("add") == 0 or
        m_opcodeName.compare("fadd") == 0 or m_opcodeName.compare("sub") == 0 or
        m_opcodeName.compare("fsub") == 0 or m_opcodeName.compare("fmul") == 0 or
        m_opcodeName.compare("mul") == 0 or m_opcodeName.compare("shl") == 0 or
        m_opcodeName.compare("lshr") == 0 or m_opcodeName.compare("ashr") == 0) {
      return m_optType + "_CONST";
    }
  }
  return m_optType;
}

void DFGNode::setExecLatency(int t_execLatency) {
  m_execLatency = t_execLatency;
}

int DFGNode::getExecLatency() {
  return m_execLatency;
}

bool DFGNode::isMultiCycleExec() {
  if (m_execLatency > 1) {
    return true;
  } else {
    return false;
  }
}

void DFGNode::setPipelinable() {
  m_pipelinable = true;
}

bool DFGNode::isPipelinable() {
  return m_pipelinable;
}

bool DFGNode::shareFU(DFGNode* t_dfgNode) {
  if (t_dfgNode->getFuType().compare(m_fuType) == 0) {
    return true;
  }
  return false;
}

void DFGNode::initType() {
  if (isLoad()) {
    m_optType = "OPT_LD";
    m_fuType = "MemUnit";
  } else if (isStore()) {
    m_optType = "OPT_STR";
    m_fuType = "MemUnit";
  } else if (isBranch()) {
    m_optType = "OPT_BRH";
    m_fuType = "Branch";
  } else if (isPhi()) {
    m_optType = "OPT_PHI";
    m_fuType = "Phi";
  } else if (isCmp()) {
    m_optType = "OPT_EQ";
    m_fuType = "Comp";
  } else if (isBitcast()) {
    m_optType = "OPT_NAH";
    m_fuType = "Alu";
  } else if (isGetptr()) {
    m_optType += "OPT_ADD";
    m_fuType = "Alu";
  } else if (m_opcodeName.compare("add") == 0) {
    m_optType = "OPT_ADD";
    m_fuType = "Alu";
  } else if (m_opcodeName.compare("sdiv") == 0) {
    m_optType = "OPT_DIV";
    m_fuType = "Div";
  } else if (m_opcodeName.compare("div") == 0) {
    m_optType = "OPT_DIV";
    m_fuType = "Div";
  } else if (m_opcodeName.compare("srem") == 0) {
    m_optType = "OPT_REM";
    m_fuType = "Div";
  } else if (m_opcodeName.compare("rem") == 0) {
    m_optType = "OPT_REM";
    m_fuType = "Div";
  } else if (m_opcodeName.compare("trunc") == 0) {
    m_optType = "OPT_TRUNC";
    m_fuType = "Alu";
  } else if (m_opcodeName.compare("select") == 0) {
    m_optType = "OPT_SEL";
    m_fuType = "Select";
  } else if (m_opcodeName.compare("ext") == 0) {
    m_optType = "OPT_EXT";
    m_fuType = "ext";
  } else if (m_opcodeName.compare("sext") == 0) {
    m_optType = "OPT_EXT";
    m_fuType = "sext";
  } else if (m_opcodeName.compare("zext") == 0) {
    m_optType = "OPT_EXT";
    m_fuType = "zext";
  } else if (m_opcodeName.compare("extractelement") == 0) {
    m_optType = "OPT_EXTRACT";
    m_fuType = "extract";
  } else if (m_opcodeName.compare("fadd") == 0) {
    m_optType = "OPT_ADD";
    m_fuType = "Alu";
  } else if (m_opcodeName.compare("sub") == 0) {
    m_optType = "OPT_SUB";
    m_fuType = "Alu";
  } else if (m_opcodeName.compare("fsub") == 0) {
    m_optType = "OPT_SUB";
    m_fuType = "Alu";
  } else if (m_opcodeName.compare("xor") == 0) {
    m_optType = "OPT_XOR";
    m_fuType = "Alu";
  } else if (m_opcodeName.compare("or") == 0) {
    m_optType = "OPT_OR";
    m_fuType = "Logic";
  } else if (m_opcodeName.compare("and") == 0) {
    m_optType = "OPT_AND";
    m_fuType = "Logic";
  } else if (m_opcodeName.compare("mul") == 0) {
    m_optType = "OPT_MUL";
    m_fuType = "Mul";
  } else if (m_opcodeName.compare("fmul") == 0) {
    m_optType = "OPT_MUL";
    m_fuType = "Mul";
  } else if (m_opcodeName.compare("shl") == 0) {
    m_optType = "OPT_SHL";
    m_fuType = "Shift";
  } else if (m_opcodeName.compare("lshr") == 0) {
    m_optType = "OPT_LSR";
    m_fuType = "Shift";
  } else if (m_opcodeName.compare("ashr") == 0) {
    m_optType = "OPT_ASR";
    m_fuType = "Shift";
  } else {
    m_optType = "Unfamiliar: " + m_opcodeName;
    m_fuType = "Unknown";
  }
}

list<DFGEdge*> *DFGNode::getInEdges() {
	return &m_inEdges;
}

list<DFGEdge*> *DFGNode::getOutEdges() {
	return &m_outEdges;
}

list<DFGNode*>* DFGNode::getPredNodes() {
  if (m_predNodes != NULL)
    return m_predNodes;

  m_predNodes = new list<DFGNode*>();
  for (DFGEdge* edge: m_inEdges) {
    assert(edge->getDst() == this);
    m_predNodes->push_back(edge->getSrc());
  }
  if (isBranch()) {
    list<DFGNode*>* m_tempNodes = new list<DFGNode*>();
    for (DFGNode* node: *m_predNodes) {
      // make sure the CMP node is the last one in the predecessors,
      // so the JSON file will get the correct ordering.
      if (!node->isCmp()) {
        m_tempNodes->push_back(node);
      }
    }
    for (DFGNode* node: *m_predNodes) {
      if (node->isCmp()) {
        m_tempNodes->push_back(node);
      }
    }
    m_predNodes = m_tempNodes;
  }
  return m_predNodes;
}

list<DFGNode*>* DFGNode::getSuccNodes() {
  if (m_succNodes != NULL)
    return m_succNodes;

  m_succNodes = new list<DFGNode*>();
  for (DFGEdge* edge: m_outEdges) {
    assert(edge->getSrc() == this);
    m_succNodes->push_back(edge->getDst());
  }
  return m_succNodes;
}

void DFGNode::setInEdge(DFGEdge* t_dfgEdge) {
  if (find(m_inEdges.begin(), m_inEdges.end(), t_dfgEdge) ==
      m_inEdges.end())
    m_inEdges.push_back(t_dfgEdge);
}

void DFGNode::setOutEdge(DFGEdge* t_dfgEdge) {
  if (find(m_outEdges.begin(), m_outEdges.end(), t_dfgEdge) ==
      m_outEdges.end())
    m_outEdges.push_back(t_dfgEdge);
}

void DFGNode::cutEdges() {
  m_inEdges.clear();
  m_outEdges.clear();

  if (m_predNodes != NULL) {
    m_predNodes = NULL;
  }
  if (m_succNodes != NULL) {
    m_succNodes = NULL;
  }
}

DFGEdge *DFGNode::getPredEdge(int index) {
	auto it = m_inEdges.begin();
	std::advance(it, index);
	return *it;
}

bool DFGNode::isSuccessorOf(DFGNode* t_dfgNode) {
  list<DFGNode*>* succNodes = t_dfgNode->getSuccNodes();
  if (find (succNodes->begin(), succNodes->end(), this) != succNodes->end())
    return true;
  return false;
}

bool DFGNode::isPredecessorOf(DFGNode* t_dfgNode) {
  list<DFGNode*>* predNodes = t_dfgNode->getPredNodes();
  if (find (predNodes->begin(), predNodes->end(), this) != predNodes->end())
    return true;
  return false;
}

bool DFGNode::isOneOfThem(list<DFGNode*>* t_pattern) {
  if (find (t_pattern->begin(), t_pattern->end(), this) != t_pattern->end())
    return true;
  return false;
}

void DFGNode::addConst() {
  ++m_numConst;
}

void DFGNode::removeInEdge(DFGEdge *e) {
	m_inEdges.remove(e);

	clearCachedNodes();
}

void DFGNode::removeOutEdge(DFGEdge *e) {
	m_outEdges.remove(e);

	clearCachedNodes();
}

void DFGNode::addInEdge(DFGEdge *e) {
	m_inEdges.push_back(e);

	clearCachedNodes();
}

void DFGNode::addOutEdge(DFGEdge *e) {
	m_outEdges.push_back(e);

	clearCachedNodes();
}


void DFGNode::removeConst() {
  --m_numConst;
}

int DFGNode::getNumConst() {
  return m_numConst;
}

OperationNumber DFGNode::getOperation() {
	return m_opcodeName;
	// return std::string("fadd");
}

void DFGNode::clearCachedNodes() {
	m_predNodes = NULL;
	m_succNodes = NULL;
}
