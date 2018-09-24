/*
** create_list.c for create_list in /home/Max/Documents/delivery/PSU_2016_tetris/src
** 
** Made by fourrier maxence
** Login   <maxence.fourrier@epitech.eu>
** 
** Started on  Mon Jul 24 17:42:25 2017 fourrier maxence
** Last update Mon Aug  7 15:11:15 2017 maxence.fourrier
*/

#include "my.h"

int		get_form(char *buff)
{
  int		i;

  i = 0;
  while(buff[i] && buff[i] != '\n')
    i++;
  return (i);
}

int		get_max(int cpt, int i)
{
  int		max;

  max = cpt;
  if (i == 0)
    max = 1;
  return (max);
}

int		check_size(int width, int height, char *buff, int color)
{
  int		i;
  int		cpt;
  int		max;
  int		line;

  i = 0;
  cpt = 0;
  max = 0;
  line = 0;
  while (buff[i])
    {
      if (buff[i] == '\n')
	{
	  cpt = 0;
	  line++;
	}
      if (buff[i] == '*' && cpt >= max)
	max = get_max(cpt, i);
      cpt++;
      i++;
    }
  if (max != width || line != height || color < 0 || color > 7)
    return (-1);
  return (0);
}

t_list		*create_list(char *str, t_list *list)
{
  t_list	*new;
  char          *buff;
  char          *name;

  if ((buff = get_buff(str)) == NULL
      || (new = malloc(sizeof(t_list))) == NULL
      || (new->name = get_name(str)) == NULL)
    return (NULL);
  new->next = list;
  if (check_buff(buff) == -1
      || check_size(get_width(buff), get_height(buff),
		    1 + buff + get_form(buff), get_color(buff)) == -1)
    new->error = 1;
  else
    {
      new->error = 0;
      new->width = get_width(buff);
      new->height = get_height(buff);
      new->color = get_color(buff);
      new->form = buff;
    }
  return (new);
}
