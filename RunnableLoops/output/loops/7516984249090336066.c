#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;
typedef __uint16_t uint16_t;

int
fn (int code, int k, uint8_t * huff_size, const uint8_t * val_table, int nb,
    uint16_t * huff_code)
{
  int i = 1;
  for (int j = 0; j < nb; j++)
    {
      int sym = val_table[k++];
      huff_size[sym] = i;
      huff_code[sym] = code;
      code++;
}}
