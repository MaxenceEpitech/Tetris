/*
** get_time.c for get_time in /home/maxence.fourrier/Documents/Project_C/bonus/my_src
** 
** Made by maxence.fourrier
** Login   <maxence.fourrier@epitech.eu>
** 
** Started on  Wed Aug 23 18:36:44 2017 maxence.fourrier
** Last update Wed Aug 23 18:44:31 2017 maxence.fourrier
*/

#include <sys/time.h>
#include "my.h"

void			get_time(t_all *all)
{
  struct timeval	tv;

  gettimeofday(&tv, NULL);
  unsigned long long time =
    (unsigned long long)(tv.tv_sec) * 1000 +
    (unsigned long long)(tv.tv_usec) / 1000;
  all->time = time;
}

void			get_save_time(t_all *all)
{
  struct timeval	tv;

  gettimeofday(&tv, NULL);
  unsigned long long time =
    (unsigned long long)(tv.tv_sec) * 1000 +
    (unsigned long long)(tv.tv_usec) / 1000;
  all->save_time = time;
}
