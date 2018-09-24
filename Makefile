##
## Makefile for makefile in /home/Max/Documents/delivery/CPE_year_Pushswap
## 
## Made by fourrier maxence
## Login   <maxence.fourrier@epitech.eu>
## 
## Started on  Tue Apr 11 10:05:45 2017 fourrier maxence
## Last update Thu Aug  3 17:46:51 2017 maxence.fourrier
##

NAME		= 	tetris

CC		= 	gcc

RM		= 	rm -f

SRCS_DIR	= 	./src/

SRCS		=	$(SRCS_DIR)main.c			\
			$(SRCS_DIR)tools.c			\
			$(SRCS_DIR)print_debug.c		\
			$(SRCS_DIR)check_all.c			\
			$(SRCS_DIR)create_list.c		\
			$(SRCS_DIR)check_buff.c			\
			$(SRCS_DIR)get_buff.c			\
			$(SRCS_DIR)sort_list.c			\
			$(SRCS_DIR)check_flags1.c		\
			$(SRCS_DIR)check_flags2.c		\
			$(SRCS_DIR)print_tetriminos.c		\
			$(SRCS_DIR)print_help.c			\
			$(SRCS_DIR)utils.c			\
			$(SRCS_DIR)init.c			\
			$(SRCS_DIR)option.c			\
			$(SRCS_DIR)tetris.c

OBJS		= 	$(SRCS:.c=.o)

CFLAGS		+= 	-I./include

LDFLAGS		+=	-L./lib/my -lmy -lncurses

all		:	$(NAME)

$(NAME)		: 	$(OBJS)
			make -C ./lib/my
			$(CC) -o $(NAME) $(OBJS) $(CFLAGS) $(LDFLAGS)

clean		:
			make clean -C ./lib/my
			$(RM) $(OBJS)

fclean		:	clean
			make fclean -C ./lib/my
			$(RM) $(NAME)

re		:	fclean all

.PHONY		: 	all clean fclean re

