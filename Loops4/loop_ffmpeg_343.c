// Source is: /home/alex/.local/share/compy-Learn/1.0/ffmpeg/content/libavcodec/qdm2.c

#include <stdint.h>
#include <stdio.h>




typedef __uint64_t uint64_t;

int
fn (float noise_table[4116], float delta, uint64_t random_seed, int i)
{
  for (i = 0; i < 4096; i++)
    {
      random_seed = random_seed * 214013 + 2531011;
      noise_table[i] =
	(delta * (float) (((int32_t) random_seed >> 16) & 0x00007FFF) -
	 1.0) * 1.3;
}}
