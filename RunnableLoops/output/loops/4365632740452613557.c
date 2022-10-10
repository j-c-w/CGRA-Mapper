#include <stdint.h>
#include <stdio.h>






int
fn (char *buffer, int len, int *lenp, const char *in)
{
  for (len = 0; len < 128; len++)
    {
      const char c = *in++;
      switch (c)
	{
	case '\0':
	  return 0;
	case '<':
	  return 0;
	case '>':
	  buffer[len] = '\0';
	  *lenp = len + 1;
	  return 1;
	default:
	  break;
	}
      buffer[len] = c;
    }
}
