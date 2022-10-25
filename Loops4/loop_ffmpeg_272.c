// Source is: /home/alex/.local/share/compy-Learn/1.0/ffmpeg/content/libavcodec/evrcdec.c

#include <stdint.h>
#include <stdio.h>






int
fn (double lsp[10], float a1[5], int i, float b1[5], float a[6], float a2[5],
    float b2[5], float b[6])
{
  for (i = 0; i < 10 / 2; i++)
    {
      a[i + 1] = a[i] - 2 * lsp[i * 2] * a1[i] + a2[i];
      b[i + 1] = b[i] - 2 * lsp[i * 2 + 1] * b1[i] + b2[i];
      a2[i] = a1[i];
      a1[i] = a[i];
      b2[i] = b1[i];
      b1[i] = b[i];
    }
}
