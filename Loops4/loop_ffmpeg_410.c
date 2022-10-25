// Source is: /home/alex/.local/share/compy-Learn/1.0/ffmpeg/content/libavcodec/bink.c

#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;

int
fn (int32_t binkb_inter_quant[16][64], int i, uint8_t inv_bink_scan[64],
    const uint8_t binkb_num[16], int32_t binkb_intra_quant[16][64],
    const uint8_t binkb_intra_seed[64], const uint8_t binkb_inter_seed[64],
    const int s[64], int j, const uint8_t binkb_den[16])
{
  for (i = 0; i < 64; i++)
    {
      int k = inv_bink_scan[i];
      binkb_intra_quant[j][k] =
	binkb_intra_seed[i] * (int64_t) s[i] * binkb_num[j] / (binkb_den[j] *
							       ((1LL << 30) >>
								12));
      binkb_inter_quant[j][k] =
	binkb_inter_seed[i] * (int64_t) s[i] * binkb_num[j] / (binkb_den[j] *
							       ((1LL << 30) >>
								12));
}}
