/*
** init.c for init in /home/maxence.fourrier/Documents/Project_C/raytracer1/bonus/my_src
** 
** Made by maxence.fourrier
** Login   <maxence.fourrier@epitech.eu>
** 
** Started on  Wed Aug  2 16:03:31 2017 maxence.fourrier
** Last update Mon Aug  7 19:27:01 2017 maxence.fourrier
*/

#include "my.h"

t_all		*init_all()
{
  t_all		*all;

  if ((all = malloc(sizeof(t_all))) == NULL
      || (all->graph = init_graph()) == NULL
      || (all->game = init_game()) == NULL
      || (all->sprite = init_sprite()) == NULL)
    return (NULL);
  return(all);
}

t_graph		*init_graph()
{
  t_graph	*graph;

  if ((graph = malloc(sizeof(t_graph))) == NULL
      || (graph->window =
          create_window(SCREEN_NAME, SCREEN_WIDTH, SCREEN_HEIGHT)) == NULL
      || (graph->sprite =
          sfSprite_create()) == NULL
      || (!graph->window)
      || (graph->texture =
          sfTexture_create(SCREEN_WIDTH, SCREEN_HEIGHT)) == NULL)
    return (NULL);
  sfSprite_setTexture(graph->sprite, graph->texture, sfTrue);
  if ((graph->framebuffer =
       my_framebuffer_create(SCREEN_WIDTH, SCREEN_HEIGHT)) == NULL)
    return (NULL);
  return (graph);
}

t_game		*init_game()
{
  t_game	*game;
  int		i;

  if ((game = malloc(sizeof(t_game))) == NULL
      || (game->map = malloc(sizeof(char *) * (MAP_SIZE_Y + 1))) == NULL)
    return (NULL);
  i = 0;
  while (i < MAP_SIZE_Y)
    {
      if ((game->map[i] = malloc(sizeof(char) * (MAP_SIZE_X + 1))) == NULL)
	return (NULL);
      i++;
    }
  fill_map(game);
  game->cpt = 0;
  game->color = 0;
  game->level = 1;
  game->score = 0;
  game->pos.x = MAP_SIZE_X / 2;
  game->pos.y = 0.1;
  return (game);
}

sfSprite	**init_sprite()
{
  sfSprite	**sprite;

  if ((sprite = malloc(sizeof(sfSprite *) * NB_SPRITE)) == NULL
      || (sprite[SPRITE_0] = load_picture(PATH_SPRITE_0)) == NULL
      || (sprite[SPRITE_1] = load_picture(PATH_SPRITE_1)) == NULL
      || (sprite[SPRITE_2] = load_picture(PATH_SPRITE_2)) == NULL
      || (sprite[SPRITE_3] = load_picture(PATH_SPRITE_3)) == NULL)
    return (NULL);
  sprite[4] = NULL;
  return (sprite);
}
