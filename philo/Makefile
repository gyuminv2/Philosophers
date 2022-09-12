# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gyumpark <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/26 21:19:45 by gyumpark          #+#    #+#              #
#    Updated: 2022/09/12 19:38:12 by gyumpark         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo
CC = cc
\CFLAGS = -fsanitize=address -g3
\CFLAGS = -fsanitize=thread -g3
CFLAGS = -Wall -Wextra -Werror
INC = ./includes

SRCS = $(addprefix ./srcs/, main.c check_input.c init.c thread.c philo.c monitor.c util.c)
OBJS = $(SRCS:.c=.o)

FTDIR = ./libft/
FT = libft.a
FTINC = ./libft/

RM = rm -rf

all: $(NAME)

$(NAME): $(OBJS)
	make -j 4 all -C $(FTDIR)
	cp $(FTDIR)$(FT) ./$(FT)
	$(CC) $(CFLAGS) -I$(INC) -I$(FTINC) -o $@ $^ libft.a

%.o : %.c
	$(CC) $(CFLAGS) -I$(INC) -I$(FTINC) -c $^ -o $@

clean:
	make fclean -C $(FTDIR)
	$(RM) $(OBJS)

fclean:	clean
	$(RM) $(NAME)
	$(RM) $(FT)
	$(RM) *.dSYM

re: fclean all

.PHONY: all clean fclean re
