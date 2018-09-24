/*
** check_buff.c for check_buff in /home/Max/Documents/delivery/PSU_2016_tetris/src
** 
** Made by fourrier maxence
** Login   <maxence.fourrier@epitech.eu>
** 
** Started on  Mon Jul 24 14:12:56 2017 fourrier maxence
** Last update Fri Jul 28 15:19:21 2017 maxence.fourrier
*/

#include "my.h"

int	check_rest_buff(char *str)
{
  int	i;

  i = 0;
  while (str[i] != '\n')
    i++;
  while (str[i])
    {
      if (!(str[i] == ' '
	    || str[i] == '*'
	    || str[i] == '\n'))
	return (-1);
      i++;
    }
  return (0);
}

int	check_line_1(char *str)
{
  int	i;
  int	save;

  i = 0;
  save = 0;
  while (str[i] >= '0' && str[i] <= '9')
    i++;
  if (save == i || str[i] == 0)
    return (-1);
  i++;
  while (str[i] >= '0' && str[i] <= '9')
    i++;
  if (save == i || str[i] == 0)
    return (-1);
  i++;
  while (str[i] >= '0' && str[i] <= '9')
    i++;
  if (save == i || str[i] == 0)
    return (-1);
  if (str[i] != '\n')
    return (-1);
  return (0);
}

int	check_buff(char *buff)
{
  if (check_line_1(buff) == -1
      || check_rest_buff(buff) == -1)
    return (-1);
  return (0);
}
