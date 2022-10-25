// Source is: /home/alex/.local/share/compy-Learn/1.0/ffmpeg/content/libavfilter/vf_unsharp.c

#include <stdint.h>
#include <stdio.h>




typedef __uint32_t uint32_t;

int
fn (uint32_t * sr, const int steps_x, int z, const int sr_offset,
    uint32_t tmp1, uint32_t tmp2)
{
  for (z = 0; z < steps_x * 2; z += 2)
    {
      tmp2 = sr[sr_offset + z + 0] + tmp1;
      sr[sr_offset + z + 0] = tmp1;
      tmp1 = sr[sr_offset + z + 1] + tmp2;
      sr[sr_offset + z + 1] = tmp2;
    }
}
