/*
** tools.c for my_script in /home/sellie_a/local/c/my_script
** 
** Made by arnaud sellier
** Login   <sellie_a@epitech.net>
** 
** Started on  Tue Feb 24 10:15:56 2009 arnaud sellier
** Last update Sun Mar 29 22:34:45 2009 arnaud sellier
*/

#include "main.h"

int	my_strlen(char *str)
{
  int	i;

  i = -1;
  while (str[++i]);
  return (i);
}

void	my_puts(char *str)
{
  write(1, str, my_strlen(str));
  write(1, "\n", 1);
}

int	my_strncmp(char *s1, char *s2, int n)
{
  int	i;

  i = 0;
  while (s1[i] && s2[i] && (i < n))
    {
      if (s1[i] != s2[i])
	return (s1[i] - s2[i]);
      i++;
    }
  return (s1[i] - s2[i]);
}

char	*my_strcpy(char *dest, char *src)
{
  int	i;

  i = 0;
  while (src[i])
    {
      dest[i] = src[i];
      i++;
    }
  dest[i] = 0;
  return (dest);
}

void		*my_memset(void *mem, int c, int len)
{
  int		i;
  unsigned char ch = (unsigned char)c;
  char		*set;

  set = (char *)mem;
  i = 0;
  while (i < len)
    {
      *(set + i) = ch;
      i++;
    }
  return (mem);
}
