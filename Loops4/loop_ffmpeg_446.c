// Source is: /home/alex/.local/share/compy-Learn/1.0/ffmpeg/content/libavcodec/mss34dsp.c

#include <stdint.h>
#include <stdio.h>






int
fn (int *ptr, int i)
{
  for (i = 0; i < 8; i++)
    {
      const unsigned t0 = -39409U * ptr[7 * 1] - 58980U * ptr[1 * 1];
      const unsigned t1 = 39410U * ptr[1 * 1] - 58980U * ptr[7 * 1];
      const unsigned t2 = -33410U * ptr[5 * 1] - 167963U * ptr[3 * 1];
      const unsigned t3 = 33410U * ptr[3 * 1] - 167963U * ptr[5 * 1];
      const unsigned t4 = ptr[3 * 1] + ptr[7 * 1];
      const unsigned t5 = ptr[1 * 1] + ptr[5 * 1];
      const unsigned t6 = 77062U * t4 + 51491U * t5;
      const unsigned t7 = 77062U * t5 - 51491U * t4;
      const unsigned t8 = 35470U * ptr[2 * 1] - 85623U * ptr[6 * 1];
      const unsigned t9 = 35470U * ptr[6 * 1] + 85623U * ptr[2 * 1];
      const unsigned tA = (((ptr[0 * 1] - ptr[4 * 1]) * (1U << 16)) + 0x2000);
      const unsigned tB = (((ptr[0 * 1] + ptr[4 * 1]) * (1U << 16)) + 0x2000);
      ptr[0 * 1] = (int) (t1 + t6 + t9 + tB) >> 13;
      ptr[1 * 1] = (int) (t3 + t7 + t8 + tA) >> 13;
      ptr[2 * 1] = (int) (t2 + t6 - t8 + tA) >> 13;
      ptr[3 * 1] = (int) (t0 + t7 - t9 + tB) >> 13;
      ptr[4 * 1] = (int) (-(t0 + t7) - t9 + tB) >> 13;
      ptr[5 * 1] = (int) (-(t2 + t6) - t8 + tA) >> 13;
      ptr[6 * 1] = (int) (-(t3 + t7) + t8 + tA) >> 13;
      ptr[7 * 1] = (int) (-(t1 + t6) + t9 + tB) >> 13;;
      ptr += 8;
}}
