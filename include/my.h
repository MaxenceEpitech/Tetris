/*
** my.h for include in /home/Max/Documents/include
** 
** Made by fourrier maxence
** Login   <maxence.fourrier@epitech.eu>
** 
** Started on  Sat May 13 10:23:04 2017 fourrier maxence
** Last update Thu Aug  3 18:07:34 2017 maxence.fourrier
*/

#ifndef _MY_H_
# define _MY_H_

/*
** __ Include __
*/

# include <unistd.h>
# include <term.h>
# include <curses.h>
# include <stdlib.h>
# include <stdarg.h>
# include <sys/types.h>
# include <dirent.h>

/*
** __ Define __
*/

/*
**		__ Tetris :D __
*/

# define KEY_LEFT_	"kcub1"
# define KEY_RIGHT_	"kcuf1"
# define KEY_DROP_	"kcud1"
# define KEY_TURN_	"kcuu1"
# define KEY_PAUSE	" "
# define KEY_QUIT	"q"
# define KEY_WNEXT	0
# define LEVEL		1
# define WIDTH		10
# define HEIGHT		20

# define DIR_NAME	"tetriminos"
# define END_FILE	".tetrimino"

/*
**		__ Flags __
*/

# define FLAG_H         "--help"
# define FLAG_L         "-l"
# define FLAG_LVL       "--level="
# define FLAG_KL        "-kl"
# define FLAG_KLEFT     "--key-left="
# define FLAG_KR        "-kr"
# define FLAG_KRIGHT    "--key-right="
# define FLAG_KT        "-kt"
# define FLAG_KTURN     "--key-turn="
# define FLAG_KD        "-kd"
# define FLAG_KDROP     "--key-drop="
# define FLAG_KQ        "-kq"
# define FLAG_KQUIT     "--key-quit="
# define FLAG_KP        "-kp"
# define FLAG_KPAUSE    "--key-pause="
# define FLAG_SIZE      "--map-size="
# define FLAG_W         "-w"
# define FLAG_WNXT      "--without-next"
# define FLAG_D         "-d"
# define FLAG_DEBUG     "--debug"

# define DEFAULT_KL     "Key Left : ^EOD\n"
# define DEFAULT_KR     "Key Right : ˆEOC\n"
# define DEFAULT_KT     "Key Turn : (space)\n"
# define DEFAULT_KD     "Key Drop : x\n"
# define DEFAULT_KQ     "Key Quit : q\n"
# define DEFAULT_KP     "Key Pause : p\n"

# define FLAG_1		"--help"
# define FLAG_2		"-l "
# define FLAG_3		"--level="
# define FLAG_4		"-kl "
# define FLAG_5		"--key-left="
# define FLAG_6		"-kr "
# define FLAG_7		"--key-right="
# define FLAG_8		"-kt "
# define FLAG_9		"--key-turn="
# define FLAG_10	"-kd "
# define FLAG_11	"--key-drop="
# define FLAG_12	"-kq "
# define FLAG_13	"--key-quit="
# define FLAG_14	"-kp "
# define FLAG_15	"--key-pause="
# define FLAG_16	"--map-size="
# define FLAG_17	"-w "
# define FLAG_18	"--without-next"
# define FLAG_19	"-d "
# define FLAG_20	"--debug-mode"

/*
**		__ Error Message __
*/

# define OPEN_MSG	"Open error.\n"

# define READ_MSG	"Read error.\n"

# define MALLOC_MSG	"Malloc error of : "
# define MALLOC_CHAR	"char.\n"
# define MALLOC_LIST	"t_list.\n"

/*
**		__ Returns Values __
*/

# define EXIT_USAGE	84
# define EXIT_MALLOC	84
# define EXIT_READ	84
# define EXIT_OPEN	84

# define EXIT_SUCCESS	0

/*
** __ T_list __
*/

typedef struct		s_key
{
  int			level;
  int			height;
  int			width;
  int			withoutnext;
  char			*keyleft;
  char			*keyright;
  char			*keydrop;
  char			*keyturn;
  char			*keypause;
  char			*keyquit;
}			t_key;

typedef struct		s_game
{
  char			*term;
  t_key			*key;
}			t_game;

typedef struct		s_list
{
  char			*form;
  char			*name;
  int			width;
  int			height;
  int			color;
  int			error;
  struct s_list		*next;
}			t_list;

/*
** __ tetris __
*/

int	check_all(char **);

int	cmp_sort(char *, char *);
int	is_min(t_list *, char *);
t_list	*add_to_list(t_list *, t_list *);
t_list	*send_end(t_list *);
t_list	*sort_list(t_list *);

int	get_form(char *);
int	check_size(int, int, char *, int);
t_list	*create_list(char *, t_list *);

void	print_help(char *);

int	check_buff(char *);

void	print_form(char *);
int	get_color(char *);
int	get_height(char *);
int	get_width(char *);
char	*get_name(char *);

int	get_size_file(char *);
char	*get_buff(char *);

t_list	*my_rev_list(t_list *);
int	check_tetriminos();
int	print_tetris(char *);
int	read_file(DIR *);
int	print_tetriminos();

void	print_info(t_key *);
void	my_print_key(char *);
void	print_key(t_key *);
int	print_debug(t_key *);

t_game	*init_game();
t_key	*init_key();

int	get_nb_file();
int	check_name(char *);
int	new_cmp(char *, char *);
char	*get_term(char **env, char *str);

int	error_arg(char **av);
t_game	*check_option(int ac, char **av, char **env);

void	check_kl(t_key *, char **, int);
void	check_kr(t_key *, char **, int);
void	check_kt(t_key *, char **, int);
void	check_kd(t_key *, char **, int);
void	check_kq(t_key *, char **, int);
void	check_kp(t_key *, char **, int);

void	check_nxt(t_key *, char **, int);
void	check_lvl(t_key *, char **, int);
int	my_isnbr(char *);
char	*get_str(char *);
int	my_spcmp(char *, char *);

/*
** __ Lib __
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
