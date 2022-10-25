// Source is: /home/alex/.local/share/compy-Learn/1.0/ffmpeg/content/libavcodec/wavpackenc.c

#include <stdint.h>
#include <stdio.h>




typedef struct Decorr
{
  int delta;
  int value;
  int weightA;
  int weightB;
  int samplesA[8];
  int samplesB[8];
  int sumA;
  int sumB;
} Decorr;

int
fn (struct Decorr *dpp, int j, int k, int i)
{
  for (i = 0, j = dpp->value - 1, k = 0; k < dpp->value / 2; i++, j--, k++)
    {
      i &= (8 - 1);
      j &= (8 - 1);
      dpp->samplesA[i] ^= dpp->samplesA[j];
      dpp->samplesA[j] ^= dpp->samplesA[i];
      dpp->samplesA[i] ^= dpp->samplesA[j];
      dpp->samplesB[i] ^= dpp->samplesB[j];
      dpp->samplesB[j] ^= dpp->samplesB[i];
      dpp->samplesB[i] ^= dpp->samplesB[j];
    }
}
