/*
** main.h for my_script in /home/sellie_a/local/c/my_script
** 
** Made by arnaud sellier
** Login   <sellie_a@epitech.net>
** 
** Started on  Tue Feb 24 10:12:35 2009 arnaud sellier
** Last update Sun Mar 29 22:28:42 2009 arnaud sellier
*/

#ifndef __MY_SCRIPT
# define __MY_SCRIPT

#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/ioctl.h>
#include <termios.h>
#include <signal.h>
#include <time.h>
#include "os.h"

#if (OS==NUX)
#include <asm/ioctls.h>
#define TIOCGETA TCGETS
#define TIOCSETA TCSETS
#endif

#if (OS==SUN)
#define TIOCGETA TCGETS
#define TIOCSETA TCSETS
#endif

#ifndef TCSANOW
#define TCSANOW         0
#endif


extern char **environ;

typedef struct	s_opt
{
  int		a;
  int		q;
  char		*outfile;
  char		**command;
}		t_opt;

typedef struct	s_glob
{
  char		*outfile;
  int		pid_zombi;
  int		fd_out;
  int		master;
  int		opt_q;
}		t_glob;

/* main.c */
void	usage(char *error);

/* shell.c */
char	*content_env(char *env_var);
char	*find_shell();

/* tools.c */
int	my_strlen(char *str);
void	my_puts(char *str);
int	my_strncmp(char *s1, char *s2, int n);
char	*my_strcpy(char *dest, char *src);
void    *my_memset(void *mem, int c, int len);
void    *my_memcpy(void *dst, void *src, int len);

/* opt.c */
void	init_options(t_opt *opt);
char	*find_options(t_opt *opt, int arg_count, char **arg_values);

/* my_script.c */
t_glob	*get_glob();
void	start_a_shell(t_opt *opt, char *shell, int slave);
void	my_script(t_opt *opt, char *shell);

/* tty_tools.c */
int	*my_openpty(int *master, int *slave, char ttyname[11]);
int	my_login_tty(int fd);
int	my_forkpty(int *master, int *slave);

/* input_output.c */
void	get_sigwinch();
void	input_output(int master, int pid_son);

/* catch_and_quit.c */
void	get_sigusr_one();
void	get_sigchld();
void	done(int pid);
void	quit_permission_denied(char *outfile);

/* term.c */
void	uncanonical();
int     my_tcgetattr(int fd, struct termios *t);
int     my_tcsetattr(int fd, struct termios *t);

#endif /* __MY_SCRIPT */
