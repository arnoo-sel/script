/*
** main.c for my_script in /home/sellie_a/local/c/my_script
** 
** Made by arnaud sellier
** Login   <sellie_a@epitech.net>
** 
** Started on  Tue Feb 24 09:40:29 2009 arnaud sellier
** Last update Sun Mar 29 21:59:10 2009 arnaud sellier
*/

#include "main.h"

void	usage(char *error)
{
  if (error)
    my_puts(error);
  my_puts("Usage: my_script [-aq] [file [command ...]]");
  exit(-1);
}

int	main(int ac, char **av)
{
  char	*shell;
  t_opt opt;

  opt.outfile = find_options(&opt, ac - 1, av + 1);
  shell = find_shell();
  my_script(&opt, shell);
  return (0);
}
