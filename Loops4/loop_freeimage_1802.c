// Source is: /home/alex/.local/share/compy-Learn/1.0/freeimage/content/Source/LibWebP/src/enc/backward_references_enc.c

#include <stdint.h>
#include <stdio.h>






int
fn (int j, int window_offsets[32], int i)
{
  int window_offsets_size = 0;
  int is_reachable = 0;
  for (j = 0; j < window_offsets_size && !is_reachable; ++j)
    {
      is_reachable |= (window_offsets[i] == window_offsets[j] + 1);
    }
}
