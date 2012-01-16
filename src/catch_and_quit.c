/*
** catch_and_quit.c for my_script in /home/sellie_a/local/c/my_script
** 
** Made by arnaud sellier
** Login   <sellie_a@epitech.net>
** 
** Started on  Tue Feb 24 15:45:52 2009 arnaud sellier
** Last update Sun Mar 29 22:33:25 2009 arnaud sellier
*/

#include "main.h"

void		done(int pid)
{
  t_glob	*glob;
  time_t	mtime;

  glob = get_glob();
  if (pid)
    kill(pid, SIGUSR1);
  if (!glob->opt_q)
    {
      write(1, "Script done, output file is ", 28);
      my_puts(glob->outfile);
      write(glob->fd_out, "\nScript done on ", 16);
      time(&mtime);
      write(glob->fd_out, ctime(&mtime), 25);
    }
  close(glob->fd_out);
  free(glob);
  exit(0);
}

void		get_sigchld()
{
  t_glob	*glob;

  glob = get_glob();
  if (!glob->opt_q)
    write(1, "\n", 1);
  if (glob->pid_zombi)
    done(glob->pid_zombi);
  else
    done(0);
}

void		get_sigusr_one()
{
  t_glob	*glob;

  glob = get_glob();
  close(glob->fd_out);
  free(glob);
  exit(-1);
}

void	quit_permission_denied(char *outfile)
{
  write(1, "my_script: ", 11);
  write(1, outfile, my_strlen(outfile));
  my_puts(": Permission denied");
  exit(-1);
}
