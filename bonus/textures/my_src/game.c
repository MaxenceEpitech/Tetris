/*
** game.c for game in /home/maxence.fourrier/Documents/Project_C/bonus/my_src
** 
** Made by maxence.fourrier
** Login   <maxence.fourrier@epitech.eu>
** 
** Started on  Fri Aug  4 19:17:45 2017 maxence.fourrier
** Last update Mon Aug  7 19:24:40 2017 maxence.fourrier
*/

#include "my.h"

int		game(t_all *all)
{
  if (all->game->pos.y + (all->game->level * SPEED) < MAP_SIZE_Y
      && all->game->map[all->game->pos.y + (SPEED * all->game->level)]
      [all->game->pos.x] == '9')
    {
      all->game->pos.y += (SPEED * all->game->level);
      draw_actual(all);
    }
  else
    {
      all->game->map[all->game->pos.y]
	[all->game->pos.x] = all->game->color + '0';
      all->game->pos.x = MAP_SIZE_X / 2;
      all->game->pos.y = 0;
    }
  return (0);
}
