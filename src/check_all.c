/*
** check_all.c for check_all in /home/maxence.fourrier/Documents/PSU_2016_tetris/src
** 
** Made by maxence.fourrier
** Login   <maxence.fourrier@epitech.eu>
** 
** Started on  Thu Aug  3 15:06:30 2017 maxence.fourrier
** Last update Mon Aug  7 12:25:00 2017 maxence.fourrier
*/

#include "my.h"

int	is_flag_equal(char *str)
{
  if (my_strcmp(str, FLAG_H)
      || my_strcmp(str, FLAG_LVL)
      || my_strcmp(str, FLAG_KLEFT)
      || my_strcmp(str, FLAG_KRIGHT)
      || my_strcmp(str, FLAG_KTURN)
      || my_strcmp(str, FLAG_KDROP)
      || my_strcmp(str, FLAG_KQUIT)
      || my_strcmp(str, FLAG_KPAUSE)
      || my_strcmp(str, FLAG_SIZE)
      || my_strcmp(str, FLAG_WNXT)
      || my_strcmp(str, FLAG_D)
      || my_strcmp(str, FLAG_DEBUG)
      || my_strcmp(str, FLAG_W))
    return (1);
  return (0);
}

int	is_flag_space(char *str)
{
  if (my_strcmp(str, FLAG_L)
      || my_strcmp(str, FLAG_KL)
      || my_strcmp(str, FLAG_KR)
      || my_strcmp(str, FLAG_KT)
      || my_strcmp(str, FLAG_KD)
      || my_strcmp(str, FLAG_KQ)
      || my_strcmp(str, FLAG_KP))
    return (1);
  return (0);
}

int	check_all(char **av)
{
  int	i;

  i = 1;
  while (av[i])
    {
      if (is_flag_equal(av[i]))
	{
	  if (av[i][my_strlen(av[i]) - 1] == '=')
	    return (-1);
	  i++;
	}
      else if (is_flag_space(av[i]))
	{
	  if (av[i + 1] == NULL)
	    return (-1);
	  i += 2;
	}
      else
	return (-1);
    }
  return (0);
}
