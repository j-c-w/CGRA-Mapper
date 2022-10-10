#include <stdint.h>
#include <stdio.h>






int
fn (int column_step, float boundaryscale, float *ptr)
{
  for (int k = 0; k < column_step; k++)
    {
      ptr[k] *= boundaryscale;
}}
