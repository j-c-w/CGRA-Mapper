#include <stdint.h>
#include <stdio.h>






int
fn (int j, double d, double *array, int size)
{
  int i = 0;
  for (int k = i + 1; k < size; k++)
    {
      array[j + k * size] -= d * array[i + k * size];
}}
