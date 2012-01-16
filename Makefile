##
## Makefile for tp in /home/sellie_a/local/c/my_script/tp/ex_1
## 
## Made by arnaud sellier
## Login   <sellie_a@epitech.net>
## 
## Started on  Mon Feb 23 13:53:03 2009 arnaud sellier
## Last update Sun Mar 29 21:51:48 2009 arnaud sellier
##

NAME = my_script

all: 
	cd src && $(MAKE)

clean:
	rm -f *.o
	rm -f *~
	cd src && $(MAKE) clean

fclean: clean
	rm -f $(NAME)

re: fclean all
