/*
** can_move.c for can_move in /home/maxence.fourrier/Documents/Project_C/bonus/my_src
** 
** Made by maxence.fourrier
** Login   <maxence.fourrier@epitech.eu>
** 
** Started on  Wed Aug 23 22:04:46 2017 maxence.fourrier
** Last update Wed Aug 23 22:55:16 2017 maxence.fourrier
*/

#include "my.h"

int		can_move_right(t_all *all)
{
  int		x;
  int		y;

  y = 0;
  while (y < MAP_SIZE_Y)
    {
      x = 0;
      while (x < MAP_SIZE_X - 1)
	{
	  if (all->game->map[y][x] == 'c'
	      && (all->game->map[y][x + 1] != '9'
		  && all->game->map[y][x + 1] != 'c'))
	    return (SUCCESS);
	  x++;
	}
      y++;
    }
  y = 0;
  while (y < MAP_SIZE_Y)
    {
      if (all->game->map[y][MAP_SIZE_X - 1] == 'c')
	return (SUCCESS);
      y++;
    }
  return (1);
}

int		can_move_left(t_all *all)
{  
  int		x;
  int		y;

  y = 0;
  while (y < MAP_SIZE_Y)
    {
      x = 1;
      while (x < MAP_SIZE_X)
	{
	  if (all->game->map[y][x] == 'c'
	      && (all->game->map[y][x - 1] != '9'
		  && all->game->map[y][x - 1] != 'c'))
	    return (SUCCESS);
	  x++;
	}
      y++;
    }
  y = 0;
  while (y < MAP_SIZE_Y)
    {
      if (all->game->map[y][0] == 'c')
	return (SUCCESS);
      y++;
    }
  return (1);
}

int		can_move_down(t_all *all)
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
	      && (all->game->map[y + 1][x] != '9'
		  && all->game->map[y + 1][x] != 'c'))
	    return (SUCCESS);
	  x++;
	}
      y++;
    }
  x = 0;
  while (x < MAP_SIZE_X)
    {
      if (all->game->map[MAP_SIZE_Y - 1][x] == 'c')
	return (SUCCESS);
      x++;
    }
  return (1);
}
