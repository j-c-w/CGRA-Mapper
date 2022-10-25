// Source is: /home/alex/.local/share/compy-Learn/1.0/DarkNet/content/./examples/go.c

#include <stdint.h>
#include <stdio.h>






int
fn (int i, float *board)
{
  for (i = 0; i < 19 * 19; ++i)
    {
      float swap = board[i];
      board[i] = board[i + 19 * 19];
      board[i + 19 * 19] = swap;
      board[i + 19 * 19 * 2] = 1 - board[i + 19 * 19 * 2];
}}
