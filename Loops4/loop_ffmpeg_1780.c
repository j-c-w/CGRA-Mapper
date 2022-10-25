// Source is: /home/alex/.local/share/compy-Learn/1.0/ffmpeg/content/libavcodec/me_cmp.c

#include <stdint.h>
#include <stdio.h>






int
fn (int temp[64], int i)
{
  int sum = 0;
  for (i = 0; i < 8; i++)
    {
      {
	int a, b;
	a = temp[8 * 0 + i];
	b = temp[8 * 1 + i];
	temp[8 * 0 + i] = a + b;
	temp[8 * 1 + i] = a - b;
      };
      {
	int a, b;
	a = temp[8 * 2 + i];
	b = temp[8 * 3 + i];
	temp[8 * 2 + i] = a + b;
	temp[8 * 3 + i] = a - b;
      };
      {
	int a, b;
	a = temp[8 * 4 + i];
	b = temp[8 * 5 + i];
	temp[8 * 4 + i] = a + b;
	temp[8 * 5 + i] = a - b;
      };
      {
	int a, b;
	a = temp[8 * 6 + i];
	b = temp[8 * 7 + i];
	temp[8 * 6 + i] = a + b;
	temp[8 * 7 + i] = a - b;
      };
      {
	int a, b;
	a = temp[8 * 0 + i];
	b = temp[8 * 2 + i];
	temp[8 * 0 + i] = a + b;
	temp[8 * 2 + i] = a - b;
      };
      {
	int a, b;
	a = temp[8 * 1 + i];
	b = temp[8 * 3 + i];
	temp[8 * 1 + i] = a + b;
	temp[8 * 3 + i] = a - b;
      };
      {
	int a, b;
	a = temp[8 * 4 + i];
	b = temp[8 * 6 + i];
	temp[8 * 4 + i] = a + b;
	temp[8 * 6 + i] = a - b;
      };
      {
	int a, b;
	a = temp[8 * 5 + i];
	b = temp[8 * 7 + i];
	temp[8 * 5 + i] = a + b;
	temp[8 * 7 + i] = a - b;
      };
      sum +=
	((((temp[8 * 0 + i]) + (temp[8 * 4 + i])) >=
	  0 ? ((temp[8 * 0 + i]) +
	       (temp[8 * 4 + i])) : (-((temp[8 * 0 + i]) +
				       (temp[8 * 4 + i])))) + (((temp[8 * 0 +
								      i]) -
								(temp
								 [8 * 4 +
								  i])) >=
							       0
							       ? ((temp
								   [8 * 0 +
								    i]) -
								  (temp
								   [8 * 4 +
								    i]))
							       : (-
								  ((temp
								    [8 * 0 +
								     i]) -
								   (temp
								    [8 * 4 +
								     i]))))) +
	((((temp[8 * 1 + i]) + (temp[8 * 5 + i])) >=
	  0 ? ((temp[8 * 1 + i]) +
	       (temp[8 * 5 + i])) : (-((temp[8 * 1 + i]) +
				       (temp[8 * 5 + i])))) + (((temp[8 * 1 +
								      i]) -
								(temp
								 [8 * 5 +
								  i])) >=
							       0
							       ? ((temp
								   [8 * 1 +
								    i]) -
								  (temp
								   [8 * 5 +
								    i]))
							       : (-
								  ((temp
								    [8 * 1 +
								     i]) -
								   (temp
								    [8 * 5 +
								     i]))))) +
	((((temp[8 * 2 + i]) + (temp[8 * 6 + i])) >=
	  0 ? ((temp[8 * 2 + i]) +
	       (temp[8 * 6 + i])) : (-((temp[8 * 2 + i]) +
				       (temp[8 * 6 + i])))) + (((temp[8 * 2 +
								      i]) -
								(temp
								 [8 * 6 +
								  i])) >=
							       0
							       ? ((temp
								   [8 * 2 +
								    i]) -
								  (temp
								   [8 * 6 +
								    i]))
							       : (-
								  ((temp
								    [8 * 2 +
								     i]) -
								   (temp
								    [8 * 6 +
								     i]))))) +
	((((temp[8 * 3 + i]) + (temp[8 * 7 + i])) >=
	  0 ? ((temp[8 * 3 + i]) +
	       (temp[8 * 7 + i])) : (-((temp[8 * 3 + i]) +
				       (temp[8 * 7 + i])))) + (((temp[8 * 3 +
								      i]) -
								(temp
								 [8 * 7 +
								  i])) >=
							       0
							       ? ((temp
								   [8 * 3 +
								    i]) -
								  (temp
								   [8 * 7 +
								    i]))
							       : (-
								  ((temp
								    [8 * 3 +
								     i]) -
								   (temp
								    [8 * 7 +
								     i])))));
}}
