#include <stdint.h>
#include <stdio.h>




typedef __uint16_t uint16_t;
typedef __uint8_t uint8_t;

int
fn (const int nb_inputs, uint8_t ** srcf, uint16_t values[256])
{
  int x = 0;
  for (int i = 0; i < nb_inputs; i++)
    {
      const uint16_t *src = (const uint16_t *) srcf[i];
      values[i] = src[x];
}}
