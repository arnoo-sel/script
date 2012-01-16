/*
** term.c for my_script in /home/sellie_a/local/c/my_script
** 
** Made by arnaud sellier
** Login   <sellie_a@epitech.net>
** 
** Started on  Tue Feb 24 16:39:36 2009 arnaud sellier
** Last update Sun Mar 29 22:32:13 2009 arnaud sellier
*/

#include "main.h"

int	my_tcgetattr(int fd, struct termios *t)
{
  return (ioctl(fd, TIOCGETA, t));
}

int	my_tcsetattr(int fd, struct termios *t)
{
  return (ioctl(fd, TIOCSETA, t));
}

void			uncanonical()
{
  struct termios	s;

  my_tcgetattr(0, &s);
  s.c_lflag &= ~(ICANON | ECHO | ISIG);
  s.c_iflag &= ~(IXON | INLCR | IGNCR | ICRNL);
  s.c_cc[VMIN] = 1;
  s.c_cc[VTIME] = 0;
  my_tcsetattr(0, &s);
}

