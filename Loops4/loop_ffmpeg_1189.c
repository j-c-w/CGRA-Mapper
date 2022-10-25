// Source is: /home/alex/.local/share/compy-Learn/1.0/ffmpeg/content/libavfilter/vf_nlmeans.c

#include <stdint.h>
#include <stdio.h>




typedef __uint32_t uint32_t;
typedef __uint8_t uint8_t;

int
fn (const float *const weight_lut, const uint32_t * const iib, int endx,
    const uint32_t * const iie, const uint8_t * const src, float *sum,
    const uint32_t * const iid, const uint32_t * const iia,
    float *total_weight, int max_meaningful_diff, int startx)
{
  for (int x = startx; x < endx; x++)
    {
      const uint32_t a = iia[x];
      const uint32_t b = iib[x];
      const uint32_t d = iid[x];
      const uint32_t e = iie[x];
      const uint32_t patch_diff_sq =
	((e - d - b + a) >
	 (max_meaningful_diff) ? (max_meaningful_diff) : (e - d - b + a));
      const float weight = weight_lut[patch_diff_sq];
      total_weight[x] += weight;
      sum[x] += weight * src[x];
}}
