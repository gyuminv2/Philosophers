# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gyumpark <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/26 21:19:45 by gyumpark          #+#    #+#              #
#    Updated: 2022/05/28 16:14:43 by gyumpark         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo
SRCS = ./main.c
OBJS = $(SRCS:.c=.o)

CC = cc
\CFLAG = -Wall -Wextra -Werror
CFLAG = -fsanitize=address -g3
RM = rm -rf

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAG) $(SRCS) -o $(NAME)

clean:
	$(RM) $(OBJS)

fclean:	clean
	$(RM) $(NAME)
	$(RM) *.dSYM

re: fclean all

.PHONY: all clean fclean re
