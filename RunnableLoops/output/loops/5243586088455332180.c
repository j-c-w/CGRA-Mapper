#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;
typedef __uint32_t uint32_t;

int
fn (uint8_t * dst, int k, uint32_t bits)
{
  for (k = 0; k < 32; k++)
    {
      int mask_bit = !!(bits & 0x80000000);
      switch (dst[0] * 2 + mask_bit)
	{
	case 0:
	  dst[0] = 0xFF;
	  dst[1] = 0x00;
	  dst[2] = 0x00;
	  dst[3] = 0x00;
	  break;
	case 1:
	  dst[0] = 0xFF;
	  dst[1] = 0xFF;
	  dst[2] = 0xFF;
	  dst[3] = 0xFF;
	  break;
	default:
	  dst[0] = 0x00;
	  dst[1] = 0x00;
	  dst[2] = 0x00;
	  dst[3] = 0x00;
	}
      dst += 4;
      bits <<= 1;
    }
}
