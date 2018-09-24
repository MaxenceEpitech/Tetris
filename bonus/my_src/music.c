/*
** music.c for music in /home/maxence.fourrier/Documents/Project_C/bonus/my_src
** 
** Made by maxence.fourrier
** Login   <maxence.fourrier@epitech.eu>
** 
** Started on  Thu Aug 24 12:51:48 2017 maxence.fourrier
** Last update Thu Aug 24 12:58:19 2017 maxence.fourrier
*/

#include "my.h"

sfMusic		*nit_music(char *str)
{
  sfMusic	*sound;

  if ((sound = sfMusic_createFromFile(str)) == NULL)
    return (NULL);
  return (sound);
}

sfMusic		**init_music()
{
  sfMusic	**music;

  if ((music = malloc(sizeof(sfMusic*) * 10)) == NULL)
    return (NULL);
  if ((music[0] = nit_music("music.ogg")) == NULL
      || (music[1] = nit_music("lost.ogg")) == NULL
      || (music[2] = nit_music("pop.ogg")) == NULL)
    return (NULL);
  sfMusic_setLoop(music[0], sfTrue);
  sfMusic_play(music[0]);
  return (music);
}
