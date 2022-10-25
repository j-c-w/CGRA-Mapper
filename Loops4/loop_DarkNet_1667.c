// Source is: /home/alex/.local/share/compy-Learn/1.0/DarkNet/content/./src/parser.c

#include <stdint.h>
#include <stdio.h>






int
fn (int cols, float *a, int x, int y, float *transpose, int rows)
{
  for (y = 0; y < cols; ++y)
    {
      transpose[y * rows + x] = a[x * cols + y];
    }
}
