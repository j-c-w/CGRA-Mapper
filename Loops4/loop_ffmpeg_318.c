// Source is: /home/alex/.local/share/compy-Learn/1.0/ffmpeg/content/libavutil/aes.c

#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;

int
fn (uint8_t sbox[256], int i, uint8_t alog8[512], uint8_t inv_sbox[256],
    int j, uint8_t log8[256])
{
  for (i = 0; i < 256; i++)
    {
      j = i ? alog8[255 - log8[i]] : 0;
      j ^= (j << 1) ^ (j << 2) ^ (j << 3) ^ (j << 4);
      j = (j ^ (j >> 8) ^ 99) & 255;
      inv_sbox[j] = i;
      sbox[i] = j;
    }
}
