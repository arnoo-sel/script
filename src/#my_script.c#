/*
** my_script.c for my_script in /home/sellie_a/local/c/my_script
** 
** Made by arnaud sellier
** Login   <sellie_a@epitech.net>
** 
** Started on  Tue Feb 24 10:50:42 2009 arnaud sellier
** Last update Sun Mar 29 22:35:16 2009 arnaud sellier
*/

#include "main.h"

t_glob		*get_glob()
{
  static t_glob *glob = NULL;

  if (glob == NULL)
    if ((glob = malloc(sizeof(*glob))) == NULL)
      exit(-1);
  return (glob);
}

/*
** Start the shell in SHELL env. variable or /bin/sh. Use -i flag
** to force interactive mode.
*/

void			start_a_shell(t_opt *opt, char *shell, int slave)
{
  struct winsize	ws;
  int			resize;

  resize = 0;
  if (ioctl(0, TIOCGWINSZ, &ws) != -1)
    resize = 1;
  if (my_login_tty(slave) == -1)
    {
      my_puts("Can't change controlling tty !");
      exit(-1);
    }
  if (resize)
    ioctl(0, TIOCSWINSZ, &ws);
  if (opt->command)
    execvp(opt->command[0], opt->command);
  else
    execl(shell, shell, "-i", NULL);
  my_puts("Command not found");
  exit(-1);
}

t_glob		*init_glob(t_opt *opt)
{
   t_glob	*glob;

   glob = get_glob();
   glob->pid_zombi = 0;
   glob->outfile = opt->outfile;
   if (opt->a)
     glob->fd_out = open(opt->outfile, O_WRONLY | O_CREAT |O_APPEND, 0644);
   else
     glob->fd_out = open(opt->outfile, O_WRONLY | O_CREAT | O_TRUNC, 0644);
   if (glob->fd_out == -1)
    quit_permission_denied(opt->outfile);
   return (glob);
}

void		outfile_head(t_opt *opt, t_glob *glob)
{
  time_t	mtime;

  write(1, "Script started, output file is ", 31);
  my_puts(opt->outfile);
  write(glob->fd_out, "Script started on ", 18);
  time(&mtime);
  write(glob->fd_out, ctime(&mtime), 25);
}

void		my_script(t_opt *opt, char *shell)
{
  int		pid;
  int		master;
  int		slave;
  t_glob	*glob;

  glob = init_glob(opt);
  signal(SIGCHLD, get_sigchld);
  uncanonical();
  pid = my_forkpty(&master, &slave);
  if (pid == 0)
    {
      if (!opt->q)
	  outfile_head(opt, glob);
      close(glob->fd_out);
      start_a_shell(opt, shell, slave);
    }
  else
    {
      glob->master = master;
      glob->opt_q = opt->q;
      input_output(master, pid);
    }
}
