/*
** pid_it.c for minitalk in /home/rotaru_i
**
** Made by Iulian Rotaru
** Login   <rotaru_i@epitech.net>
**
** Started on  Thu Feb 11 16:59:44 2016 Iulian Rotaru
** Last update Sun Feb 21 12:09:51 2016 Iulian Rotaru
*/

#include "minitalk.h"

extern t_tools	g_tools;

void		pid_it_next(int sigo)
{
  if (sigo == - 1)
    {
      g_tools.nb = 0;
      g_tools.tmpid = 0;
    }
}

void	set_globs()
{
  g_tools.nb = 0;
  g_tools.letter = 0;
  g_tools.tmpid = 0;
  g_tools.pid = - 1;
}
