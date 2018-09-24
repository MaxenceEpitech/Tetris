/*
** init.c for init in /home/Max/Documents/delivery/PSU_2016_tetris/src
** 
** Made by fourrier maxence
** Login   <maxence.fourrier@epitech.eu>
** 
** Started on  Fri Jul 21 15:32:21 2017 fourrier maxence
** Last update Mon Aug  7 14:52:14 2017 maxence.fourrier
*/

#include "my.h"

t_game		*init_game()
{
  t_game	*game;

  if ((game = malloc(sizeof(t_game))) == NULL)
    return (NULL);
  return (game);
}

t_key		*init_key(char *term)
{
  t_key		*key;

  if ((key = malloc(sizeof(t_key))) == NULL)
    return (NULL);
  key->level = LEVEL;
  key->width = WIDTH;
  key->height = HEIGHT;
  if ((key->keyleft = tigetstr(KEY_LEFT_)) == NULL
    || (key->keyright = tigetstr(KEY_RIGHT_)) == NULL
    || (key->keyturn = tigetstr(KEY_TURN_)) == NULL
    || (key->keydrop = tigetstr(KEY_DROP_)) == NULL)
    return (NULL);
  key->keyquit = KEY_QUIT;
  key->keypause = KEY_PAUSE;
  key->withoutnext = KEY_WNEXT;
  return (key);
}
