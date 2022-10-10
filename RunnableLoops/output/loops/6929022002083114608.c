#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;

int
fn (int i, uint8_t * cap, uint8_t field1, const uint8_t * p)
{
  int cc_count = 0;
  for (i = 0; i < cc_count; i++)
    {
      cap[0] = (p[0] == 0xff && field1) ? 0xfc : 0xfd;
      cap[1] = p[1];
      cap[2] = p[2];
      cap[3] = (p[3] == 0xff && !field1) ? 0xfc : 0xfd;
      cap[4] = p[4];
      cap[5] = p[5];
      cap += 6;
      p += 6;
    }
}
