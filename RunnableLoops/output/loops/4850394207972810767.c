#include <stdint.h>
#include <stdio.h>






int
fn (unsigned int sub_count, int *p, int *block_p, unsigned int i,
    unsigned int sub_len)
{
  for (i = 0, p = block_p; i < sub_count; i++)
    {
      p[0]++;
      p += sub_len;
    }
}
