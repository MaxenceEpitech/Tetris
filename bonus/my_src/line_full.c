/*
** line_full.c for line_full in /home/maxence.fourrier/Documents/Project_C/bonus/my_src
** 
** Made by maxence.fourrier
** Login   <maxence.fourrier@epitech.eu>
** 
** Started on  Wed Aug 23 23:20:34 2017 maxence.fourrier
** Last update Thu Aug 24 10:23:13 2017 maxence.fourrier
*/

#include "my.h"

int		is_line_full(t_all *all)
{
  int		y;
  int		x;
  int		full;

  y = 0;
  while (y < MAP_SIZE_Y)
    {
      x = 0;
      full = 0;
      while (x < MAP_SIZE_X)
	{
	  if (all->game->map[y][x] == '9'
	      || all->game->map[y][x] == 'c')
	    full = 1;
	  x++;
	}
      if (full == 0)
	return (y);
      y++;
    }
  return (-1);
}

void		move_map_down(t_all *all, int line)
{
  int		y;
  int		x;

  y = line;
  while (y > 0)
    {
      x = 0;
      while (x < MAP_SIZE_X)
	{
	  all->game->map[y][x] = all->game->map[y - 1][x];
	  x++;
	}
      y--;
    }
}

int		get_score(char *str)
{
  int		ret;
  int		i;

  i = 0;
  ret = 0;
  while (str[i])
    {
      ret += (str[i] * 2);
      i++;
    }
  return (ret);
}

void		line_full(t_all *all)
{
  int		line;

  while ((line = is_line_full(all)) != -1)
    {
      all->game->score += get_score(all->game->map[line]);
      move_map_down(all, line);
    }
}
