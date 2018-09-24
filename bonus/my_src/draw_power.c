/*
** draw_power.c for draw_power in /home/maxence.fourrier/Documents/Project_C/bonus/my_src
** 
** Made by maxence.fourrier
** Login   <maxence.fourrier@epitech.eu>
** 
** Started on  Thu Aug 24 12:17:59 2017 maxence.fourrier
** Last update Thu Aug 24 12:46:40 2017 maxence.fourrier
*/

#include "my.h"

void		draw_power(t_all *all)
{
  int		x;
  int		y;

  y = 0;
  while (y < 300)
    {
      x = 0;
      while (x < 50)
	{
	  my_put_pixel(all->graph->framebuffer,
		       x + (SCREEN_WIDTH / 3),
		       -y + (SCREEN_HEIGHT / 1.6), sfBlack);
	  x++;
	}
      y++;
    }
  y = 0;
  while (y < all->game->power * 3)
    {
      x = 0;
      while (x < 50)
	{
	  my_put_pixel(all->graph->framebuffer,
		       x + (SCREEN_WIDTH / 3),
		       -y + (SCREEN_HEIGHT / 1.6), sfGreen);
	  x++;
	}
      y++;
    }
}
