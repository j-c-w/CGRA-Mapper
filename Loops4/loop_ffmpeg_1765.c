// Source is: /home/alex/.local/share/compy-Learn/1.0/ffmpeg/content/libavcodec/adpcm.c

#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;

int
fn (uint8_t temp[84], int channels, const uint8_t * buf, int block_size)
{
  int n = 0;
  int i = 0;
  for (int j = 0; j < block_size; j++)
    {
      temp[j] =
	buf[4 * channels + block_size * n * channels + (j % 4) +
	    (j / 4) * (channels * 4) + i * 4];
}}
