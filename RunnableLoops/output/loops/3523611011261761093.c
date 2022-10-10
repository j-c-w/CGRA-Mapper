#include <stdint.h>
#include <stdio.h>






int
fn (float *buf, int i)
{
  for (i = 0; i < 256; i++)
    {
      do
	{
	  float SWAP_tmp = buf[1023 - i];
	  buf[1023 - i] = buf[i + 512];
	  buf[i + 512] = SWAP_tmp;
	}
      while (0);
    }
}
