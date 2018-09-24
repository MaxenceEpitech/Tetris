/*
** can_rotate_s2.c for can_rotate_s2 in /home/maxence.fourrier/Documents/Project_C/bonus/my_src
** 
** Made by maxence.fourrier
** Login   <maxence.fourrier@epitech.eu>
** 
** Started on  Thu Aug 24 00:22:28 2017 maxence.fourrier
** Last update Thu Aug 24 00:27:05 2017 maxence.fourrier
*/

#include "my.h"

void		get_pos_2_s1(t_all *all, int *pos_x, int *pos_y)
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
              *pos_y = y + 1;
              return;
            }
          x++;
        }
      y++;
    }
}

void		get_pos_2_s2(t_all *all, int *pos_x, int *pos_y)
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
              *pos_x = x;
              *pos_y = y + 1;
              return;
            }
          x++;
        }
      y++;
    }
}

void		get_pos_2_s3(t_all *all, int *pos_x, int *pos_y)
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
              *pos_x = x + 2;
              *pos_y = y;
              return;
            }
          x++;
        }
      y++;
    }
}

void		get_pos_2_s4(t_all *all, int *pos_x, int *pos_y)
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
              *pos_x = x;
              *pos_y = y + 2;
              return;
            }
          x++;
        }
      y++;
    }
}
