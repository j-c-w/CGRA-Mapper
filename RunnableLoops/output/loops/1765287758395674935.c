#include <stdint.h>
#include <stdio.h>






int
fn (int m, double *A, int n)
{
  int k = 0;
  for (int i = k + 1; i < n; i++)
    {
      double t2 = A[i + n * m];
      A[i + n * m] = A[i + n * k];
      A[i + n * k] = t2;
}}
