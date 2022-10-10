#include <stdint.h>
#include <stdio.h>




typedef __uint16_t uint16_t;

int
fn (unsigned int *vhistogram, unsigned int *uhistogram, const uint16_t * uptr,
    const uint16_t * vptr, const int width)
{
  for (int x = 0; x < width; x++)
    {
      uhistogram[uptr[x]]++;
      vhistogram[vptr[x]]++;
}}
