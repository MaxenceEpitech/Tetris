/*
** menu.c for menu in /home/maxence.fourrier/Documents/Project_C/bonus/my_src
** 
** Made by maxence.fourrier
** Login   <maxence.fourrier@epitech.eu>
** 
** Started on  Thu Aug 24 09:29:54 2017 maxence.fourrier
** Last update Thu Aug 24 09:33:44 2017 maxence.fourrier
*/

#include "my.h"

void		draw_menu(t_all *all)
{
  sfEvent	event;

  sfRenderWindow_drawSprite(all->graph->window,
                            all->sprite[SPRITE_MENU], NULL);
  sfRenderWindow_display(all->graph->window);
  while (sfRenderWindow_pollEvent(all->graph->window, &event)
	 || event.type != sfEvtKeyReleased);
}
