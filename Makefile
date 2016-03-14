##
## Makefile for minitalk in /home/rotaru_i
## 
## Made by Iulian Rotaru
## Login   <rotaru_i@epitech.net>
## 
## Started on  Thu Feb  4 11:39:19 2016 Iulian Rotaru
## Last update Sun Feb 21 12:21:00 2016 Iulian Rotaru
##

CC	= gcc

CFLAGS	+= -I./inc -W -Wall -Wextra -Werror

RM	= rm -rf

NAME0	= ./client/client

NAME1	= ./server/server

SRCS0	= ./client/client.c \
	  ./client/client_next.c \
	  ./client/senders.c

SRCS1	= ./server/server.c \
	  ./server/pid_it.c

OBJ0	= $(SRCS0:.c=.o)

OBJ1	= $(SRCS1:.c=.o)

all: $(NAME0) $(NAME1)

$(NAME0): $(OBJ0)
	$(CC) -o $(NAME0) $(OBJ0)
	@echo -e "\033[3;34m"
	@echo -e "//=========================\\\\\\\\\n||=========================||\n||  Done building client   ||\n||=========================||\n\\\\\\\\=========================//"
	@echo -e " \033[0m"

$(NAME1): $(OBJ1)
	$(CC) -o $(NAME1) $(OBJ1)
	@echo -e "\033[3;32m"
	@echo -e "//=========================\\\\\\\\\n||=========================||\n||  Done building server   ||\n||=========================||\n\\\\\\\\=========================//"
	@echo -e " \033[0m"

clean:
	$(RM) $(OBJ0)
	$(RM) $(OBJ1)

fclean: clean
	$(RM) $(NAME0)
	$(RM) $(NAME1)

re: fclean all
