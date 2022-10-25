// Source is: /home/alex/.local/share/compy-Learn/1.0/ffmpeg/content/libavcodec/dca_lbr.c

#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;
typedef __int8_t int8_t;

int
fn (int w2, int i, uint8_t * g1_scf_a, int8_t * g3_scf, int g3_avg,
    uint8_t * g1_scf_b, int w1, uint8_t * hr_scf)
{
  for (i = 0; i < 8; i++)
    {
      int scf = w1 * g1_scf_a[i] + w2 * g1_scf_b[i];
      hr_scf[i] = (scf >> 7) - g3_avg - g3_scf[i];
}}
