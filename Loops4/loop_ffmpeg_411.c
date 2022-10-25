// Source is: /home/alex/.local/share/compy-Learn/1.0/ffmpeg/content/libavcodec/aic.c

#include <stdint.h>
#include <stdio.h>




typedef __int16_t int16_t;
typedef __uint8_t uint8_t;

int
fn (int16_t * block, uint8_t * quant_matrix, int i, int q)
{
  for (i = 0; i < 64; i++)
    {
      int val = (uint16_t) block[i];
      int sign = val & 1;
      block[i] = (((val >> 1) ^ -sign) * q * quant_matrix[i] >> 4) + sign;
}}
