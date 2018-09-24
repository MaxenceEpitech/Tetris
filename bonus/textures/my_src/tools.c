/*
** tools.c for tools in /home/maxence.fourrier/Documents/Project_C/raytracer1
** 
** Made by maxence.fourrier
** Login   <maxence.fourrier@epitech.eu>
** 
** Started on  Wed Aug  2 13:50:22 2017 maxence.fourrier
** Last update Mon Aug  7 19:16:11 2017 maxence.fourrier
*/

#include "my.h"

int		not_lost(char **map)
{
  int		x;

  x = 0;
  while (x < MAP_SIZE_X)
    {
      if (map[0][x] != '9')
	return (0);
      x++;
    }
  return (1);
}
