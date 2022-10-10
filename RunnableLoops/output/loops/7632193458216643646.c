#include <stdint.h>
#include <stdio.h>




typedef float INTFLOAT;

int
fn (int i, INTFLOAT * buf, const int n)
{
  for (i = 0; i < n; i += 2)
    {
      buf[i] = -buf[i];
    }
}
