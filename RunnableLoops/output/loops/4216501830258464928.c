#include <stdint.h>
#include <stdio.h>






int
fn (const uint8_t * channel_buffer[4], int rgb_channel_count,
    const uint8_t * rgb[3], int c)
{
  for (c = 0; c < rgb_channel_count; c++)
    {
      rgb[c] = channel_buffer[c];
    }
}
