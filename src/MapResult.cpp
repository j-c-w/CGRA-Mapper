#include "MapResult.h"
#include "DFG.h"

MapResult::MapResult(bool fail, int II, int max_cycle, DFG *dfg) {
	m_failed = fail;
	m_II = II;
	m_max_cycle = max_cycle;
	m_winning_dfg = dfg;
}

bool MapResult::failed() {
	return m_failed;
}

int MapResult::II() {
	return m_II;
}

int MapResult::latency() {
	return m_max_cycle;
}

DFG *MapResult::winningDFG() {
	return m_winning_dfg;
}