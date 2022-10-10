#include <stdint.h>
#include <stdio.h>




typedef __uint32_t uint32_t;
typedef __uint8_t uint8_t;
typedef __int16_t int16_t;

int
fn (int level[16], int i, int total_coeff, int16_t * block,
    const uint8_t * scantable, const uint32_t * qmul)
{
  for (; i < total_coeff; i++)
    {
      scantable--;
      ((int32_t *) block)[*scantable] =
	((int) (level[i] * qmul[*scantable] + 32)) >> 6;
}}
