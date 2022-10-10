#include <stdint.h>
#include <stdio.h>






int
fn (int *deltas, int i, int *last, int j, int *data, unsigned int *CD)
{
  for (i = 0; i < 2; i++)
    {
      CD[j] += deltas[i + j * 2];
      last[i] += CD[j];
      data[i] = last[i];
    }
}
