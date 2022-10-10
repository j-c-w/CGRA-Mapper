#include <stdint.h>
#include <stdio.h>






int
fn (int i, int x, int ret, const int fixed_log_table[10], int tmp, int xpow)
{
  for (i = 0; i < 10; i += 2)
    {
      xpow = (int) (((int64_t) xpow * x + 0x40000000) >> 31);
      tmp = (int) (((int64_t) xpow * fixed_log_table[i] + 0x40000000) >> 31);
      ret -= tmp;
      xpow = (int) (((int64_t) xpow * x + 0x40000000) >> 31);
      tmp =
	(int) (((int64_t) xpow * fixed_log_table[i + 1] + 0x40000000) >> 31);
      ret += tmp;
}}
