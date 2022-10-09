#include<time.h>
#include <stdio.h>

int iter_count;
clock_t start;

void loop_iteration() {
	iter_count += 1;
}

void loop_start(const char * id) {
	iter_count = 0;
	start = clock();
}

void loop_end(const char *id) {
	clock_t end = clock();
	double time = (double) (end - start) / CLOCKS_PER_SEC;
	printf("%s, %d, %.12f\n", id, iter_count, time);
}
