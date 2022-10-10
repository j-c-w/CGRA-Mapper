#include <stdint.h>
#include <stdio.h>




typedef __int32_t int32_t;
typedef __uint64_t uint64_t;

int
fn (uint64_t sum[4], int i, int n, int32_t rt, const int32_t * left_ch,
    int32_t lt, const int32_t * right_ch)
{
  for (i = 2; i < n; i++)
    {
      lt = left_ch[i] - 2 * left_ch[i - 1] + left_ch[i - 2];
      rt = right_ch[i] - 2 * right_ch[i - 1] + right_ch[i - 2];
      sum[2] +=
	(((lt + rt) >> 1) >= 0 ? ((lt + rt) >> 1) : (-((lt + rt) >> 1)));
      sum[3] += ((lt - rt) >= 0 ? (lt - rt) : (-(lt - rt)));
      sum[0] += ((lt) >= 0 ? (lt) : (-(lt)));
      sum[1] += ((rt) >= 0 ? (rt) : (-(rt)));
    }
}
