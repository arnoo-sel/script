##
## Makefile for tp in /home/sellie_a/local/c/my_script/tp/ex_1
## 
## Made by arnaud sellier
## Login   <sellie_a@epitech.net>
## 
## Started on  Mon Feb 23 13:53:03 2009 arnaud sellier
## Last update Sun Mar 29 22:31:32 2009 arnaud sellier
##

CC =		`sh ../get_cc.sh`

NAME = 		my_script

SRC = 		main.c \
		tools.c \
		shell.c \
		opt.c \
		my_script.c \
		tty_tools.c \
		input_output.c \
		catch_and_quit.c \
		term.c

OBJ = 		$(SRC:.c=.o)

CFLAGS = 	-I../include -O2 -W -Wall

#####################################

all: $(OBJ)
	$(CC) -o ../$(NAME) $(OBJ)
	@cp ../$(NAME) ../$(NAME)_`uname -m`-`uname -s`

clean:
	rm -f *.o
	rm -f *~

fclean: clean
	rm -f $(NAME)

re: fclean all
