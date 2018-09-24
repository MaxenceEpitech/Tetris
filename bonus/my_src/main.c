/*
** main.c for main in /home/maxence.fourrier/Documents/Project_C/raytracer1/my_src
** 
** Made by maxence.fourrier
** Login   <maxence.fourrier@epitech.eu>
** 
** Started on  Wed Aug  2 13:49:32 2017 maxence.fourrier
** Last update Wed Aug  2 19:29:01 2017 maxence.fourrier
*/

#include "my.h"

int	main(void)
{
  int	ret;

  if ((ret = tetris()) == -1)
    return (84);
  return (ret);
}
