#include <stdint.h>
#include <stdio.h>






int
fn (double *matrix, int size, double *vector)
{
  int i = 0;
  for (int j = i + 1; j < size; j++)
    {
      double d = matrix[j + i * size];
      vector[j] -= d * vector[i];
}}
