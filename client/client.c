/*
** client.c for minitalk in /home/rotaru_i
**
** Made by Iulian Rotaru
** Login   <rotaru_i@epitech.net>
**
** Started on  Thu Feb  4 11:33:02 2016 Iulian Rotaru
** Last update Sun Feb 21 12:21:40 2016 Iulian Rotaru
*/

#include <unistd.h>
#include <stdlib.h>
#include <signal.h>
#include "minitalk.h"

t_tools		g_tools;

void		send_int(int mail, pid_t pid)
{
  int		i;

  i = 0;
  while (i < 32)
    {
      if (1 << i & mail)
	{
	  if (kill(pid, SIGUSR1) < 0)
	    exit(- 1);
	}
      else
	{
	  if (kill(pid, SIGUSR2) < 0)
	    exit(- 1);
	}
      usleep(5000);
      i++;
    }
}

void		live(int sig)
{
  if (sig == SIGUSR1)
    g_tools.timer = 1;
}

int		check_error(int argc, char **argv)
{
  if (argc != 3)
    {
      write(2, "Usage: ./client server_pid message\n", 35);
      return (1);
    }
  if (is_it_posnum(argv[1]) == 1)
    {
      write(2, "Wrong pid\n", 10);
      return (1);
    }
  return (0);
}

void		sender(char **argv, pid_t pid)
{
  unsigned char	decal;

  while (*argv[2])
    {
      decal = 0;
      while (decal < 8)
	{
	  if (1 << decal & *argv[2])
	    send_one(pid);
	  else
	    send_zero(pid);
	  decal++;
	}
      ++argv[2];
    }
}

int		main(int argc, char **argv)
{
  pid_t		pid;

  if ((signal(SIGUSR1, live) == SIG_ERR) ||
      (signal(SIGUSR2, live) == SIG_ERR))
    return (- 1);
  if (check_error(argc, argv) == 1)
    return (1);
  pid = my_getnbr(argv[1]);
  g_tools.timer = 0;
  send_int(getpid(), pid);
  usleep(5000);
  if (g_tools.timer == 0)
    {
      write(2, "Error: Server might be busy or down\n", 36);
      return (- 1);
    }
  if ((signal(SIGUSR1, trafic_handler) == SIG_ERR) ||
      (signal(SIGUSR2, trafic_handler) == SIG_ERR))
    return (- 1);
  sender(argv, pid);
  return (0);
}
