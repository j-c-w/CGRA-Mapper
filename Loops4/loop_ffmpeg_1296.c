// Source is: /home/alex/.local/share/compy-Learn/1.0/ffmpeg/content/libavcodec/error_resilience.c

#include <stdint.h>
#include <stdio.h>






int
fn (int min_x, int mv_predictor[8][2], int max_x, int ref[8], int pred_count,
    int min_y, int max_r, int j, int max_y, int min_r)
{
  for (j = 0; j < pred_count; j++)
    {
      max_x =
	((max_x) > (mv_predictor[j][0]) ? (max_x) : (mv_predictor[j][0]));
      max_y =
	((max_y) > (mv_predictor[j][1]) ? (max_y) : (mv_predictor[j][1]));
      max_r = ((max_r) > (ref[j]) ? (max_r) : (ref[j]));
      min_x =
	((min_x) > (mv_predictor[j][0]) ? (mv_predictor[j][0]) : (min_x));
      min_y =
	((min_y) > (mv_predictor[j][1]) ? (mv_predictor[j][1]) : (min_y));
      min_r = ((min_r) > (ref[j]) ? (ref[j]) : (min_r));
    }
}
