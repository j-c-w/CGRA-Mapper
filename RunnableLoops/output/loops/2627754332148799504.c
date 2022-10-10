#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;

int
fn (unsigned int *vhistogram, unsigned int *uhistogram, const uint8_t * uptr,
    const uint8_t * vptr, const int width)
{
  for (int x = 0; x < width; x++)
    {
      uhistogram[uptr[x]]++;
      vhistogram[vptr[x]]++;
}}
