// Source is: /home/alex/.local/share/compy-Learn/1.0/freeimage/content/Source/LibJPEG/jchuff.c

#include <stdint.h>
#include <stdio.h>




typedef unsigned char UINT8;

int
fn (UINT8 bits[33], int j, int i)
{
  for (i = 32; i > 16; i--)
    {
      while (bits[i] > 0)
	{
	  j = i - 2;
	  while (bits[j] == 0)
	    j--;
	  bits[i] -= 2;
	  bits[i - 1]++;
	  bits[j + 1] += 2;
	  bits[j]--;
	}
    }
}
