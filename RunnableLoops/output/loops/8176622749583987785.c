#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;
typedef __uint16_t uint16_t;

int
fn (uint16_t values[256], uint8_t ** srcf, const int nb_inputs)
{
  int x = 0;
  for (int i = 0; i < nb_inputs; i++)
    {
      const uint16_t *src = (const uint16_t *) srcf[i];
      values[i] = src[x];
}}
