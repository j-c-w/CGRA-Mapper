#define LOOP_ITERATION loop_iteration()
#define START(u) loop_start(u)
#define END(u) loop_end(u)
#define TIMES 100000

void loop_iteration();
void loop_start(const char *id);
void loop_end(const char *id);
