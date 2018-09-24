/*
** main.c for main in /home/Max/Documents
** 
** Made by fourrier maxence
** Login   <maxence.fourrier@epitech.eu>
** 
** Started on  Tue Apr 25 13:13:22 2017 fourrier maxence
** Last update Mon Aug  7 14:29:13 2017 maxence.fourrier
*/

#include "my.h"

int		check_key(t_game *game, char **av, int ac)
{
  int		i;

  check_kl(game->key, av, ac);
  check_kr(game->key, av, ac);
  check_kt(game->key, av, ac);
  check_kd(game->key, av, ac);
  check_kq(game->key, av, ac);
  check_kp(game->key, av, ac);
  check_nxt(game->key, av, ac);
  check_lvl(game->key, av, ac);
  i = 1;
  while (av[i])
    {
      if (my_strcmp(av[i], "-d") || my_strcmp(av[i], "--debug"))
	if (print_debug(game->key) == -1)
	  return (-1);
      if (my_strcmp(av[i], "--help"))
	print_help(av[0]);
      i++;
    }
}

int		main(int ac, char **av, char **env)
{
  t_game	*game;

  if (check_all(av) == -1)
    {
      print_help(av[0]);
      return (84);
    }
  if ((game = check_option(ac, av, env)) == NULL
      || check_key(game, av, ac) == -1)
    return (84);
  return (0);
}
