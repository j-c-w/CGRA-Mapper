#include <stdint.h>
#include <stdio.h>




typedef __uint16_t uint16_t;

int
fn (uint16_t * codes_count)
{
  for (unsigned i = 32, nb_codes = 0; i > 0; i--)
    {
      uint16_t curr = codes_count[i];
      codes_count[i] = nb_codes / 2;
      nb_codes = codes_count[i] + curr;
}}
