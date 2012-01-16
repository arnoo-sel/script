/*
** shell.c for my_script in /home/sellie_a/local/c/my_script
** 
** Made by arnaud sellier
** Login   <sellie_a@epitech.net>
** 
** Started on  Tue Feb 24 10:16:48 2009 arnaud sellier
** Last update Tue Feb 24 10:17:04 2009 arnaud sellier
*/

#include "main.h"

char	*content_env(char *env_var)
{
  int	i;

  i = 0;
  while (env_var[i] != '=')
    i++;
  return (env_var + i + 1);
}

char	*find_shell()
{
  int	i;

  i = 0;
  while (environ[i])
    {
      if ((my_strncmp(environ[i], "SHELL", 4) == 0) && (environ[i][5] == '='))
	return (content_env(environ[i]));
      i++;
    }
  return ("/bin/sh");
}
