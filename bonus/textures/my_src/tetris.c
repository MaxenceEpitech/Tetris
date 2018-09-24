/*
** raytracer.c for tetris in /home/maxence.fourrier/Documents/Project_C/bonus/my_src
** 
** Made by maxence.fourrier
** Login   <maxence.fourrier@epitech.eu>
** 
** Started on  Wed Aug  2 19:27:20 2017 maxence.fourrier
** Last update Mon Aug  7 19:41:43 2017 maxence.fourrier
*/

#include "my.h"

int		check_event(t_all *all)
{
  if (sfKeyboard_isKeyPressed(sfKeyEscape))
    return (SUCCESS);
  if (sfKeyboard_isKeyPressed(sfKeyRight)
      && all->game->pos.x + 1 < MAP_SIZE_X)
    all->game->pos.x++;
  return (1);
}

int		tetris()
{
  t_all		*all;

  if ((all = init_all()) == NULL)
    return (ERROR);
  while (not_lost(all->game->map))
    {
      if (all->game->cpt >= TIME)
	{
	  clear_screen(all->graph);
	  if (game(all) == ERROR
	      || draw_all(all) == ERROR)
	    return (clear_ressource(all, ERROR));
	  sfRenderWindow_display(all->graph->window);
	  all->game->cpt = 0;
	}
      if (check_event(all) == SUCCESS)
	return (clear_ressource(all, SUCCESS));
      all->game->cpt++;
    }
  return (SUCCESS);
}
