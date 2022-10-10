#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;

int
fn (const char *hex_table, char *buff, int s, const uint8_t * src)
{
  for (int i = 0; i < s; i++)
    {
      buff[i * 2] = hex_table[src[i] >> 4];
      buff[i * 2 + 1] = hex_table[src[i] & 0xF];
}}
