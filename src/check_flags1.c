/*
** check_flags.c for TETRIS in /home/iyad/PSU_2016_tetris
** 
** Made by Iyad
** Login   <iyad.callas@epitech.eu>
** 
** Started on  Tue Jul 25 23:38:59 2017 Iyad
** Last update Thu Aug  3 14:23:13 2017 maxence.fourrier
*/

#include "my.h"

void	check_kl(t_key *key, char **argv, int argc)
{
  int   i;

  i = 0;
  while (++i < argc)
    {
      if (my_strcmp(argv[i], FLAG_KL) == 1
	  && i + 1 != argc)
	key->keyleft = argv[++i];
      else if ((my_spcmp(argv[i], FLAG_KLEFT)) == 1)
	key->keyleft = get_str(argv[i]);
    }
}

void	check_kr(t_key *key, char **argv, int argc)
{
  int   i;

  i = 0;
  while (++i < argc)
    {
      if (my_strcmp(argv[i], FLAG_KR) == 1
	  && i + 1 != argc)
	key->keyright = argv[++i];
      else if ((my_spcmp(argv[i], FLAG_KRIGHT)) == 1)
	key->keyright = get_str(argv[i]);
    }
}

void	check_kt(t_key *key, char **argv, int argc)
{
  int   i;

  i = 0;
  while (++i < argc)
    {
      if (my_strcmp(argv[i], FLAG_KT) == 1
	  && i + 1 != argc)
	key->keyturn = argv[++i];
      else if ((my_spcmp(argv[i], FLAG_KTURN)) == 1)
	key->keyturn = get_str(argv[i]);
    }
}

void	check_kd(t_key *key, char **argv, int argc)
{
  int   i;

  i = 0;
  while (++i < argc)
    {
      if (my_strcmp(argv[i], FLAG_KD) == 1
	  && i + 1 != argc)
	key->keyright = argv[++i];
      else if ((my_spcmp(argv[i], FLAG_KDROP)) == 1)
	key->keyright = get_str(argv[i]);
    }
}

void	check_kq(t_key *key, char **argv, int argc)
{
  int   i;

  i = 0;
  while (++i < argc)
    {
      if (my_strcmp(argv[i], FLAG_KQ) == 1
	  && i + 1 != argc)
	key->keyquit = argv[++i];
      else if ((my_spcmp(argv[i], FLAG_KQUIT)) == 1)
	key->keyquit = get_str(argv[i]);
    }
}
