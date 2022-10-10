#include <stdint.h>
#include <stdio.h>






int
fn (unsigned int sx[8], unsigned int k, unsigned int s[8],
    unsigned int sub_blocks)
{
  for (k = 0; k < sub_blocks; k++)
    {
      sx[k] = s[k] & 0x0F;
      s[k] >>= 4;
    }
}
