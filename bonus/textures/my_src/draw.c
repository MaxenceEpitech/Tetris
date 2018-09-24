/*
** draw.c for draw in /home/maxence.fourrier/Documents/Project_C/bonus/my_src
** 
** Made by maxence.fourrier
** Login   <maxence.fourrier@epitech.eu>
** 
** Started on  Thu Aug  3 19:12:41 2017 maxence.fourrier
** Last update Mon Aug  7 19:25:32 2017 maxence.fourrier
*/

#include "my.h"

void		draw_actual(t_all *all)
{
  sfVector2f	vec;

  vec.x = all->game->pos.x * TETRI_SIZE;
  vec.y = all->game->pos.y * TETRI_SIZE;
  sfSprite_setPosition(all->sprite[all->game->color], vec);
  sfRenderWindow_drawSprite(all->graph->window,
			    all->sprite[all->game->color], NULL);
}

void		draw_form(t_all *all, int x, int y)
{
  sfVector2f	vec;

  vec.x = x * TETRI_SIZE;
  vec.y = y * TETRI_SIZE;
  sfSprite_setPosition(all->sprite[all->game->map[y][x]
				   - '0'], vec);
  sfRenderWindow_drawSprite(all->graph->window,
			    all->sprite[all->game->map[y][x]
					- '0'], NULL);
}

int		draw_all(t_all *all)
{
  int		x;
  int		y;

  y = 0;
  draw_actual(all);
  while (all->game->map[y])
    {
      x = 0;
      while (all->game->map[y][x])
	{
	  if (all->game->map[y][x] != '9')
	    draw_form(all, x, y);
	  x++;
	}
      y++;
    }
  sfRenderWindow_display(all->graph->window);
  return (SUCCESS);
}
