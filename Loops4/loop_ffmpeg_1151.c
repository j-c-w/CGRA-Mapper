// Source is: /home/alex/.local/share/compy-Learn/1.0/ffmpeg/content/libavfilter/vf_readeia608.c

#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;

int
fn (uint8_t codes[19], int j, int bit, int run)
{
  for (int k = 0; j < 19 && k < run; k++)
    {
      codes[j++] = bit;
}}
