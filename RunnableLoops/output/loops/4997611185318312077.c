#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;
typedef __int8_t int8_t;

int
fn (int w2, int8_t * g3_scf, int w1, uint8_t * g1_scf_b, int i,
    uint8_t * hr_scf, uint8_t * g1_scf_a, int g3_avg)
{
  for (i = 0; i < 8; i++)
    {
      int scf = w1 * g1_scf_a[i] + w2 * g1_scf_b[i];
      hr_scf[i] = (scf >> 7) - g3_avg - g3_scf[i];
}}
