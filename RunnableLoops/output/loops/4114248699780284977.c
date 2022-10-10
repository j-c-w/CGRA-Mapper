#include <stdint.h>
#include <stdio.h>






int
fn (int i, const unsigned char *alloc, int max_sb)
{
  for (i = 0; i < max_sb; i++)
    {
      alloc += 1 << alloc[0];
    }
}
