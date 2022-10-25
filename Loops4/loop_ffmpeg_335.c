// Source is: /home/alex/.local/share/compy-Learn/1.0/ffmpeg/content/libavcodec/eac3enc.c

#include <stdint.h>
#include <stdio.h>






int
fn (int i, const uint8_t ff_eac3_frm_expstr[32][6],
    int8_t eac3_frame_expstr_index_tab[3][4][4][4][4][4])
{
  for (i = 0; i < 32; i++)
    {
      eac3_frame_expstr_index_tab[ff_eac3_frm_expstr[i][0] -
				  1][ff_eac3_frm_expstr[i][1]]
	[ff_eac3_frm_expstr[i][2]][ff_eac3_frm_expstr[i][3]]
	[ff_eac3_frm_expstr[i][4]][ff_eac3_frm_expstr[i][5]] = i;
    }
}
