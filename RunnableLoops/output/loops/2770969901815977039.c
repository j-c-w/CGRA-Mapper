#include <stdint.h>
#include <stdio.h>




typedef short IDWTELEM;

int
fn (int i, IDWTELEM * temp, IDWTELEM * b)
{
  for (; (i & 0x1E) != 0x1E; i -= 2)
    {
      b[i + 1] = temp[i >> 1];
      b[i] = b[i >> 1];
    }
}
