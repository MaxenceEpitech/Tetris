/*
** rotate.c for rotate.c in /home/maxence.fourrier/Documents/Project_C/bonus/my_src
** 
** Made by maxence.fourrier
** Login   <maxence.fourrier@epitech.eu>
** 
** Started on  Wed Aug 23 23:47:36 2017 maxence.fourrier
** Last update Thu Aug 24 01:16:07 2017 maxence.fourrier
*/

#include "my.h"

void		rotate_0_s1(t_all *all)
{
  int		pos_x;
  int		pos_y;

  get_pos_0_s1(all, &pos_x, &pos_y);
  if (!(pos_y + 2 >= MAP_SIZE_Y
	|| all->game->map[pos_y - 1][pos_x] != '9'
	|| all->game->map[pos_y + 1][pos_x] != '9'
	|| all->game->map[pos_y + 2][pos_x] != '9'))
    {
      all->game->map[pos_y - 1][pos_x] = 'c';
      all->game->map[pos_y + 1][pos_x] = 'c';
      all->game->map[pos_y + 2][pos_x] = 'c';
      all->game->map[pos_y][pos_x - 1] = '9';
      all->game->map[pos_y][pos_x + 1] = '9';
      all->game->map[pos_y][pos_x + 2] = '9';
      all->game->side = 2;
    }
}

void		rotate_0_s2(t_all *all)
{
  int		pos_x;
  int		pos_y;

  get_pos_0_s2(all, &pos_x, &pos_y);
  if (!(pos_x + 2 >= MAP_SIZE_X
	|| pos_x - 1 < 0
	|| all->game->map[pos_y][pos_x - 1] != '9'
	|| all->game->map[pos_y][pos_x + 1] != '9'
	|| all->game->map[pos_y][pos_x + 2] != '9'))
    {
      all->game->map[pos_y - 1][pos_x] = '9';
      all->game->map[pos_y + 1][pos_x] = '9';
      all->game->map[pos_y + 2][pos_x] = '9';
      all->game->map[pos_y][pos_x - 1] = 'c';
      all->game->map[pos_y][pos_x + 1] = 'c';
      all->game->map[pos_y][pos_x + 2] = 'c';
      all->game->side = 1;
    }
}

void		rotate_current(t_all *all)
{
  if (all->game->color == 0 && all->game->side == 1)
    rotate_0_s1(all);
  else if (all->game->color == 0 && all->game->side == 2)
    rotate_0_s2(all);
  else if (all->game->color == 2 && all->game->side == 1)
    rotate_2_s1(all);
  else if (all->game->color == 2 && all->game->side == 2)
    rotate_2_s2(all);
  else if (all->game->color == 2 && all->game->side == 3)
    rotate_2_s3(all);
  else if (all->game->color == 2 && all->game->side == 4)
    rotate_2_s4(all);
  else if (all->game->color == 3 && all->game->side == 1)
    rotate_3_s1(all);
  else if (all->game->color == 3 && all->game->side == 2)
    rotate_3_s2(all);
}
