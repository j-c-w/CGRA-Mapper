// Source is: /home/alex/.local/share/compy-Learn/1.0/bzip2/content/blocksort.c

#include <stdint.h>
#include <stdio.h>




typedef int Int32;
typedef unsigned char Bool;

int
fn (Bool bigDone[256], Int32 i, Int32 runningOrder[256])
{
  for (i = 0; i <= 255; i++)
    {
      bigDone[i] = ((Bool) 0);
      runningOrder[i] = i;
    }
}
