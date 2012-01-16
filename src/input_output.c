/*
** input_output.c for my_script in /home/sellie_a/local/c/my_script
** 
** Made by arnaud sellier
** Login   <sellie_a@epitech.net>
** 
** Started on  Tue Feb 24 15:19:21 2009 arnaud sellier
** Last update Sun Mar 29 22:35:37 2009 arnaud sellier
*/

#include "main.h"

void			get_sigwinch()
{
  struct winsize	ws;
  t_glob		*glob;

  signal(SIGWINCH, get_sigwinch);
  glob = get_glob();
  if (ioctl(0, TIOCGWINSZ, &ws) != -1)
    ioctl(glob->master, TIOCSWINSZ, &ws);
}

void	the_input(t_glob *glob, int pid, char *buf, int master)
{
#if (OS != SUN)
  signal(SIGWINCH, get_sigwinch);
#endif
  glob->pid_zombi = pid;
  while (1)
    {
      my_memset(buf, 0, 4096);
      if ((read(0, buf, 4096)) == -1)
	done(pid);
      write(master, buf, my_strlen(buf));
    }
}

void	the_output(t_glob *glob, char *buf, int master)
{
  signal(SIGUSR1, get_sigusr_one);
  while (1)
    {
      my_memset(buf, 0, 4096);
      if ((read(master, buf, 4096)) == -1)
	done(0);
      write(1, buf, my_strlen(buf));
      write(glob->fd_out, buf, my_strlen(buf));
    }
}

void		input_output(int master, int pid_son)
{
  int		pid;
  char		buf[4096];
  t_glob	*glob;

  glob = get_glob();
  if ((pid = fork()) == -1)
    {
      kill(pid_son, SIGKILL);
      exit(-1);
    }
  if (!pid)
    the_output(glob, buf, master);
  else
    the_input(glob, pid, buf, master);
}
