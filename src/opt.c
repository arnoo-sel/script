/*
** opt.c for my_script in /home/sellie_a/local/c/my_script
** 
** Made by arnaud sellier
** Login   <sellie_a@epitech.net>
** 
** Started on  Tue Feb 24 10:47:59 2009 arnaud sellier
** Last update Sun Mar 29 19:43:44 2009 arnaud sellier
*/

#include "main.h"

void	init_options(t_opt *opt)
{
  opt->a = 0;
  opt->q = 0;
}

char	*find_options(t_opt *opt, int arg_count, char **arg_values)
{
  int	i;
  int	j;

  init_options(opt);
  i = -1;
  while ((++i < arg_count) && (arg_values[i][0] == '-'))
    {
      j = 0;
      while (arg_values[i][++j])
	if (arg_values[i][j] == 'a')
	  opt->a = 1;
	else if (arg_values[i][j] == 'q')
	  opt->q = 1;
	else
	  usage("Unknow option");
    }
  opt->command = NULL;
  if (i < arg_count)
    {
      if ((i + 1) < arg_count)
	opt->command = arg_values + i + 1;
      return (arg_values[i]);
    }
  else
    return ("typescript");
}
