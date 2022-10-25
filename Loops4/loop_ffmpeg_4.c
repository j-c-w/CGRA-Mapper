// Source is: /home/alex/.local/share/compy-Learn/1.0/ffmpeg/content/libavcodec/aacps_float.c

#include <stdint.h>
#include <stdio.h>




typedef float INTFLOAT;

int
fn (int i, INTFLOAT (*transient_gain)[32], INTFLOAT * power_smooth,
    INTFLOAT (*power)[32], int n0, int n, INTFLOAT * peak_decay_nrg,
    INTFLOAT * peak_decay_diff_smooth, const INTFLOAT peak_decay_factor)
{
  const float a_smooth = 0.25f;
  const float transient_impact = 1.5f;
  int nL = 0;
  for (n = n0; n < nL; n++)
    {
      float decayed_peak = peak_decay_factor * peak_decay_nrg[i];
      float denom;
      peak_decay_nrg[i] =
	((decayed_peak) > (power[i][n]) ? (decayed_peak) : (power[i][n]));
      power_smooth[i] += a_smooth * (power[i][n] - power_smooth[i]);
      peak_decay_diff_smooth[i] +=
	a_smooth * (peak_decay_nrg[i] - power[i][n] -
		    peak_decay_diff_smooth[i]);
      denom = transient_impact * peak_decay_diff_smooth[i];
      transient_gain[i][n] =
	(denom > power_smooth[i]) ? power_smooth[i] / denom : 1.0f;
}}
