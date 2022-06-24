#ifndef CGRA_H
#define CGRA_H
/*
 * ======================================================================
 * CGRA.h
 * ======================================================================
 * CGRA implementation header file.
 *
 * Author : Cheng Tan
 *   Date : July 16, 2019
 */

//#include "llvm/Pass.h"
#include "CGRANode.h"
#include "CGRALink.h"
#include "Options.h"
#include <iostream>
//#include <llvm/Support/raw_ostream.h>
#include <map>

using namespace llvm;

class CGRA {
  private:
    int m_FUCount;
    int m_LinkCount;
    int m_rows;
    int m_columns;
    Parameters * m_params;
    void disable();

  public:
    CGRA(Options *, Parameters *);
    CGRANode ***nodes;
    CGRALink **links;
    int getFUCount();
    void getRoutingResource();
    void constructMRRG(int);
    int getRows() { return m_rows; }
    int getColumns() { return m_columns; }
    CGRALink* getLink(CGRANode*, CGRANode*);
    void setBypassConstraint(int);
    void setCtrlMemConstraint(int);
    void setRegConstraint(int);
};

#endif
