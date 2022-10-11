#include <stdint.h>
#include <stdio.h>




typedef int32_t dwtcoef;
typedef long int ptrdiff_t;

int
fn (dwtcoef * linell, dwtcoef * linehl, dwtcoef * linelh, int x,
    dwtcoef * synthl, ptrdiff_t synthw, dwtcoef * linehh, int width)
{
  for (x = 0; x < width; x++)
    {
      linell[x] = synthl[(x << 1)];
      linehl[x] = synthl[(x << 1) + 1];
      linelh[x] = synthl[(x << 1) + synthw];
      linehh[x] = synthl[(x << 1) + synthw + 1];
    }
}