/*
** rotate_3.c for rotate_3 in /home/maxence.fourrier/Documents/Project_C/bonus/my_src
** 
** Made by maxence.fourrier
** Login   <maxence.fourrier@epitech.eu>
** 
** Started on  Thu Aug 24 01:06:46 2017 maxence.fourrier
** Last update Thu Aug 24 02:13:05 2017 maxence.fourrier
*/

#include "my.h"

void		rotate_3_s1(t_all *all)
{
  int		pos_x;
  int		pos_y;

  get_pos_3_s1(all, &pos_x, &pos_y);
  if (pos_y <= 0 || pos_x >= MAP_SIZE_X - 1 || pos_y >= MAP_SIZE_Y - 1)
    return;
  if (all->game->map[pos_y][pos_x + 1] == '9'
      && all->game->map[pos_y - 1][pos_x + 1] == '9')
    {
      all->game->map[pos_y][pos_x - 1] = '9';
      all->game->map[pos_y + 1][pos_x + 1] = '9';
      all->game->map[pos_y][pos_x + 1] = 'c';
      all->game->map[pos_y - 1][pos_x + 1] = 'c';
      all->game->side = 2;
    }
}

void		rotate_3_s2(t_all *all)
{
  int		pos_x;
  int		pos_y;

  get_pos_3_s2(all, &pos_x, &pos_y);
  if (pos_x == 0 || pos_x >= MAP_SIZE_X - 1 || pos_y >= MAP_SIZE_Y - 1)
    return;
  if (all->game->map[pos_y][pos_x - 1] == '9'
      && all->game->map[pos_y + 1][pos_x + 1] == '9')
    {
      all->game->map[pos_y][pos_x + 1] = '9';
      all->game->map[pos_y - 1][pos_x + 1] = '9';
      all->game->map[pos_y][pos_x - 1] = 'c';
      all->game->map[pos_y + 1][pos_x + 1] = 'c';
      all->game->side = 1;
    }
}
