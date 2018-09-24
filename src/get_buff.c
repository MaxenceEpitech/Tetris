/*
** get_buff.c for get_buff in /home/Max/Documents/delivery/PSU_2016_tetris/src
** 
** Made by fourrier maxence
** Login   <maxence.fourrier@epitech.eu>
** 
** Started on  Mon Jul 24 10:55:15 2017 fourrier maxence
** Last update Mon Jul 24 12:37:58 2017 fourrier maxence
*/

#include <fcntl.h>

#include "my.h"

char		*add_tetrimino(char *str, char *doc)
{
  char		*ret;
  int		i;
  int		x;

  if ((ret = malloc(sizeof(char) * (my_strlen(str) + 12))) == NULL)
    return (NULL);
  x = 0;
  i = 0;
  while (doc[x])
    {
      ret[x] = doc[x];
      x++;
    }
  ret[x] = '/';
  x++;
  while (str[i])
    {
      ret[x + i] = str[i];
      i++;
    }
  ret[x + i] = '\0';
  return (ret);
}

int		get_size_file(char *str)
{
  int		file;
  int		i;
  char		c;

  i = 0;
  if ((str = add_tetrimino(str, DIR_NAME)) == NULL
      || (file = open(str, O_RDONLY)) == -1)
    return (-1);
  while (read(file, &c, 1) > 0)
    i++;
  return (i);
}

char		*get_buff(char *str)
{
  char		*buff;
  int		taille;
  int		file;
  int		pos;

  if ((taille = get_size_file(str)) == -1)
    return (NULL);
  if ((buff = malloc(sizeof(char) * (taille + 1))) == NULL
      || (str = add_tetrimino(str, DIR_NAME)) == NULL)
    return (NULL);
  if ((file = open(str, O_RDONLY)) == -1)
    return (NULL);
  if ((pos = read(file, buff, taille)) == -1)
    return (NULL);
  buff[taille] = '\0';
  if (close(file) == -1)
    return (NULL);
  return (buff);
}

int		get_nb_file()
{
  struct dirent	*dirent;
  DIR		*dir;
  int		i;

  if ((dir = opendir(DIR_NAME)) == NULL)
    return (-1);
  i = 0;
  while ((dirent = readdir(dir)) != NULL)
    if (check_name(dirent->d_name) != -1)
      i++;
  return (i);
}
