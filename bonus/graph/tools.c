/*
** tools.c for tools in /home/maxence.fourrier/Documents/Project_C/raytracer1/bonus/graph
** 
** Made by maxence.fourrier
** Login   <maxence.fourrier@epitech.eu>
** 
** Started on  Wed Aug  2 16:32:41 2017 maxence.fourrier
** Last update Thu Aug 24 01:49:19 2017 maxence.fourrier
*/

#include "my.h"

void		clear_screen(t_graph *graph)
{
  int		x;
  int		y;

  y = Y_POS;
  while (y < Y_POS + (MAP_SIZE_Y * TETRI_SIZE))
    {
      x = X_POS;
      while (x < X_POS + (MAP_SIZE_X * TETRI_SIZE))
	{
	  my_put_pixel(graph->framebuffer, x, y, sfBlack);
	  x++;
	}
      y++;
    }
  sfTexture_updateFromPixels(graph->texture,
                             graph->framebuffer->pixels,
                             SCREEN_WIDTH, SCREEN_HEIGHT, 0, 0);
  sfRenderWindow_drawSprite(graph->window, graph->sprite, NULL);
}

void		refresh(t_all *all)
{
  sfTexture_updateFromPixels(all->graph->texture,
                             all->graph->framebuffer->pixels,
                             SCREEN_WIDTH, SCREEN_HEIGHT, 0, 0);
  sfRenderWindow_drawSprite(all->graph->window, all->graph->sprite, NULL);
  sfRenderWindow_display(all->graph->window);
}
