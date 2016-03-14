/*
** minitalk.h for minitalk in /home/rotaru_i/Coding/PSU/PSU_2015_minitalk/inc
**
** Made by Iulian Rotaru
** Login   <rotaru_i@epitech.net>
**
** Started on  Thu Feb 11 16:11:55 2016 Iulian Rotaru
** Last update Sun Feb 21 12:21:24 2016 Iulian Rotaru
*/

#ifndef MINITALK_H_
# define MINITALK_H_

typedef struct	s_tools
{
  int	pid;
  int	timer;
  int	nb;
  int	tmpid;
  unsigned char	letter;
}		t_tools;

void	trafic_handler(int signal);
void	pid_it_next(int sigo);
int	my_getnbr(const char *nb);
void	send_one(const unsigned int pid);
void	send_zero(const unsigned int pid);
int	is_it_posnum(const char *str);
void	set_globs();

#endif /* !MINITALK_H_ */
