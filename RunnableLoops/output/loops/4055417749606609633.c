#include <stdint.h>
#include <stdio.h>






int
fn (int n, double *A, int m)
{
  int k = 0;
  for (int i = k + 1; i < n; i++)
    {
      double t2 = A[i + n * m];
      A[i + n * m] = A[i + n * k];
      A[i + n * k] = t2;
}}
