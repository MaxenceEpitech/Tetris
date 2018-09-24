/*
** rotate_s2.c for rotate_s2.c in /home/maxence.fourrier/Documents/Project_C/bonus/my_src
** 
** Made by maxence.fourrier
** Login   <maxence.fourrier@epitech.eu>
** 
** Started on  Thu Aug 24 00:23:03 2017 maxence.fourrier
** Last update Thu Aug 24 01:04:01 2017 maxence.fourrier
*/

#include "my.h"

void		rotate_2_s1(t_all *all)
{
  int           pos_x;
  int           pos_y;

  get_pos_2_s1(all, &pos_x, &pos_y);
  if (!(pos_y + 2 >= MAP_SIZE_Y
        || all->game->map[pos_y + 1][pos_x] != '9'
        || all->game->map[pos_y + 2][pos_x] != '9'))
    {
      all->game->map[pos_y - 1][pos_x - 1] = '9';
      all->game->map[pos_y][pos_x - 1] = '9';
      all->game->map[pos_y][pos_x + 1] = '9';
      all->game->map[pos_y][pos_x + 2] = '9';
      all->game->map[pos_y - 1][pos_x] = 'c';
      all->game->map[pos_y - 1][pos_x + 1] = 'c';
      all->game->map[pos_y + 1][pos_x] = 'c';
      all->game->map[pos_y + 2][pos_x] = 'c';
      all->game->side = 2;
    }
}

void		rotate_2_s2(t_all *all)
{
  int           pos_x;
  int           pos_y;

  get_pos_2_s2(all, &pos_x, &pos_y);
  if (!(pos_x - 2 < 0
        || all->game->map[pos_y][pos_x - 1] != '9'
        || all->game->map[pos_y][pos_x - 2] != '9'))
    {
      all->game->map[pos_y - 1][pos_x] = '9';
      all->game->map[pos_y - 1][pos_x + 1] = '9';
      all->game->map[pos_y + 1][pos_x] = '9';
      all->game->map[pos_y + 2][pos_x] = '9';
      all->game->map[pos_y][pos_x - 1] = 'c';
      all->game->map[pos_y][pos_x - 2] = 'c';
      all->game->map[pos_y][pos_x + 1] = 'c';
      all->game->map[pos_y + 1][pos_x + 1] = 'c';
      all->game->side = 3;
    }
}

void		rotate_2_s3(t_all *all)
{
  int           pos_x;
  int           pos_y;

  get_pos_2_s3(all, &pos_x, &pos_y);
  if (!(all->game->map[pos_y - 1][pos_x] != '9'
      || all->game->map[pos_y - 1][pos_x - 1] != '9'))
    {
      all->game->map[pos_y][pos_x - 2] = '9';
      all->game->map[pos_y][pos_x - 1] = '9';
      all->game->map[pos_y][pos_x + 1] = '9';
      all->game->map[pos_y + 1][pos_x + 1] = '9';
      all->game->map[pos_y - 2][pos_x] = 'c';
      all->game->map[pos_y - 1][pos_x] = 'c';
      all->game->map[pos_y + 1][pos_x] = 'c';
      all->game->map[pos_y + 1][pos_x - 1] = 'c';
      all->game->side = 4;
    }
}

void		rotate_2_s4(t_all *all)
{
  int           pos_x;
  int           pos_y;

  get_pos_2_s4(all, &pos_x, &pos_y);
  if (!(pos_x + 2 >= MAP_SIZE_X
        || all->game->map[pos_y][pos_x + 1] != '9'
        || all->game->map[pos_y][pos_x + 2] != '9'))
    {
      all->game->map[pos_y - 2][pos_x] = '9';
      all->game->map[pos_y - 1][pos_x] = '9';
      all->game->map[pos_y + 1][pos_x] = '9';
      all->game->map[pos_y + 1][pos_x - 1] = '9';
      all->game->map[pos_y - 1][pos_x - 1] = 'c';
      all->game->map[pos_y][pos_x - 1] = 'c';
      all->game->map[pos_y][pos_x + 1] = 'c';
      all->game->map[pos_y][pos_x + 2] = 'c';
      all->game->side = 1;
    }
}
