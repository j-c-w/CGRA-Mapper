// Source is: /home/alex/.local/share/compy-Learn/1.0/ffmpeg/content/libavcodec/texturedspenc.c

#include <stdint.h>
#include <stdio.h>




typedef __uint32_t uint32_t;
typedef __uint8_t uint8_t;
typedef long int ptrdiff_t;

int
fn (const uint8_t * block, int y, uint32_t cm, int at1_r, ptrdiff_t stride,
    int x, const int w1tab[4], int at1_g, int at2_g, int at2_r,
    const int prods[4])
{
  int at2_b = 0;
  int at1_b = 0;
  int akku = 0;
  for (x = 0; x < 4; x++)
    {
      int step = cm & 3;
      int w1 = w1tab[step];
      int r = block[0 + x * 4 + y * stride];
      int g = block[1 + x * 4 + y * stride];
      int b = block[2 + x * 4 + y * stride];
      akku += prods[step];
      at1_r += w1 * r;
      at1_g += w1 * g;
      at1_b += w1 * b;
      at2_r += r;
      at2_g += g;
      at2_b += b;
      cm >>= 2;
}}
