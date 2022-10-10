#include <stdint.h>
#include <stdio.h>




typedef __int16_t int16_t;

int
fn (int i, const int16_t ** tmpU, const int vChrFilterSize)
{
  for (; i < vChrFilterSize; i++)
    {
      tmpU[i] = tmpU[i - 1];
    }
}
