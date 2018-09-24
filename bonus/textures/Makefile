##
## Makefile for makefile in /home/Max/Documents/delivery/CPE_year_Pushswap
## 
## Made by fourrier maxence
## Login   <maxence.fourrier@epitech.eu>
## 
## Started on  Tue Apr 11 10:05:45 2017 fourrier maxence
## Last update Fri Aug  4 19:18:07 2017 maxence.fourrier
##

DEBUG		=	yes

NAME		= 	tetris

CC		= 	gcc

ECHO		=	echo

NORMAL		=	tput sgr0

RED		=	tput setaf 1

BOLD		=	tput bold

BLUE		=	tput setaf 5

RM		= 	rm -f

SRC		= 	./my_src/

GRAPH		= 	./graph/

SRCS		=	$(GRAPH)tools.c				\
			$(GRAPH)graph.c				\
			$(SRC)main.c				\
			$(SRC)tools.c				\
			$(SRC)draw.c				\
			$(SRC)clear_ressource.c			\
			$(SRC)init.c				\
			$(SRC)game.c				\
			$(SRC)init_utils.c			\
			$(SRC)tetris.c

OBJS		= 	$(SRCS:.c=.o)

CFLAGS		+= 	-I./include ##-Wall -Werror -Wextra

LDFLAGS		+=	-L./lib/my -lmy -lm -lcsfml-graphics -lcsfml-window -lcsfml-system -lcsfml-audio

ifeq ($(DEBUG), yes)
	CFLAGS	+=	-g3
endif

all		:	$(NAME)
			$(NORMAL)

$(NAME)		: 	print_debug $(OBJS)
			@make -C ./lib/my
			@$(BLUE)
			@$(CC) -o $(NAME) $(OBJS) $(CFLAGS) $(LDFLAGS)
			@$(RED)
			@$(BOLD)
			@$(ECHO) ""
			@$(ECHO) "___________		START MAKE		___________"
			@$(BLUE)
			@$(ECHO) ""
			@$(ECHO) "OBJS		= OK"
			@$(ECHO) "Lib Make	= OK"
			@$(ECHO) "Binary		= OK"
			@$(ECHO) ""
			@$(RED)
			@$(ECHO) "___________		END MAKE		___________"
			@$(ECHO) ""
			@$(ECHO) ""
			@$(NORMAL)

clean		:	print_debug
			@make clean -C ./lib/my
			@$(RM) $(OBJS)
			@$(RED)
			@$(BOLD)
			@$(ECHO) ""
			@$(ECHO) "___________		START CLEAN		___________"
			@$(BLUE)
			@$(ECHO) ""
			@$(ECHO) "Lib clean	= OK"
			@$(ECHO) "OBJS deleted 	= OK"
			@$(ECHO) ""
			@$(RED)
			@$(ECHO) "___________		END CLEAN		___________"
			@$(ECHO) ""
			@$(ECHO) ""
			@$(NORMAL)

fclean		:	clean
			@make fclean -C ./lib/my
			@$(RM) $(NAME)
			@$(RED)
			@$(BOLD)
			@$(ECHO) ""
			@$(ECHO) "___________		START FCLEAN		___________"
			@$(BLUE)
			@$(ECHO) ""
			@$(ECHO) "Lib fclean	= OK"
			@$(ECHO) "Binary deleted 	= OK"
			@$(ECHO) ""
			@$(RED)
			@$(ECHO) "___________		END FCLEAN		___________"
			@$(ECHO) ""
			@$(ECHO) ""
			@$(NORMAL)

print_debug	:
ifeq ($(DEBUG), yes)
			@$(BLUE)
			@$(BOLD)
			@echo ""
			@echo "  ____  _____ ____  _   _  ____   __  __  ___  ____  _____ "
			@echo " |  _ \| ____| __ )| | | |/ ___| |  \/  |/ _ \|  _ \| ____|"
			@echo " | | | |  _| |  _ \| | | | |  _  | |\/| | | | | | | |  _|  "
			@echo " | |_| | |___| |_) | |_| | |_| | | |  | | |_| | |_| | |___ "
			@echo " |____/|_____|____/ \___/ \____| |_|  |_|\___/|____/|_____|"
			@echo ""
			@$(NORMAL)
endif

re		:	print_debug fclean all

.SILENT		:

.PHONY		: 	all clean fclean re

