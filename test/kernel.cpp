// Source is: /home/alex/.local/share/compy-Learn/1.0/libav/content/libavcodec/apedec.c

#include <stdint.h>
#include <stdio.h>


typedef __uint16_t uint16_t;

int
fn (int cf, int symbol, const uint16_t * counts)
{
  for (symbol = 0; counts[symbol + 1] <= cf; symbol++);
}
