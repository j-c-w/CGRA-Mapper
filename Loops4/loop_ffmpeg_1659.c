// Source is: /home/alex/.local/share/compy-Learn/1.0/ffmpeg/content/libavcodec/h264pred.c

#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;
typedef long int ptrdiff_t;

int
fn (int y, uint8_t * top, ptrdiff_t stride, const uint8_t * cm, uint8_t * src)
{
  for (y = 0; y < 16; y++)
    {
      const uint8_t *cm_in = cm + src[-1];
      src[0] = cm_in[top[0]];
      src[1] = cm_in[top[1]];
      src[2] = cm_in[top[2]];
      src[3] = cm_in[top[3]];
      src[4] = cm_in[top[4]];
      src[5] = cm_in[top[5]];
      src[6] = cm_in[top[6]];
      src[7] = cm_in[top[7]];
      src[8] = cm_in[top[8]];
      src[9] = cm_in[top[9]];
      src[10] = cm_in[top[10]];
      src[11] = cm_in[top[11]];
      src[12] = cm_in[top[12]];
      src[13] = cm_in[top[13]];
      src[14] = cm_in[top[14]];
      src[15] = cm_in[top[15]];
      src += stride;
}}
