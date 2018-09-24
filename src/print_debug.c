/*
** print_debug.c for print_debug in /home/Max/Documents/delivery/PSU_2016_tetris/src
** 
** Made by fourrier maxence
** Login   <maxence.fourrier@epitech.eu>
** 
** Started on  Mon Jul 24 09:56:04 2017 fourrier maxence
** Last update Mon Jul 24 17:07:12 2017 fourrier maxence
*/

#include "my.h"

void	print_info(t_key *key)
{
  if (key->withoutnext =! 0)
    my_putstr("Next : Yes\n");
  else
    my_putstr("Next : No\n");
  my_putstr("Level : ");
  my_putnbr(key->level);
  my_putstr("\nsize : ");
  my_putnbr(key->width);
  my_putchar('*');
  my_putnbr(key->height);
  my_putstr("\n");
}

void	my_print_key(char *str)
{
  int	i;

  i = 0;
  while (str[i])
    {
      if (str[i] == '\e')
	my_putstr("^E");
      else if (str[i] == '\b')
	my_putstr("^H");
      else if (str[i] == '\t')
	my_putstr("(tab)");
      else if (str[i] == ' ')
	my_putstr("(space)");
      else if (str[i] == '\n')
	my_putstr("(enter)");
      else
	my_putchar(str[i]);
      i++;
    }
}

void	print_key(t_key *key)
{
  my_putstr("Key Left : ");
  my_print_key(key->keyleft);
  my_putstr("\nKey Right : ");
  my_print_key(key->keyright);
  my_putstr("\nKey Turn : ");
  my_print_key(key->keyturn);
  my_putstr("\nKey Drop : ");
  my_print_key(key->keydrop);
  my_putstr("\nKey Quit : ");
  my_print_key(key->keyquit);
  my_putstr("\nKey Pause : ");
  my_print_key(key->keypause);
  my_putchar('\n');
}

int	print_debug(t_key *key)
{
  if (check_tetriminos() == -1)
    return (-1);
  my_putstr("*** DEBUG MODE ***\n");
  print_key(key);
  print_info(key);
  if (print_tetriminos() == -1)
    return (-1);
  my_putstr("Press any key to start Tetris\n");
  return (0);
}
