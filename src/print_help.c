/*
** print_help.c for print_help in /home/Max/Documents/delivery/PSU_2016_tetris/src
** 
** Made by fourrier maxence
** Login   <maxence.fourrier@epitech.eu>
** 
** Started on  Mon Jul 24 15:31:05 2017 fourrier maxence
** Last update Mon Jul 24 17:01:53 2017 fourrier maxence
*/

#include "my.h"

void	print_help(char *binaire)
{
  my_putstr("Usage: ");
  my_putstr(binaire);
  my_putstr(" [options]\nOptions:\n");
  my_putstr("   --help\t\tDisplay this help\n");
  my_putstr("   -l --level={num}\tStart Tetris at level num (def: 1)\n");
  my_putstr("   -kl --key-left={K}\t");
  my_putstr("Move the tetrimino LEFT using the K key (def: left arrow)\n");
  my_putstr("   -kr --key-right={K}\t");
  my_putstr("Move the tetrimino RIGHT using the K key (def: right arrow)\n");
  my_putstr("   -kt --key-turn={K}\t");
  my_putstr("TURN the tetrimino clockwise 90d using the K key ");
  my_putstr("(def: top arrow)\n");
  my_putstr("   -kd --key-drop={K}\t");
  my_putstr("DROP the tetrimino using the K key (def: down arrow)\n");
  my_putstr("   -kq --key-quit={K}\t");
  my_putstr("QUIT the game using the K key (def: 'q' key)\n");
  my_putstr("   -kp --key-pause={K}\t");
  my_putstr("PAUSE/RESTART the game using the K key (def: space bar)\n");
  my_putstr("   --map-size={row,col}\t");
  my_putstr("Set the numbers of rows and columns of the map (def: 20,10)\n");
  my_putstr("   -w --without-next\t");
  my_putstr("Hide next tetrimino (def: false)\n");
  my_putstr("   -d --debug\t\t");
  my_putstr("Debug mode (def: false)\n");
}
