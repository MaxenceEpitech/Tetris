/*
** draw.c for draw in /home/maxence.fourrier/Documents/Project_C/bonus/my_src
** 
** Made by maxence.fourrier
** Login   <maxence.fourrier@epitech.eu>
** 
** Started on  Thu Aug  3 19:12:41 2017 maxence.fourrier
** Last update Thu Aug 24 12:19:26 2017 maxence.fourrier
*/

#include "my.h"

int		draw_score(t_all *all)
{
  char		*str;

  if ((str = malloc(sizeof(char) * 20)) == NULL)
    return (ERROR);
  if (all->game->score != 0)
    {
      str = my_int_to_str(all->game->score);
      str = my_strcat("Score : ", str);
    }
  else
    str = "Score : 0\n";
  sfText_setString(all->graph->text, str);
  sfRenderWindow_drawText(all->graph->window, all->graph->text, NULL);
  draw_power(all);
  return (SUCCESS);
}

void		draw_actual(t_all *all, int x, int y)
{
  sfVector2f	vec;

  vec.x = x * TETRI_SIZE + X_POS;
  vec.y = y * TETRI_SIZE + Y_POS;
  sfSprite_setPosition(all->sprite[all->game->color], vec);
  sfRenderWindow_drawSprite(all->graph->window,
			    all->sprite[all->game->color], NULL);
}

void		draw_form(t_all *all, int x, int y)
{
  sfVector2f	vec;

  vec.x = x * TETRI_SIZE + X_POS;
  vec.y = y * TETRI_SIZE + Y_POS;
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
  sfRenderWindow_drawSprite(all->graph->window,
			    all->sprite[SPRITE_5], NULL);
  clear_screen(all->graph);
  while (all->game->map[y])
    {
      x = 0;
      while (all->game->map[y][x])
	{
	  if (all->game->map[y][x] == 'c')
	    draw_actual(all, x, y);
	  else if (all->game->map[y][x] != '9')
	    draw_form(all, x, y);
	  x++;
	}
      y++;
    }
  if ((draw_score(all)) == ERROR)
    return (ERROR);
  sfRenderWindow_display(all->graph->window);
  return (SUCCESS);
}
