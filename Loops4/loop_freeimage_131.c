// Source is: /home/alex/.local/share/compy-Learn/1.0/freeimage/content/Source/LibJPEG/jquant2.c

#include <stdint.h>
#include <stdio.h>






int
fn (int *table, int out, int in)
{
  for (; in < ((255 + 1) / 16) * 3; in++, out += (in & 1) ? 0 : 1)
    {
      table[in] = out;
      table[-in] = -out;
    }
}
