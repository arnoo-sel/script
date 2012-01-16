/*
** tty_tools.c for my_script in /home/sellie_a/local/c/my_script
** 
** Made by arnaud sellier
** Login   <sellie_a@epitech.net>
** 
** Started on  Tue Feb 24 15:14:20 2009 arnaud sellier
** Last update Sun Mar 29 22:33:15 2009 arnaud sellier
*/

#include "main.h"

/*
** Find a free pty and the associate tty
*/

int	*my_openpty(int *master, int *slave, char ttyname[11])
{
  char	pty[11];
  char	tty[11];
  char	x;
  char	y;

  my_strcpy(pty, "/dev/pty");
  pty[10] = 0;
  x = 'p' - 1;
  while (++x <= 'z' && (y = '0' - 1))
    while (++y <= 'f')
      {
	pty[8] = x;
	pty[9] = y;
	if ((*master = open(pty, O_RDWR)) != -1)
	  {
	    my_strcpy(tty, pty);
	    tty[5] = 't';
	    if ((*slave = open(tty, O_RDWR)) == -1)
	      return (NULL);
	    my_strcpy(ttyname, tty);
	    return (master);
	  }
      }
  return (NULL);
}

/*
** Make a tty the process controller
*/

int	my_login_tty(int fd)
{
  int	out;

  out = 0;
  setsid();
#if (OS != SUN)
  out = ioctl(fd, TIOCSCTTY, (char *)NULL);
#endif
  dup2(fd, 0);
  dup2(fd, 1);
  dup2(fd, 2);
  close(fd);
  return (out);
}

int	my_forkpty(int *master, int *slave)
{
  char	ttyname[11];
  int	pid;

  if (my_openpty(master, slave, ttyname) == NULL)
    {
      my_puts("Can't open a pty !");
      exit(-1);
    }
  pid = fork();
  if (pid == -1)
    {
      my_puts("Can't fork !");
      exit(-1);
    }
  if (!pid)
    close(*master);
  else
    close(*slave);
  return (pid);
}
