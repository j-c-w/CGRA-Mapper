// Source is: /home/alex/.local/share/compy-Learn/1.0/ffmpeg/content/libavcodec/rpzaenc.c

#include <stdint.h>
#include <stdio.h>




typedef __uint16_t uint16_t;
typedef __uint8_t uint8_t;

int
fn (uint16_t * color, uint8_t dithered_color[3])
{
  for (int channel = 0; channel < 3; channel++)
    {
      dithered_color[channel] = (((color[0]) >> ((channel) * 5) & 0x1F) * 8);
}}
