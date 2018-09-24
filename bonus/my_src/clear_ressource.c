/*
** clear_ressource.c for clear_ressource in /home/maxence.fourrier/Documents/Project_C/raytracer1/bonus/my_src
** 
** Made by maxence.fourrier
** Login   <maxence.fourrier@epitech.eu>
** 
** Started on  Thu Aug  3 10:36:50 2017 maxence.fourrier
** Last update Thu Aug 24 13:02:05 2017 maxence.fourrier
*/

#include "my.h"

void		clear_game(t_game *game)
{
  int		y;

  y = 0;
  while (y < MAP_SIZE_Y)
    {
      free(game->map[y]);
      y++;
    }
  free(game->map);
  free(game);
}

void		clear_sprite(sfSprite **sprite)
{
  int		i;

  i = 0;
  while (sprite[i])
    {
      sfSprite_destroy(sprite[i]);
      i++;
    }
  free(sprite);
}

int		clear_ressource(t_all *all, int ret)
{
  clear_sprite(all->sprite);
  sfSprite_destroy(all->graph->sprite);
  sfTexture_destroy(all->graph->texture);
  sfRenderWindow_destroy(all->graph->window);
  clear_game(all->game);
  free(all->graph->framebuffer->pixels);
  free(all->graph->framebuffer);  
  free(all->graph);
  sfMusic_destroy(all->music[0]);
  sfMusic_destroy(all->music[1]);
  sfMusic_destroy(all->music[2]);
  free(all);
  return (ret);
}
