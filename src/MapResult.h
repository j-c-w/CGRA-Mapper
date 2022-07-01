#ifndef MapResult_H
#define MapResult_H

#include "DFG.h"

class MapResult {
	private:
		bool m_failed;
		int m_II;
		int m_max_cycle;
		DFG *m_winning_dfg;

	public:
		MapResult(bool failed, int II, int max_cycle, DFG *winning_dfg);

		bool failed();
		int II();
		int latency();
		DFG *winningDFG();
};

#endif
