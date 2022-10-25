// Source is: /home/alex/.local/share/compy-Learn/1.0/freeimage/content/Source/LibOpenJPEG/invert.c

#include <stdint.h>
#include <stdio.h>




typedef float OPJ_FLOAT32;
typedef uint32_t OPJ_UINT32;

int
fn (OPJ_FLOAT32 * p_dest_temp, OPJ_UINT32 i, OPJ_UINT32 nb_compo,
    OPJ_FLOAT32 * lCurrentPtr)
{
  for (i = 0; i < nb_compo; ++i)
    {
      *(lCurrentPtr) = p_dest_temp[i];
      lCurrentPtr += nb_compo;
    }
}
