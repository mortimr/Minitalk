/*
** senders.c for minitalk in /home/rotaru_i
**
** Made by Iulian Rotaru
** Login   <rotaru_i@epitech.net>
**
** Started on  Thu Feb 11 16:57:35 2016 Iulian Rotaru
** Last update Sun Feb 21 11:59:59 2016 Iulian Rotaru
*/

#include <stdlib.h>
#include <signal.h>
#include "minitalk.h"

extern t_tools	g_tools;

void		send_one(const unsigned int pid)
{
  g_tools.nb = 1;
  if (kill(pid, SIGUSR1) < 0)
    exit(- 1);
  while (g_tools.nb != 0 && g_tools.nb != 3);
}

void		send_zero(const unsigned int pid)
{
  g_tools.nb = 2;
  if (kill(pid, SIGUSR2) < 0)
    exit(- 1);
  while (g_tools.nb != 0 && g_tools.nb != 3);
}
