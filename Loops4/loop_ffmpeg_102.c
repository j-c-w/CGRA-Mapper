// Source is: /home/alex/.local/share/compy-Learn/1.0/ffmpeg/content/libavcodec/dss_sp.c

#include <stdint.h>
#include <stdio.h>






int
fn (const uint32_t dss_sp_combinatorial_table[8][72], int pulse_idx,
    int pulse, unsigned int combined_pulse_pos)
{
  for (; combined_pulse_pos < dss_sp_combinatorial_table[pulse][pulse_idx];
       --pulse_idx);
}
