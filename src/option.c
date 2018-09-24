/*
** option.c for option in /home/Max/Documents/delivery/PSU_2016_tetris/src
** 
** Made by fourrier maxence
** Login   <maxence.fourrier@epitech.eu>
** 
** Started on  Wed Jul 19 12:41:21 2017 fourrier maxence
** Last update Mon Aug  7 14:51:52 2017 maxence.fourrier
*/

#include "my.h"

t_game		*check_option(int ac, char **av, char **env)
{
  t_game	*game;
  int		error;

  if ((game = init_game()) == NULL
      || (game->term = get_term(env, "TERM=")) == NULL
      || setupterm(game->term, 1, &error) == -1
      || (game->key = init_key(game->term)) == NULL)
    return (NULL);
  return (game);
}
