// Source is: /home/alex/.local/share/compy-Learn/1.0/ffmpeg/content/libavfilter/vf_vif.c

#include <stdint.h>
#include <stdio.h>




typedef __uint16_t uint16_t;

int
fn (int w, float *main_ptr_data, const float factor,
    const uint16_t * main_ptr, float *ref_ptr_data, const uint16_t * ref_ptr)
{
  for (int j = 0; j < w; j++)
    {
      ref_ptr_data[j] = ref_ptr[j] * factor - 128.f;
      main_ptr_data[j] = main_ptr[j] * factor - 128.f;
}}
