  
# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bboisset <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/14 17:54:40 by bboisset          #+#    #+#              #
#    Updated: 2019/11/26 14:21:05 by bboisset         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	libft.a

SRCS	= 	ft_memset.c ft_bzero.c ft_memcpy.c ft_memccpy.c \
			ft_memmove.c ft_memchr.c ft_memcmp.c ft_strlen.c \
			ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c \
			ft_isprint.c ft_toupper.c ft_tolower.c ft_strchr.c \
			ft_strrchr.c ft_strncmp.c ft_strlcpy.c ft_strlcat.c \
			ft_strnstr.c ft_atoi.c ft_calloc.c ft_strdup.c ft_substr.c \
			ft_char_to_string.c ft_itoa.c ft_lstadd_back.c \
			ft_lstnew.c ft_number_length.c ft_putstr.c ft_strcpy.c \
			ft_strjoin.c ft_strlowcase.c ft_strrev.c ft_lstfree.c \
			ft_lstsize.c

OBJS	= $(SRCS:.c=.o)

CC		= gcc

GFLAGS	= -Wall -Wextra -Werror

RM		= rm -f

all: $(NAME)


$(NAME): $(OBJS)
			  ar -rcs $(NAME) $(OBJS)

%.o: %.c
		$(CC) $(GFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

fmake:	clean
		make

re: fclean all

.PHONY: all fclean re
