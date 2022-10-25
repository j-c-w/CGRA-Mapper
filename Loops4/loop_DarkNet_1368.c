// Source is: /home/alex/.local/share/compy-Learn/1.0/DarkNet/content/./src/image.c

#include <stdint.h>
#include <stdio.h>




typedef unsigned char stbi_uc;

int
fn (int output_bytes, int k, stbi_uc * prior, stbi_uc * raw, int filter_bytes,
    stbi_uc * cur)
{
  for (k = 0; k < filter_bytes; ++k)
    {
      cur[k] =
	((stbi_uc)
	 ((raw[k] + ((prior[k] + cur[k - output_bytes]) >> 1)) & 255));
    }
}
