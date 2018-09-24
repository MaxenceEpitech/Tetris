/*
** raytracer.c for tetris in /home/maxence.fourrier/Documents/Project_C/bonus/my_src
** 
** Made by maxence.fourrier
** Login   <maxence.fourrier@epitech.eu>
** 
** Started on  Wed Aug  2 19:27:20 2017 maxence.fourrier
** Last update Thu Aug 24 14:56:45 2017 maxence.fourrier
*/

#include <time.h>
#include "my.h"

void		draw_lost(t_all *all)
{
  sfVector2f	vec;
  char		*str;

  vec.x = SCREEN_WIDTH / 2 - 130;
  vec.y = SCREEN_HEIGHT / 2 + 50;
  sfMusic_stop(all->music[0]);
  sfMusic_play(all->music[1]);
  sfRenderWindow_drawSprite(all->graph->window,
                            all->sprite[4], NULL);
  if ((str = malloc(sizeof(char) * 20)) == NULL)
    return;
  if (all->game->score != 0)
    {
      str = my_int_to_str(all->game->score);
      str = my_strcat("Score : ", str);
    }
  else
    str = "Score : 0\n";
  sfText_setString(all->graph->text, str);
  sfText_setCharacterSize(all->graph->text, 80);
  sfText_setPosition(all->graph->text, vec);
  sfRenderWindow_drawText(all->graph->window, all->graph->text, NULL);
  sfRenderWindow_display(all->graph->window);
  while (!sfKeyboard_isKeyPressed(sfKeyEscape));
}

int		check_keys(t_all *all)
{
  sfEvent	event;

  if (sfKeyboard_isKeyPressed(sfKeyRight)
      && can_move_right(all))
    {
      move_right(all);
      return (1);
    }
  if (sfKeyboard_isKeyPressed(sfKeyLeft)
      && can_move_left(all))
    {
      move_left(all);
      return (1);
    }
  return (SUCCESS);
}

int		check_rotate(t_all *all)
{
  if (sfKeyboard_isKeyPressed(sfKeyDown)
      && can_move_down(all))
    {
      move_down(all);
      return (1);
    }
  if (sfKeyboard_isKeyPressed(sfKeySpace))
    {
      rotate_current(all);
      return (1);
    }
  if (sfKeyboard_isKeyPressed(sfKeyUp))
    {
      all->game->power--;
      return (1);
    }
  return (SUCCESS);
}

int		check_event(t_all *all)
{
  if (sfKeyboard_isKeyPressed(sfKeyEscape))
    return (SUCCESS);
  if (check_keys(all) == 1
      || check_rotate(all))
    {
      clear_screen(all->graph);
      if (draw_all(all) == ERROR)
	return (SUCCESS);
      usleep(200000);
    }
  return (1);
}

int		tetris()
{
  t_all		*all;

  if ((all = init_all()) == NULL)
    return (ERROR);
  draw_menu(all);
  generate_form(all);
  all->init = all->time;
  all->game->speed = 1;
  while (not_lost(all->game->map))
    {
      if (all->time > all->init + 200000)
	all->game->speed = 2;
      if (all->time > all->init + 700000)
	all->game->speed = 3;
      if (all->time > all->init + 1000000)
	all->game->speed = 4;
      get_time(all);
      if (all->time > all->save_time + TIME / all->game->speed)
	{
	  if (game(all) == ERROR
	      || draw_all(all) == ERROR)
	    return (clear_ressource(all, ERROR));
	  get_save_time(all);
	}
      if (check_event(all) == SUCCESS)
	return (clear_ressource(all, SUCCESS));
    }
  draw_lost(all);
  return (clear_ressource(all, SUCCESS));
}
