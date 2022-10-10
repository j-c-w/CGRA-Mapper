#include <stdint.h>
#include <stdio.h>




typedef __uint16_t uint16_t;

int
fn (const uint16_t * uptr, const uint16_t * vptr, int min_u, int max_u,
    const int width, int max_v)
{
  int min_v = 2147483647;
  for (int x = 0; x < width; x++)
    {
      min_u = ((min_u) > (uptr[x]) ? (uptr[x]) : (min_u));
      min_v = ((min_v) > (vptr[x]) ? (vptr[x]) : (min_v));
      max_u = ((max_u) > (uptr[x]) ? (max_u) : (uptr[x]));
      max_v = ((max_v) > (vptr[x]) ? (max_v) : (vptr[x]));
}}
