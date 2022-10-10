#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;

int
fn (const uint8_t * uptr, int min_u, const uint8_t * vptr, const int width,
    int max_u)
{
  int min_v = 255;
  int max_v = 0;
  for (int x = 0; x < width; x++)
    {
      min_u = ((min_u) > (uptr[x]) ? (uptr[x]) : (min_u));
      min_v = ((min_v) > (vptr[x]) ? (vptr[x]) : (min_v));
      max_u = ((max_u) > (uptr[x]) ? (max_u) : (uptr[x]));
      max_v = ((max_v) > (vptr[x]) ? (max_v) : (vptr[x]));
}}
