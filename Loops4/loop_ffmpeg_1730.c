// Source is: /home/alex/.local/share/compy-Learn/1.0/ffmpeg/content/libavcodec/mjpegenc_common.c

#include <stdint.h>
#include <stdio.h>




typedef __uint16_t uint16_t;
typedef __uint8_t uint8_t;

int
fn (uint16_t * huff_code, int nb, uint8_t * huff_size, int k, int code,
    const uint8_t * val_table)
{
  int i = 1;
  for (int j = 0; j < nb; j++)
    {
      int sym = val_table[k++];
      huff_size[sym] = i;
      huff_code[sym] = code;
      code++;
}}
