#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;

int
fn (int w2, int w1, int i, uint8_t * g1_scf_b, uint8_t * hr_scf,
    uint8_t * g1_scf_a)
{
  for (i = 0; i < 8; i++)
    {
      int scf = w1 * g1_scf_a[i] + w2 * g1_scf_b[i];
      hr_scf[i] = scf >> 7;
}}
