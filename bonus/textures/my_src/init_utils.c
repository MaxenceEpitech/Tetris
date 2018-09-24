/*
** init_utils.c for utils in /home/maxence.fourrier/Documents/Project_C/bonus/my_src
** 
** Made by maxence.fourrier
** Login   <maxence.fourrier@epitech.eu>
** 
** Started on  Thu Aug  3 19:47:45 2017 maxence.fourrier
** Last update Mon Aug  7 12:06:57 2017 maxence.fourrier
*/

#include "my.h"

void		fill_map(t_game *game)
{
  int		x;
  int		y;

  y = 0;
  while (y < MAP_SIZE_Y)
    {
      x = 0;
      while (x < MAP_SIZE_X)
        {
          game->map[y][x] = '9';
          x++;
        }
      game->map[y][x] = 0;
      y++;
    }
  game->map[y] = NULL;
}

sfSprite	*load_picture(char *str)
{
  sfSprite	*sprite;
  sfTexture	*texture;

  if ((texture = sfTexture_createFromFile(str, NULL)) == NULL
      || (sprite = sfSprite_create()) == NULL)
    return (NULL);
  sfSprite_setTexture(sprite, texture, sfTrue);
  return (sprite);
}
