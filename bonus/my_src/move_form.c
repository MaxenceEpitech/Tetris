/*
** move_form.c for move_form in /home/maxence.fourrier/Documents/Project_C/bonus/my_src
** 
** Made by maxence.fourrier
** Login   <maxence.fourrier@epitech.eu>
** 
** Started on  Wed Aug 23 20:37:09 2017 maxence.fourrier
** Last update Wed Aug 23 21:41:21 2017 maxence.fourrier
*/

#include "my.h"

int		check_move(t_all *all)
{
  int		x;
  int		y;

  y = 0;
  while (y < MAP_SIZE_Y - 1)
    {
      x = 0;
      while (x < MAP_SIZE_X)
	{
	  if (all->game->map[y][x] == 'c'
	      && all->game->map[y + 1][x] != '9'
	      && all->game->map[y + 1][x] != 'c')
	    return (1);
	  x++;
	}
      y++;
    }
  x = 0;
  while (x < MAP_SIZE_X)
    {
      if (all->game->map[y][x] == 'c')
	return (1);
      x++;
    }
  return (SUCCESS);
}

void		move_form(t_all *all)
{
  int		x;
  int		y;

  if (check_move(all) == 1)
    return;
  y = MAP_SIZE_Y - 1;
  while (y >= 0)
    {
      x = 0;
      while (x < MAP_SIZE_X)
	{
	  if (all->game->map[y][x] == 'c')
	    {
	      all->game->map[y][x] = '9';
	      all->game->map[y + 1][x] = 'c';
	    }
	  x++;
	}
      y--;
    }
}
