/*
** client_next.c for minitalk in /home/rotaru_i
**
** Made by Iulian Rotaru
** Login   <rotaru_i@epitech.net>
**
** Started on  Thu Feb 11 16:54:12 2016 Iulian Rotaru
** Last update Sun Feb 21 11:57:55 2016 Iulian Rotaru
*/

#include <unistd.h>
#include <stdlib.h>
#include <signal.h>
#include "minitalk.h"

extern t_tools	g_tools;

int		my_strlen(const char *str)
{
  int		i;

  i = 0;
  if (str == NULL)
    return (0);
  while (str[i])
    i++;
  return (i);
}

int		my_getnbr(const char *nb)
{
  int		multi;
  int		out;
  int		i;

  i = my_strlen(nb) - 1;
  multi = 1;
  out = 0;
  while (i >= 0)
    {
      if (nb[i] >= '0' && nb[i] <= '9')
	out += (nb[i] - 48) * multi;
      if (nb[i] == '-')
	out = - out;
      multi *= 10;
      i--;
    }
  return (out);
}

int		is_it_posnum(const char *str)
{
  int		i;

  i = 0;
  while (str[i])
    {
      if (str[i] < '0' || str[i] > '9')
	return (1);
      i++;
    }
  return (0);
}

void		trafic_handler_next(int signal)
{
  if (signal == SIGUSR2)
    {
      if (g_tools.nb == 2)
	g_tools.nb = 0;
      else if (g_tools.nb == 1)
	{
	  write(2, "Trafic error : Signals conflict found\n", 38);
	  exit(0);
	  g_tools.nb = 3;
	}
    }
}

void		trafic_handler(int signal)
{
  if (signal == SIGUSR1)
    {
      if (g_tools.nb == 1)
	g_tools.nb = 0;
      else if (g_tools.nb == 2)
	{
	  write(2, "Trafic error : Signals conflict found\n", 38);
	  exit(0);
	  g_tools.nb = 3;
	}
    }
  trafic_handler_next(signal);
}
