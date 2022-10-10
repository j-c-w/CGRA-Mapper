#include <stdint.h>
#include <stdio.h>






int
fn (int width, double sqr_diff, float *img_metrics)
{
  double mean = 0.0;
  int j = 0;
  for (int i = 0; i < width; i++)
    {
      float mean_diff = img_metrics[j * width + i] - mean;
      sqr_diff += (mean_diff * mean_diff);
}}
