// Source is: /home/alex/.local/share/compy-Learn/1.0/ffmpeg/content/libavcodec/lcldec.c

#include <stdint.h>
#include <stdio.h>






int
fn (int col, unsigned int pixel_ptr, unsigned int width,
    unsigned char *encoded, unsigned char yq, unsigned char uq,
    unsigned char vq)
{
  for (col = 0; col < width / 4; col++)
    {
      encoded[pixel_ptr] = yq -= encoded[pixel_ptr];
      encoded[pixel_ptr + 1] = yq -= encoded[pixel_ptr + 1];
      encoded[pixel_ptr + 2] = yq -= encoded[pixel_ptr + 2];
      encoded[pixel_ptr + 3] = yq -= encoded[pixel_ptr + 3];
      encoded[pixel_ptr + 4] = uq -= encoded[pixel_ptr + 4];
      encoded[pixel_ptr + 5] = uq -= encoded[pixel_ptr + 5];
      encoded[pixel_ptr + 6] = vq -= encoded[pixel_ptr + 6];
      encoded[pixel_ptr + 7] = vq -= encoded[pixel_ptr + 7];
      pixel_ptr += 8;
    }
}
