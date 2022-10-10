#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;

int
fn (float *ref_ptr_data, float *main_ptr_data, const uint8_t * ref_ptr,
    const float factor, int w, const uint8_t * main_ptr)
{
  for (int j = 0; j < w; j++)
    {
      ref_ptr_data[j] = ref_ptr[j] * factor - 128.f;
      main_ptr_data[j] = main_ptr[j] * factor - 128.f;
}}
