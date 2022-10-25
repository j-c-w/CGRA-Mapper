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
typedef __int32_t int32_t;

int
fn (int32_t temp_A[8], struct Decorr *dpp, int m)
{
  int i = 0;
  for (i = 0; i < 8; i++)
    {
      dpp->samplesA[i] = temp_A[m];
      m = (m + 1) & (8 - 1);
    }
}
