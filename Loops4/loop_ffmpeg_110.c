// Source is: /home/alex/.local/share/compy-Learn/1.0/ffmpeg/content/libavcodec/mjpegenc_common.c

#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;

int
fn (uint8_t * buf, int i, int ff_count, int size)
{
  for (; i < size - 15; i += 16)
    {
      int acc, v;
      v = *(uint32_t *) (&buf[i]);
      acc = (((v & (v >> 4)) & 0x0F0F0F0F) + 0x01010101) & 0x10101010;
      v = *(uint32_t *) (&buf[i + 4]);
      acc += (((v & (v >> 4)) & 0x0F0F0F0F) + 0x01010101) & 0x10101010;
      v = *(uint32_t *) (&buf[i + 8]);
      acc += (((v & (v >> 4)) & 0x0F0F0F0F) + 0x01010101) & 0x10101010;
      v = *(uint32_t *) (&buf[i + 12]);
      acc += (((v & (v >> 4)) & 0x0F0F0F0F) + 0x01010101) & 0x10101010;
      acc >>= 4;
      acc += (acc >> 16);
      acc += (acc >> 8);
      ff_count += acc & 0xFF;
}}
