// Source is: /home/alex/.local/share/compy-Learn/1.0/ffmpeg/content/libavcodec/mss34dsp.c

#include <stdint.h>
#include <stdio.h>






int
fn (int *ptr, int i)
{
  for (i = 0; i < 8; i++)
    {
      const unsigned t0 = -39409U * ptr[7 * 8] - 58980U * ptr[1 * 8];
      const unsigned t1 = 39410U * ptr[1 * 8] - 58980U * ptr[7 * 8];
      const unsigned t2 = -33410U * ptr[5 * 8] - 167963U * ptr[3 * 8];
      const unsigned t3 = 33410U * ptr[3 * 8] - 167963U * ptr[5 * 8];
      const unsigned t4 = ptr[3 * 8] + ptr[7 * 8];
      const unsigned t5 = ptr[1 * 8] + ptr[5 * 8];
      const unsigned t6 = 77062U * t4 + 51491U * t5;
      const unsigned t7 = 77062U * t5 - 51491U * t4;
      const unsigned t8 = 35470U * ptr[2 * 8] - 85623U * ptr[6 * 8];
      const unsigned t9 = 35470U * ptr[6 * 8] + 85623U * ptr[2 * 8];
      const unsigned tA = (((ptr[0 * 8] - ptr[4 * 8]) + 32) * (1U << 16));
      const unsigned tB = (((ptr[0 * 8] + ptr[4 * 8]) + 32) * (1U << 16));
      ptr[0 * 8] = (int) (t1 + t6 + t9 + tB) >> 22;
      ptr[1 * 8] = (int) (t3 + t7 + t8 + tA) >> 22;
      ptr[2 * 8] = (int) (t2 + t6 - t8 + tA) >> 22;
      ptr[3 * 8] = (int) (t0 + t7 - t9 + tB) >> 22;
      ptr[4 * 8] = (int) (-(t0 + t7) - t9 + tB) >> 22;
      ptr[5 * 8] = (int) (-(t2 + t6) - t8 + tA) >> 22;
      ptr[6 * 8] = (int) (-(t3 + t7) + t8 + tA) >> 22;
      ptr[7 * 8] = (int) (-(t1 + t6) + t9 + tB) >> 22;;
      ptr++;
}}
