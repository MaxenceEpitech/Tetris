/*
** check_flags2.c for TETRIS in /home/iyad/PSU_2016_tetris
** 
** Made by Iyad
** Login   <iyad.callas@epitech.eu>
** 
** Started on  Tue Jul 25 23:44:26 2017 Iyad
** Last update Thu Aug  3 14:25:09 2017 maxence.fourrier
*/

#include "my.h"

void	check_kp(t_key *key, char **argv, int argc)
{
  int   i;

  i = 0;
  while (++i < argc)
    {
      if (my_strcmp(argv[i], FLAG_KP) == 1
	  && argc != i + 1)
	key->keypause = argv[++i];
      else if ((my_spcmp(argv[i], FLAG_KPAUSE)) == 1)
	key->keypause = get_str(argv[i]);
    }
}

void	check_nxt(t_key *key, char **argv, int argc)
{
  int   i;

  i = 0;
  while (++i < argc)
    {
      if (my_strcmp(argv[i], FLAG_W) || my_strcmp(argv[i], FLAG_WNXT))
	key->withoutnext = 1;
    }
}

void	check_lvl(t_key *key, char **av, int argc)
{
  int	i;
  char	*l;

  i = 0;
  while (++i < argc)
    {
      if (my_strcmp(av[i], FLAG_L))
	{
	  if ((my_isnbr(av[i + 1])) == 1
	      && argc != i + 1)
	    key->level = my_str_to_int(av[++i]);
	}
      else if ((my_spcmp(av[i], FLAG_LVL)) == 1)
	{
	  l = get_str(av[i]);
	  if ((my_isnbr(l)) == 1)
	    key->level = my_str_to_int(l);
	}
    }
}

int	my_isnbr(char *str)
{
  int	i;

  i = -1;
  while (str[++i] != '\0')
    if (!('0' <= str[i] && str[i] <= '9'))
      return (0);
  return (1);
}

char	*get_str(char *str)
{
  int	i;
  int	x;
  char	*ret;

  i = 0;
  x = 0;
  if ((ret = malloc(sizeof(char) * (my_strlen(str) + 1))) == NULL)
    return (NULL);
  while (str[i] && str[i] != '=')
    i++;
  while (str[i])
    {
      ret[x] = str[i];
      x++;
      i++;
    }
  ret[x] = 0;
  return (ret + 1);
}
