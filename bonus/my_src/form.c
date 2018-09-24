/*
** form.c for FORM in /home/maxence.fourrier/Documents/Project_C/bonus/my_src
** 
** Made by maxence.fourrier
** Login   <maxence.fourrier@epitech.eu>
** 
** Started on  Wed Aug 23 20:08:43 2017 maxence.fourrier
** Last update Thu Aug 24 12:59:38 2017 maxence.fourrier
*/

#include <time.h>
#include "my.h"

void		init_form_1_2(t_all *all)
{
  if (all->game->color == 0)
    {
      all->game->map[1][(MAP_SIZE_X / 2) - 2] = 'c';
      all->game->map[1][(MAP_SIZE_X / 2) - 1] = 'c';
      all->game->map[1][(MAP_SIZE_X / 2)] = 'c';
      all->game->map[1][(MAP_SIZE_X / 2) + 1] = 'c';
    }
  if (all->game->color == 1)
    {
      all->game->map[1][(MAP_SIZE_X / 2) - 1] = 'c';
      all->game->map[1][(MAP_SIZE_X / 2)] = 'c';
      all->game->map[0][(MAP_SIZE_X / 2) - 1] = 'c';
      all->game->map[0][(MAP_SIZE_X / 2)] = 'c';
    }
}

void		init_form_3_4(t_all *all)
{
  if (all->game->color == 2)
    {
      all->game->map[0][(MAP_SIZE_X / 2) - 2] = 'c';
      all->game->map[1][(MAP_SIZE_X / 2) - 2] = 'c';
      all->game->map[1][(MAP_SIZE_X / 2) - 1] = 'c';
      all->game->map[1][(MAP_SIZE_X / 2)] = 'c';
      all->game->map[1][(MAP_SIZE_X / 2) + 1] = 'c';
    }
  if (all->game->color == 3)
    {
      all->game->map[0][(MAP_SIZE_X / 2) - 1] = 'c';
      all->game->map[0][(MAP_SIZE_X / 2)] = 'c';
      all->game->map[1][(MAP_SIZE_X / 2)] = 'c';
      all->game->map[1][(MAP_SIZE_X / 2) + 1] = 'c';
    }
}

void		generate_form(t_all *all)
{
  sfMusic_play(all->music[2]);
  line_full(all);
  srand(time(NULL));
  all->game->color = rand() % 4;
  init_form_1_2(all);
  init_form_3_4(all);
  all->game->side = 1;
}
