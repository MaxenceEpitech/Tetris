/*
** my.h for include in /home/Max/Documents/include
** 
** Made by fourrier maxence
** Login   <maxence.fourrier@epitech.eu>
** 
** Started on  Sat May 13 10:23:04 2017 fourrier maxence
** Last update Sat Aug 26 14:20:22 2017 maxence.fourrier
*/

#ifndef _MY_H_
# define _MY_H_

/*      __________ ________________________ __________
**
**                        INCLUDES
**      __________ ________________________ __________ 
*/

# include <stdlib.h>
# include <unistd.h>
# include <SFML/Graphics.h>
# include <SFML/Audio.h>
# include <SFML/Window.h>

/*      __________ ________________________ __________
**
**                        DEFINES
**      __________ ________________________ __________ 
*/

# define NB_SPRITE	10

# define PATH_SPRITE_0	"textures/red.png"
# define SPRITE_0	0
# define PATH_SPRITE_1	"textures/cyan.png"
# define SPRITE_1	1
# define PATH_SPRITE_2	"textures/green.png"
# define SPRITE_2	2
# define PATH_SPRITE_3	"textures/orange.png"
# define SPRITE_3	3
# define PATH_SPRITE_4	"textures/lost.png"
# define SPRITE_4	4
# define PATH_SPRITE_5	"textures/tetris.png"
# define SPRITE_5	5
# define PATH_SPRITE_6	"textures/menu.png"
# define SPRITE_MENU	6

# define MAP_SIZE_X	10
# define MAP_SIZE_Y	20
# define SPEED		1
# define TIME		250
# define TETRI_SIZE	16

# define SCREEN_WIDTH   1920
# define SCREEN_HEIGHT  1080
# define SCREEN_NAME	"__TETRIS WORLD__ :D"

# define X_POS		(SCREEN_WIDTH / 2) - ((TETRI_SIZE * MAP_SIZE_X) / 2)
# define Y_POS		(SCREEN_HEIGHT / 2) - ((TETRI_SIZE * MAP_SIZE_Y) / 2)

/*
**		     __ Error Message __
*/

# define OPEN_MSG	"Open Error.\n"

# define READ_MSG	"Read Error.\n"

# define MALLOC_MSG	"Malloc Error.\n"

/*
**	             __ Returns Values __
*/

# define SUCCESS	0
# define ERROR		84

/*
**                       __ TypeDef __
*/

typedef struct		s_list
{
  char			*data;
  struct s_list		*next;
}			t_list;

typedef struct		s_my_framebuffer
{
  sfUint8		*pixels;
  int			width;
  int			height;
}			t_my_framebuffer;

typedef struct		s_graph
{
  sfRenderWindow	*window;
  t_my_framebuffer	*framebuffer;
  sfTexture		*texture;
  sfSprite		*sprite;
  sfText		*text;
}                       t_graph;

typedef struct		s_game
{
  char			**map;
  int			power;
  int			side;
  int			color;
  int			level;
  int			score;
  int			speed;
  sfVector2i		pos;
  sfVector2i		size;
}			t_game;

typedef struct		s_all
{
  sfMusic		**music;
  unsigned long long	init;
  unsigned long long	time;
  unsigned long long	save_time;  
  sfSprite		**sprite;
  t_graph		*graph;
  t_game		*game;
}			t_all;

/*      __________ ________________________ __________
**
**                       Tetris
**      __________ ________________________ __________ 
*/

sfMusic		**init_music();
void		draw_power(t_all *);
char		*my_strcat(char *, char *);

/*
**		     __ game.c __
*/
void		replace_current(t_all *);
int		game(t_all *);

int		tetris();

t_all		*init_all();
t_graph		*init_graph();
t_game		*init_game();
sfSprite	**init_sprite();

sfSprite	*load_picture(char *);
void		fill_map(t_game *);

void		clear_game(t_game *);
int		clear_ressource(t_all *, int);

void		draw_actual(t_all *, int, int);
void		draw_form(t_all *, int, int);
int		draw_all(t_all *);

int		not_lost(char **);

void		get_time(t_all *);
void		get_save_time(t_all *);

/*
**		     __ form.c __
*/
void		init_form_1_2(t_all *);
void		init_form_3_4(t_all *);
void		generate_form(t_all *);

/*
**		     __ move_form.c __
*/
int		check_move(t_all *);
void		move_form(t_all *);

/*
**		     __ can_move.c __
*/
int		can_move_right(t_all *);
int		can_move_left(t_all *);
int		can_move_down(t_all *);

/*
**		     __ can_move.c __
*/
void		move_right(t_all *);
void		move_left(t_all *);
void		move_down(t_all *);

/*
**		     __ line_full.c __
*/
int		is_line_full(t_all *);
void		move_map_down(t_all *, int);
void		line_full(t_all *);

/*
**		     __ rotate.c __
*/
void		rotate_current(t_all *);
void		rotate_0(t_all *);

/*
**		     __ can_rotate.c __
*/
void		get_pos_0_s1(t_all *, int *, int *);
void		get_pos_0_s2(t_all *, int *, int *);
int		can_rotate_0(char **);

/*
**		     __ rotate_s2.c __
*/
void		rotate_2_s1(t_all *);
void		rotate_2_s2(t_all *);
void		rotate_2_s3(t_all *);
void		rotate_2_s4(t_all *);

/*
**		     __ can_rotate_s2.c __
*/
void		get_pos_2_s1(t_all *, int *, int *);
void		get_pos_2_s2(t_all *, int *, int *);
void		get_pos_2_s3(t_all *, int *, int *);
void		get_pos_2_s4(t_all *, int *, int *);

/*
**		     __ rotate_3.c __
*/
void		rotate_3_s1(t_all *);
void		rotate_3_s2(t_all *);

/*
**		     __ can_rotate_s3.c __
*/
void		get_pos_3_s1(t_all *, int *, int *);
void		get_pos_3_s2(t_all *, int *, int *);

/*
**		     __ menu.c __
*/
void		draw_menu(t_all *);

/*      __________ ________________________ __________
**
**                    LIBRARY #GRAPHIC
**      __________ ________________________ __________ 
*/

sfUint8			*create_pixel_buffer(int width, int height);
sfRenderWindow		*create_window(char *name, int width, int height);
t_my_framebuffer	*my_framebuffer_create(int width, int height);
void			my_put_pixel(t_my_framebuffer *framebuffer,
                                     int y, int x, sfColor color);
void			refresh(t_all *);
void			clear_screen(t_graph *);

/*      __________ ________________________ __________
**
**                        LIBRARY #C
**      __________ ________________________ __________ 
*/

t_list	*my_rev_list(t_list *list);
t_list	*my_link_list(t_list *list, char *data);
t_list	*my_list_cpy(t_list *list);
int	my_list_size(t_list *begin);
int	my_list_is_empty(t_list *liste);
void	my_print_list(t_list *liste);

int	my_decimal_to_octal(int nb);
int	my_strlen(char *str);
int	my_str_who_bigger(char *s1, char *s2);
int	my_str_to_int(char *str);
int	my_strcmp(char *a, char *b);
int	my_swap(int *a, int *b);

void	my_putstr_error(char *str);
void	my_putnbr(int nb);
void	my_putchar(char a);
void	my_putstr(char *str);

char	*my_int_to_str(int nb);
char	*my_str_maj(char *str);
char	*my_decimal_to_hexa(int nb);
char	*supp_0(char *str);
char	*my_revstr(char *str);
char	*my_strcpy(char *dest, char *src);

#endif /* !__MY_H_ */
