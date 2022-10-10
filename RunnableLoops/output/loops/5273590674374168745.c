#include <stdint.h>
#include <stdio.h>






int
fn (int x, int filter_limit, int value, int *bounding_values)
{
  for (x = value = filter_limit; x < 128 && value; x++, value--)
    {
      bounding_values[x] = value;
      bounding_values[-x] = -value;
    }
}
