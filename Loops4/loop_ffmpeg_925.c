// Source is: /home/alex/.local/share/compy-Learn/1.0/ffmpeg/content/libavcodec/agm.c

#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;

int
fn (int blcounts[32], int zlcount, int syms[8192], const uint8_t * bitlens)
{
  for (int i = 0; i < 256; i++)
    {
      int bitlen = bitlens[i];
      int blcount = blcounts[bitlen];
      zlcount += bitlen < 1;
      syms[(bitlen << 8) + blcount] = i;
      blcounts[bitlen]++;
}}
