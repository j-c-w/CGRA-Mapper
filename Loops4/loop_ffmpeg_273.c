// Source is: /home/alex/.local/share/compy-Learn/1.0/ffmpeg/content/libavcodec/g723_1enc.c

#include <stdint.h>
#include <stdio.h>




typedef __int16_t int16_t;

int
fn (int f[12], int16_t * lsp, int i)
{
  for (i = 0; i < 10 / 2; i++)
    {
      f[2 * i + 2] = -f[2 * i] - ((lsp[i] + lsp[10 - 1 - i]) << 12);
      f[2 * i + 3] = f[2 * i + 1] - ((lsp[i] - lsp[10 - 1 - i]) << 12);
    }
}
