/*
** server.c for minitalk in /home/rotaru_i
**
** Made by Iulian Rotaru
** Login   <rotaru_i@epitech.net>
**
** Started on  Thu Feb  4 11:54:14 2016 Iulian Rotaru
** Last update Sun Feb 21 12:09:37 2016 Iulian Rotaru
*/

#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include "minitalk.h"

t_tools	g_tools;

int	char_builder(int bit)
{
  if (bit == 1)
    {
      g_tools.letter += 1 << g_tools.nb;
      g_tools.nb++;
    }
  if (bit == 0)
    g_tools.nb++;
  if (g_tools.nb == 8)
    {
      g_tools.nb = 0;
      write(1, &g_tools.letter, 1);
      g_tools.letter = 0;
    }
  if (bit == - 1)
    {
      g_tools.nb = 0;
      g_tools.letter = 0;
    }
  return (0);
}

void	receiver(int signal)
{
  if (signal == SIGUSR1)
    {
      g_tools.timer = 1;
      char_builder(1);
      if (kill(g_tools.pid, SIGUSR1) < 0)
	exit(- 1);
    }
  if (signal == SIGUSR2)
    {
      g_tools.timer = 1;
      char_builder(0);
      if (kill(g_tools.pid, SIGUSR2) < 0)
	exit(- 1);
    }
}

void	pid_it(int sigo)
{
  if (sigo == SIGUSR1)
    {
      g_tools.tmpid += 1 << g_tools.nb;
      g_tools.nb++;
    }
  if (sigo == SIGUSR2)
    g_tools.nb++;
  if (g_tools.nb == 32)
    {
      g_tools.nb = 0;
      if ((signal(SIGUSR1, receiver) == SIG_ERR) ||
	  (signal(SIGUSR2, receiver) == SIG_ERR))
	exit(- 1);
      g_tools.pid = g_tools.tmpid;
      if (kill(g_tools.pid, SIGUSR1) < 0)
	exit(- 1);
    }
  pid_it_next(sigo);
}

void	my_put_nbr(int nb)
{
  char	lie;

  if (nb < 0)
    {
      nb = - nb;
      write(1, "-", 1);
    }
  if (nb >= 10)
    my_put_nbr(nb / 10);
  lie = nb % 10 + 48;
  write(1, &lie, 1);
}

int	main()
{
  my_put_nbr((int)getpid());
  if ((signal(SIGUSR1, pid_it) == SIG_ERR) ||
      (signal(SIGUSR2, pid_it) == SIG_ERR))
    return (- 1);
  set_globs();
  while (42)
    {
      while (g_tools.pid != - 1)
	{
	  g_tools.timer = 0;
	  usleep(50000);
	  if (g_tools.timer == 0)
	    {
	      char_builder(- 1);
	      pid_it(- 1);
	      g_tools.pid = - 1;
	      if ((signal(SIGUSR1, pid_it) == SIG_ERR) ||
		  (signal(SIGUSR2, pid_it) == SIG_ERR))
		return (- 1);
	    }
	}
    }
  return (0);
}
