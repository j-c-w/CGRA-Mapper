// Source is: /home/alex/.local/share/compy-Learn/1.0/ffmpeg/content/libavcodec/svq1dec.c

#include <stdint.h>
#include <stdio.h>




typedef __uint32_t uint32_t;

int
fn (int stages, const uint32_t * codebook, uint32_t n1, uint32_t n3,
    uint32_t n2, int j, int entries[6])
{
  for (j = 0; j < stages; j++)
    {
      n3 = codebook[entries[j]] ^ 0x80808080;
      n1 += (n3 & 0xFF00FF00) >> 8;
      n2 += n3 & 0x00FF00FF;
    }
}
