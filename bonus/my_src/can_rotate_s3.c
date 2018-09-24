/*
** can_rotate_s3.c for can_rotate_s3.c in /home/maxence.fourrier/Documents/Project_C/bonus/my_src
** 
** Made by maxence.fourrier
** Login   <maxence.fourrier@epitech.eu>
** 
** Started on  Thu Aug 24 01:08:07 2017 maxence.fourrier
** Last update Thu Aug 24 01:28:48 2017 maxence.fourrier
*/

#include "my.h"

void		get_pos_3_s1(t_all *all, int *pos_x, int *pos_y)
{
  int		y;
  int		x;

  y = 0;
  while (y < MAP_SIZE_Y)
    {
      x = 0;
      while (x < MAP_SIZE_X)
        {
          if (all->game->map[y][x] == 'c')
            {
              *pos_x = x + 1;
              *pos_y = y;
              return;
            }
          x++;
        }
      y++;
    }
}

void		get_pos_3_s2(t_all *all, int *pos_x, int *pos_y)
{
  int		y;
  int		x;

  y = 0;
  while (y < MAP_SIZE_Y)
    {
      x = 0;
      while (x < MAP_SIZE_X)
        {
          if (all->game->map[y][x] == 'c')
            {
              *pos_x = x - 1;
              *pos_y = y + 1;
              return;
            }
          x++;
        }
      y++;
    }
}
