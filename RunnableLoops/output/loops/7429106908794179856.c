#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;

int
fn (const uint8_t * extradata, int extradata_size, int i, int *header_len)
{
  int overall_len = 3;
  for (; overall_len < extradata_size && *extradata == 0xff; extradata++)
    {
      header_len[i] += 0xff;
      overall_len += 0xff + 1;
    }
}
