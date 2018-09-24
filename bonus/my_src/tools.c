/*
** tools.c for tools in /home/maxence.fourrier/Documents/Project_C/raytracer1
** 
** Made by maxence.fourrier
** Login   <maxence.fourrier@epitech.eu>
** 
** Started on  Wed Aug  2 13:50:22 2017 maxence.fourrier
** Last update Thu Aug 24 10:31:02 2017 maxence.fourrier
*/

#include "my.h"

char		*my_strcat(char *a, char *b)
{
  char		*ret;
  int		i;
  int		x;

  if ((ret = malloc(sizeof(char) * 20)) == NULL)
    return (NULL);
  i = 0;
  x = 0;
  while (a[i])
    {
      ret[i] = a[i];
      i++;
    }
  while (b[x])
    {
      ret[i + x] = b[x];
      x++;
    }
  ret[i + x] = 0;
  return (ret);
}

int		not_lost(char **map)
{
  int		x;

  x = 0;
  while (x < MAP_SIZE_X)
    {
      if (map[1][x] != '9' && map[1][x] != 'c')
	return (SUCCESS);
      x++;
    }
  return (1);
}
