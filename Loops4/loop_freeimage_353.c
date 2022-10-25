// Source is: /home/alex/.local/share/compy-Learn/1.0/freeimage/content/Source/LibWebP/src/dsp/dec.c

#include <stdint.h>
#include <stdio.h>




typedef __int16_t int16_t;

int
fn (int *tmp, int i, const int16_t * in)
{
  for (i = 0; i < 4; ++i)
    {
      const int a = in[0] + in[8];
      const int b = in[0] - in[8];
      const int c =
	(((in[4]) * 35468) >> 16) - ((((in[12]) * 20091) >> 16) + (in[12]));
      const int d =
	((((in[4]) * 20091) >> 16) + (in[4])) + (((in[12]) * 35468) >> 16);
      tmp[0] = a + d;
      tmp[1] = b + c;
      tmp[2] = b - c;
      tmp[3] = a - d;
      tmp += 4;
      in++;
}}
