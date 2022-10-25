#define SIZE 513
#define NUM 1

int S[SIZE];
int T[SIZE];
int DTW[SIZE+1][SIZE+1];


void kernel(int id) {
  int cost[(SIZE-1)/NUM];
  int j = (SIZE-1)/NUM*id + 1;
  for(int i = 1; i < SIZE; ++i) {
    //#pragma clang loop vectorize(enable) vectorize_width(4) unroll_count(4)
    //#pragma clang loop vectorize(disable) unroll_count(4)
    for(int x=0; x<(SIZE-1)/(NUM); x++) {
		int v = S[i] - T[j + x];
		if (v < 0) {
			v = - v;
		}
      cost[x] = v;
	  int min = 65535;
	int a = DTW[i-1][j+x];
		int b = DTW[i][j+x];
		int c = DTW[i][j-1+x];
		if (a < b) min = a;
		else min = b;
		if (min > c) min = c;
      DTW[i+1][j+1+x] = cost[x] + min; 
    }
  }
}
