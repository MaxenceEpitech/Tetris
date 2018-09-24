/*
** tools.c for tools in /home/maxence.fourrier/Documents/Project_C/raytracer1/bonus/graph
** 
** Made by maxence.fourrier
** Login   <maxence.fourrier@epitech.eu>
** 
** Started on  Wed Aug  2 16:32:41 2017 maxence.fourrier
** Last update Mon Aug  7 19:42:59 2017 maxence.fourrier
*/

#include "my.h"

void		clear_screen(t_graph *graph)
{
  int		x;
  int		y;

  y = 0;
  while (y < MAP_SIZE_Y * (TETRI_SIZE + 1))
    {
      x = 0;
      while (x < MAP_SIZE_X * (TETRI_SIZE + 1))
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

void		refresh(t_graph *graph)
{
  sfTexture_updateFromPixels(graph->texture,
                             graph->framebuffer->pixels,
                             SCREEN_WIDTH, SCREEN_HEIGHT, 0, 0);
  sfRenderWindow_drawSprite(graph->window, graph->sprite, NULL);
  sfRenderWindow_display(graph->window);
}
