// Source is: /home/alex/.local/share/compy-Learn/1.0/bzip2/content/huffman.c

#include <stdint.h>
#include <stdio.h>




typedef int Int32;

int
fn (Int32 alphaSize, Int32 heap[260], Int32 nHeap, Int32 i, Int32 weight[516],
    Int32 parent[516])
{
  for (i = 1; i <= alphaSize; i++)
    {
      parent[i] = -1;
      nHeap++;
      heap[nHeap] = i;
      {
	Int32 zz, tmp;
	zz = nHeap;
	tmp = heap[zz];
	while (weight[tmp] < weight[heap[zz >> 1]])
	  {
	    heap[zz] = heap[zz >> 1];
	    zz >>= 1;
	  }
	heap[zz] = tmp;
      };
    }
}
