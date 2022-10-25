// Source is: /home/alex/.local/share/compy-Learn/1.0/freeimage/content/Source/LibWebP/src/enc/predictor_enc.c

#include <stdint.h>
#include <stdio.h>






int
fn (int i, const int *counts, double bits, double exp_val,
    const int significant_symbols)
{
  const double exp_decay_factor = 0.6;
  for (i = 1; i < significant_symbols; ++i)
    {
      bits += exp_val * (counts[i] + counts[256 - i]);
      exp_val *= exp_decay_factor;
    }
}
