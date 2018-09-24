/*
** sort_list.c for sort_list in /home/Max/Documents/delivery/PSU_2016_tetris/src
** 
** Made by fourrier maxence
** Login   <maxence.fourrier@epitech.eu>
** 
** Started on  Thu Jul 27 09:47:12 2017 fourrier maxence
** Last update Thu Jul 27 10:39:03 2017 fourrier maxence
*/

#include "my.h"

int		cmp_sort(char *a, char *b)
{
  int		i;

  i = 0;
  while (a[i] && b[i])
    {
      if (a[i] > b[i])
	return (1);
      else if (a[i] < b[i])
	return (-1);
      i++;
    }
  if (my_strlen(a) > my_strlen(b))
    return (1);
  else if (my_strlen(a) < my_strlen(b))
    return (-1);
  return (-1);
}

int		is_min(t_list *list, char *data)
{
  while (list != NULL)
    {
      if (cmp_sort(data, list->name) != -1)
	return (0);
      list = list->next;
    }
  return (1);
}

t_list		*add_to_list(t_list *list, t_list *ret)
{
  t_list	*new;

  if ((new = malloc(sizeof(t_list))) == NULL)
    return (NULL);
  new->name = list->name;
  new->width = list->width;
  new->height = list->height;
  new->color = list->color;
  new->form = list->form;
  new->error = list->error;
  new->next = ret;
  return (new);
}

t_list		*send_end(t_list *list)
{
  t_list	*ret;
  t_list	*save;

  if ((ret = malloc(sizeof(t_list))) == NULL
      || (save = malloc(sizeof(t_list))) == NULL)
    return (NULL);
  save = list;
  ret = list->next;
  while (list->next != NULL)
    list = list->next;
  list->next = save;
  save->next = NULL;
  return (ret);
}

t_list		*sort_list(t_list *list)
{
  t_list	*tmp;

  if (list->next == NULL)
    return (list);
  if ((tmp = malloc(sizeof(t_list))) == NULL || list == NULL)
    return (NULL);
  tmp = NULL;
  while (list != NULL)
    {
      if (is_min(list, list->name))
	{
	  if ((tmp = add_to_list(list, tmp)) == NULL)
	    return (NULL);
	  list = list->next;
	}
      else
	if ((list = send_end(list)) == NULL)
	  return (NULL);
    }
  return (tmp);
}
