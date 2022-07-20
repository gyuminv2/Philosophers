# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gyumpark <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/18 17:33:20 by gyumpark          #+#    #+#              #
#    Updated: 2022/03/18 17:33:22 by gyumpark         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS		=	ft_atoi.c\
			ft_bzero.c\
			ft_calloc.c\
			ft_isalnum.c\
			ft_isalpha.c\
			ft_isascii.c\
			ft_isdigit.c\
			ft_isprint.c\
			ft_itoa.c\
			ft_memchr.c\
			ft_memcmp.c\
			ft_memcpy.c\
			ft_memmove.c\
			ft_memset.c\
			ft_putchar_fd.c\
			ft_putendl_fd.c\
			ft_putnbr_fd.c\
			ft_putstr_fd.c\
			ft_strchr.c\
			ft_strdup.c\
			ft_strjoin.c\
			ft_strlcat.c\
			ft_strlcpy.c\
			ft_strlen.c\
			ft_strmapi.c\
			ft_strncmp.c\
			ft_strnstr.c\
			ft_strrchr.c\
			ft_strtrim.c\
			ft_substr.c\
			ft_striteri.c\
			ft_tolower.c\
			ft_toupper.c\
			ft_isnum.c\

OBJS = $(SRCS:.c=.o)

SRCS_BONUS	=	ft_lstadd_back.c\
			ft_lstadd_front.c\
			ft_lstclear.c\
			ft_lstdelone.c\
			ft_lstiter.c\
			ft_lstlast.c\
			ft_lstmap.c\
			ft_lstnew.c\
			ft_lstsize.c

OBJS_BONUS = $(SRCS_BONUS:.c=.o)

NAME = libft.a
CC = gcc
CFLAGS = -Wall -Wextra -Werror
RM = rm -rf
AR = ar rcs

all : $(NAME)

$(NAME) : $(OBJS)
						$(CC) $(CFLAGS) -c $(SRCS) -I./
						$(AR) $@ $^

clean :
						$(RM) $(OBJS) $(OBJS_BONUS)

fclean : clean
						$(RM) $(NAME) $(BONUS)

re : fclean all

bonus: $(NAME)
						$(CC) $(CFLAGS) -c $(SRCS_BONUS) -I./
						$(AR) $(NAME) $(OBJS_BONUS)

.PHONY : all clean fclean re
