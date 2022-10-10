#include <stdint.h>
#include <stdio.h>






int
fn (int i, int max_sb, const unsigned char *alloc)
{
  for (i = 0; i < max_sb; i++)
    {
      alloc += 1 << alloc[0];
    }
}
