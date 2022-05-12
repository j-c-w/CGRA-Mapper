#ifndef MapResult_H
#define MapResult_H

class MapResult {
	private:
		bool m_failed;
		int m_II;
		int m_max_cycle;

	public:
		MapResult(bool failed, int II, int max_cycle);

		bool failed();
		int II();
		int latency();
};

#endif
