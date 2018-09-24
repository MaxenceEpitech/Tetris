/*
** game.c for game in /home/maxence.fourrier/Documents/Project_C/bonus/my_src
** 
** Made by maxence.fourrier
** Login   <maxence.fourrier@epitech.eu>
** 
** Started on  Fri Aug  4 19:17:45 2017 maxence.fourrier
** Last update Thu Aug 24 00:33:58 2017 maxence.fourrier
*/

#include "my.h"

void		replace_current(t_all *all)
{
  int		x;
  int		y;

  y = 0;
  while (y < MAP_SIZE_Y)
    {
      x = 0;
      while (x < MAP_SIZE_X)
	{
	  if (all->game->map[y][x] == 'c')
	    all->game->map[y][x] = all->game->color + '0';
	  x++;
	}
      y++;
    }
}

int		game(t_all *all)
{
  int		x;

  x = 0;
  move_form(all);
  if (check_move(all) == 1)
    {
      replace_current(all);
      while (x < MAP_SIZE_X)
	{
	  if (all->game->map[1][x] != '9')
	    return (SUCCESS);
	  x++;
	}
      generate_form(all);
    }
  return (SUCCESS);
}
