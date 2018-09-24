/*
** utils.c for utils in /home/Max/Documents/delivery/PSU_2016_tetris/src
** 
** Made by fourrier maxence
** Login   <maxence.fourrier@epitech.eu>
** 
** Started on  Mon Jul 24 12:52:24 2017 fourrier maxence
** Last update Mon Jul 24 14:09:41 2017 fourrier maxence
*/

#include "my.h"

char	*get_name(char *str)
{
  char	*ret;
  int	i;

  if ((ret = malloc(sizeof(char) * (my_strlen(str) + 1))) == NULL)
    return (NULL);
  i = 0;
  while (str[i])
    {
      ret[i] = str[i];
      if (my_strcmp(i + str, END_FILE))
	{
	  ret[i] = '\0';
	  return (ret);
	}
      i++;
    }
  return (NULL);
}

int	get_width(char *str)
{
  char	*nbr;
  int	i;

  if ((nbr = malloc(sizeof(char) * 5)) == NULL)
    return (0);
  i = 0;
  while (str[i] && str[i] != ' ')
    {
      nbr[i] = str[i];
      i++;
    }
  nbr[i] = 0;
  return (my_str_to_int(nbr));
}

int	get_height(char *str)
{
  char	*nbr;
  int	i;
  int	x;

  if ((nbr = malloc(sizeof(char) * 5)) == NULL)
    return (0);
  x = 0;
  i = 0;
  while (str[i++] && (str[i] >= '0' && str[i] <= '9'));
  while (str[i++] && str[i] == ' ');
  while (str[i + x] && str[i + x] != ' ')
    {
      nbr[x] = str[i + x];
      x++;
    }
  nbr[x] = 0;
  return (my_str_to_int(nbr));  
}

int	get_color(char *str)
{
  char	*nbr;
  int	i;
  int	x;

  if ((nbr = malloc(sizeof(char) * 5)) == NULL)
    return (0);
  x = 0;
  i = 0;
  while (str[i++] && (str[i] >= '0' && str[i] <= '9'));
  while (str[i++] && str[i] == ' ');
  while (str[i++] && (str[i] >= '0' && str[i] <= '9'));
  while (str[i++] && str[i] == ' ');
  while (str[i + x] && (str[i + x] >= '0' && str[i + x] <= '9'))
    {
      nbr[x] = str[i + x];
      x++;
    }
  nbr[x] = 0;
  return (my_str_to_int(nbr));  
}

void	print_form(char *str)
{
  int	i;

  i = 0;
  while (str[i] == ' ' || (str[i] >= '0' && str[i] <= '9'))
    i++;
  i++;
  while (str[i])
    {
      my_putchar(str[i]);
      i++;
    }
}
