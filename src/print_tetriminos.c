/*
** print_tetriminos.c for print_tetriminos in /home/Max/Documents/delivery/PSU_2016_tetris/src
** 
** Made by fourrier maxence
** Login   <maxence.fourrier@epitech.eu>
** 
** Started on  Mon Jul 24 10:22:42 2017 fourrier maxence
** Last update Mon Aug  7 14:32:35 2017 maxence.fourrier
*/

#include "my.h"

int		check_tetriminos()
{
  DIR		*dir;

  if ((dir = opendir(DIR_NAME)) == NULL)
    return (-1);  
  if (closedir(dir) == -1)
    return (-1);
}

void		print_list(t_list *list)
{
  while (list != NULL)
    {
      my_putstr("Tetriminos : Name ");
      my_putstr(list->name);
      if (list->error == 1)
	my_putstr(" : Error\n");
      else
	{
	  my_putstr(" : Size ");
	  my_putnbr(list->width);
	  my_putchar('*'); 
	  my_putnbr(list->height);
	  my_putstr(" : Color ");
	  my_putnbr(list->color);
	  my_putstr(" :\n");
	  print_form(list->form);
	}
      list = list->next;
    }
}

int		read_file(DIR *dir)
{
  struct dirent	*dirent;
  int		nb_file;
  t_list	*list;

  if ((nb_file = get_nb_file()) == -1
      || nb_file == 0
      || (list = malloc(sizeof(t_list))) == NULL)
    return (-1);
  list = NULL;
  my_putstr("Tetriminos : ");
  my_putnbr(nb_file);
  my_putchar('\n');
  while ((dirent = readdir(dir)) != NULL)
    if (check_name(dirent->d_name) != -1)
      if ((list = create_list(dirent->d_name, list)) == NULL)
	return (-1);
  if ((list = sort_list(list)) == NULL)
    return (-1);
  list = my_rev_list(list);
  print_list(list);
  return (0);
}

int		print_tetriminos()
{
  DIR		*dir;

  if ((dir = opendir(DIR_NAME)) == NULL
      || read_file(dir) == -1
      || closedir(dir) == -1)
    return (-1);
}

t_list          *my_rev_list(t_list *list)
{
  t_list        *copy;
  t_list        *my_pos;
  t_list        *pos_next;

  copy = malloc(sizeof(t_list));
  my_pos = malloc(sizeof(t_list));
  pos_next = malloc(sizeof(t_list));
  if (copy == NULL || my_pos == NULL || pos_next == NULL)
    return (NULL);
  copy = list;
  my_pos = NULL;
  while (copy->next != NULL)
    {
      pos_next = copy->next;
      copy->next = my_pos;
      my_pos = copy;
      copy = pos_next;
    }
  copy->next = my_pos;
  return (copy);
}
