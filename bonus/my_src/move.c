/*
** move.c for move in /home/maxence.fourrier/Documents/Project_C/bonus/my_src
** 
** Made by maxence.fourrier
** Login   <maxence.fourrier@epitech.eu>
** 
** Started on  Wed Aug 23 22:41:32 2017 maxence.fourrier
** Last update Thu Aug 24 12:27:54 2017 maxence.fourrier
*/

#include "my.h"

void		move_right(t_all *all)
{
  int		x;
  int		y;

  y = 0;
  while (y < MAP_SIZE_Y)
    {
      x = MAP_SIZE_X - 1;
      while (x >= 0)
	{
	  if (all->game->map[y][x] == 'c')
	    {
	      all->game->map[y][x] = '9';
	      all->game->map[y][x + 1] = 'c';
	    }
	  x--;
	}
      y++;
    }
}

void		move_left(t_all *all)
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
	    {
	      all->game->map[y][x] = '9';
	      all->game->map[y][x - 1] = 'c';
	    }
	  x++;
	}
      y++;
    }
}

void		move_down(t_all *all)
{
  int		x;
  int		y;

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
  if (all->game->power < 100)
    all->game->power++;
  if (can_move_down(all) == SUCCESS)
    {
      replace_current(all);
      generate_form(all);
    }
}
