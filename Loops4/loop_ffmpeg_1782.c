// Source is: /home/alex/.local/share/compy-Learn/1.0/ffmpeg/content/libavcodec/aacdec_fixed.c

#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;

int
fn (int tags, int i, uint8_t (*layout)[3], int TYPE_CPE, int AAC_CHANNEL_CC,
    int AAC_CHANNEL_OFF)
{
  int sum = 0;
  for (i = 0; i < tags; i++)
    {
      int syn_ele = layout[i][0];
      int pos = layout[i][2];
      sum += (1 + (syn_ele == TYPE_CPE)) * (pos != AAC_CHANNEL_OFF
					    && pos != AAC_CHANNEL_CC);
}}
