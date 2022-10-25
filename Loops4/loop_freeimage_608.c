// Source is: /home/alex/.local/share/compy-Learn/1.0/freeimage/content/Source/LibWebP/src/utils/bit_reader_utils.c

#include <stdint.h>
#include <stdio.h>




typedef long unsigned int size_t;
typedef __uint8_t uint8_t;
typedef uint64_t vp8l_val_t;

int
fn (size_t length, const uint8_t * const start, vp8l_val_t value, size_t i)
{
  for (i = 0; i < length; ++i)
    {
      value |= (vp8l_val_t) start[i] << (8 * i);
    }
}
