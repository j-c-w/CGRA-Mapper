// Source is: /home/alex/.local/share/compy-Learn/1.0/DarkNet/content/./src/image.c

#include <stdint.h>
#include <stdio.h>






int
fn (float *fdtbl, int i, float *CDU,
    const unsigned char stbiw__jpg_ZigZag[64], int DU[64])
{
  for (i = 0; i < 64; ++i)
    {
      float v = CDU[i] * fdtbl[i];
      DU[stbiw__jpg_ZigZag[i]] = (int) (v < 0 ? v - 0.5f : v + 0.5f);
}}
