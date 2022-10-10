#include <stdint.h>
#include <stdio.h>






int
fn (int i, int dstW, int *filterPos)
{
  for (i = 0; i + 8 <= dstW; i += 8)
    {
      do
	{
	  int SWAP_tmp = filterPos[i + 4];
	  filterPos[i + 4] = filterPos[i + 2];
	  filterPos[i + 2] = SWAP_tmp;
	}
      while (0);
      do
	{
	  int SWAP_tmp = filterPos[i + 5];
	  filterPos[i + 5] = filterPos[i + 3];
	  filterPos[i + 3] = SWAP_tmp;
	}
      while (0);
    }
}
