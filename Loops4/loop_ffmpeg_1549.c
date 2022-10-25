// Source is: /home/alex/.local/share/compy-Learn/1.0/ffmpeg/content/libavcodec/targa.c

#include <stdint.h>
#include <stdio.h>






int
fn (int x, int w, int bpp, void *line)
{
  for (x = 0; x < w >> 1; x++)
    {
      switch (bpp)
	{
	case 32:
	  do
	    {
	      uint32_t SWAP_tmp = ((uint32_t *) line)[w - x - 1];
	      ((uint32_t *) line)[w - x - 1] = ((uint32_t *) line)[x];
	      ((uint32_t *) line)[x] = SWAP_tmp;
	    }
	  while (0);
	  break;
	case 24:
	  do
	    {
	      uint8_t SWAP_tmp = ((uint8_t *) line)[3 * w - 3 * x - 3];
	      ((uint8_t *) line)[3 * w - 3 * x - 3] =
		((uint8_t *) line)[3 * x];
	      ((uint8_t *) line)[3 * x] = SWAP_tmp;
	    }
	  while (0);
	  do
	    {
	      uint8_t SWAP_tmp = ((uint8_t *) line)[3 * w - 3 * x - 2];
	      ((uint8_t *) line)[3 * w - 3 * x - 2] =
		((uint8_t *) line)[3 * x + 1];
	      ((uint8_t *) line)[3 * x + 1] = SWAP_tmp;
	    }
	  while (0);
	  do
	    {
	      uint8_t SWAP_tmp = ((uint8_t *) line)[3 * w - 3 * x - 1];
	      ((uint8_t *) line)[3 * w - 3 * x - 1] =
		((uint8_t *) line)[3 * x + 2];
	      ((uint8_t *) line)[3 * x + 2] = SWAP_tmp;
	    }
	  while (0);
	  break;
	case 16:
	  do
	    {
	      uint16_t SWAP_tmp = ((uint16_t *) line)[w - x - 1];
	      ((uint16_t *) line)[w - x - 1] = ((uint16_t *) line)[x];
	      ((uint16_t *) line)[x] = SWAP_tmp;
	    }
	  while (0);
	  break;
	case 8:
	  do
	    {
	      uint8_t SWAP_tmp = ((uint8_t *) line)[w - x - 1];
	      ((uint8_t *) line)[w - x - 1] = ((uint8_t *) line)[x];
	      ((uint8_t *) line)[x] = SWAP_tmp;
	    }
	  while (0);
	}
    }
}
