// Source is: /home/alex/.local/share/compy-Learn/1.0/ffmpeg/content/libavcodec/ffv1enc.c

#include <stdint.h>
#include <stdio.h>






int
fn (int i, int bb, int bg, const int rct_y_coeff[15][2], int br, int stat[15])
{
  for (i = 0; i < 15; i++)
    {
      stat[i] +=
	((bg + ((br * rct_y_coeff[i][0] + bb * rct_y_coeff[i][1]) >> 2)) >=
	 0 ? (bg +
	      ((br * rct_y_coeff[i][0] +
		bb * rct_y_coeff[i][1]) >> 2)) : (-(bg +
						    ((br * rct_y_coeff[i][0] +
						      bb *
						      rct_y_coeff[i][1]) >>
						     2))));
    }
}
