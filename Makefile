# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gyumpark <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/26 21:19:45 by gyumpark          #+#    #+#              #
#    Updated: 2022/07/09 15:32:57 by gyumpark         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo
CC = cc
CFLAG = -fsanitize=address -g3
\CFLAG = -Wall -Wextra -Werror
INC = ./includes

SRCS = $(addprefix ./srcs/, main.c init.c thread.c check_input.c)
OBJS = $(SRCS:.c=.o)

FTDIR = ./libft/
FT = libft.a
FTINC = ./libft/

RM = rm -rf

all: $(NAME)

$(NAME): $(OBJS)
	make all -C $(FTDIR)
	cp $(FTDIR)$(FT) ./$(FT)
	$(CC) $(CFLAG) -I$(INC) -I$(FTINC) -o $@ $^ libft.a

%.o : %.c
	$(CC) $(CFLAG) -I$(INC) -I$(FTINC) -c $^ -o $@

clean:
	make fclean -C $(FTDIR)
	$(RM) $(OBJS)

fclean:	clean
	$(RM) $(NAME)
	$(RM) $(FT)
	$(RM) *.dSYM

re: fclean all

.PHONY: all clean fclean re
