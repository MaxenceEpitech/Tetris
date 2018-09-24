/*
** init.c for init in /home/maxence.fourrier/Documents/Project_C/raytracer1/bonus/my_src
** 
** Made by maxence.fourrier
** Login   <maxence.fourrier@epitech.eu>
** 
** Started on  Wed Aug  2 16:03:31 2017 maxence.fourrier
** Last update Thu Aug 24 12:52:30 2017 maxence.fourrier
*/

#include "my.h"

t_all		*init_all()
{
  t_all		*all;

  if ((all = malloc(sizeof(t_all))) == NULL
      || (all->graph = init_graph()) == NULL
      || (all->game = init_game()) == NULL
      || (all->sprite = init_sprite()) == NULL
      || (all->music = init_music()) == NULL)
    return (NULL);
  get_time(all);
  get_save_time(all);
  sfRenderWindow_drawSprite(all->graph->window,
                            all->sprite[SPRITE_5], NULL);
  return(all);
}

sfText		*init_text()
{
  sfText        *text;
  sfFont	*font;
  sfVector2f    vec;

  if ((text = sfText_create()) == NULL
      || (font = sfFont_createFromFile("font.ttf")) == NULL)
    return (NULL);
  vec.x = 10;
  vec.y = 10;
  sfText_setString(text, "score : 0\n");
  sfText_setFont(text, font);
  sfText_setCharacterSize(text, 30);
  sfText_setColor(text, sfWhite);
  sfText_setPosition(text, vec);
  return (text);
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
       my_framebuffer_create(SCREEN_WIDTH, SCREEN_HEIGHT)) == NULL
      || (graph->text = init_text()) == NULL)
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
  game->side = 1;
  game->color = 0;
  game->level = 1;
  game->score = 0;
  game->pos.x = MAP_SIZE_X / 2;
  game->pos.y = 0.1;
  game->power = 50;
  return (game);
}

sfSprite	**init_sprite()
{
  sfSprite	**sprite;

  if ((sprite = malloc(sizeof(sfSprite *) * NB_SPRITE)) == NULL
      || (sprite[SPRITE_0] = load_picture(PATH_SPRITE_0)) == NULL
      || (sprite[SPRITE_1] = load_picture(PATH_SPRITE_1)) == NULL
      || (sprite[SPRITE_2] = load_picture(PATH_SPRITE_2)) == NULL
      || (sprite[SPRITE_3] = load_picture(PATH_SPRITE_3)) == NULL
      || (sprite[SPRITE_4] = load_picture(PATH_SPRITE_4)) == NULL
      || (sprite[SPRITE_5] = load_picture(PATH_SPRITE_5)) == NULL
      || (sprite[SPRITE_MENU] = load_picture(PATH_SPRITE_6)) == NULL)
    return (NULL);
  sprite[7] = NULL;
  return (sprite);
}
