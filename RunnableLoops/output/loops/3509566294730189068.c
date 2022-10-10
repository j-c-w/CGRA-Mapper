#include <stdint.h>
#include <stdio.h>




typedef __int16_t int16_t;

int
fn (int16_t * ptr, int i)
{
  for (i = 0; i < 8; i++)
    {
      const int t0 = (((2841 * ptr[1 * 8] + 565 * ptr[7 * 8]) + 4) >> 3);
      const int t1 = (((565 * ptr[1 * 8] - 2841 * ptr[7 * 8]) + 4) >> 3);
      const int t2 = (((1609 * ptr[5 * 8] + 2408 * ptr[3 * 8]) + 4) >> 3);
      const int t3 = (((2408 * ptr[5 * 8] - 1609 * ptr[3 * 8]) + 4) >> 3);
      const int t4 = (((1108 * ptr[2 * 8] - 2676 * ptr[6 * 8]) + 4) >> 3);
      const int t5 = (((2676 * ptr[2 * 8] + 1108 * ptr[6 * 8]) + 4) >> 3);
      const int t6 = ((ptr[0 * 8] + ptr[4 * 8]) * (1 << 8)) + 0x2000;
      const int t7 = ((ptr[0 * 8] - ptr[4 * 8]) * (1 << 8)) + 0x2000;
      const int t8 = t0 + t2;
      const int t9 = t0 - t2;
      const int tA = (int) (181U * (t9 + (t1 - t3)) + 0x80) >> 8;
      const int tB = (int) (181U * (t9 - (t1 - t3)) + 0x80) >> 8;
      const int tC = t1 + t3;
      ptr[0 * 8] = (t6 + t5 + t8) >> 14;
      ptr[1 * 8] = (t7 + t4 + tA) >> 14;
      ptr[2 * 8] = (t7 - t4 + tB) >> 14;
      ptr[3 * 8] = (t6 - t5 + tC) >> 14;
      ptr[4 * 8] = (t6 - t5 - tC) >> 14;
      ptr[5 * 8] = (t7 - t4 - tB) >> 14;
      ptr[6 * 8] = (t7 + t4 - tA) >> 14;
      ptr[7 * 8] = (t6 + t5 - t8) >> 14;;
      ptr++;
}}
