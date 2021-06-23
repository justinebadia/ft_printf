# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jbadia <jbadia@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/22 09:38:55 by jbadia            #+#    #+#              #
#    Updated: 2021/06/23 08:57:45 by jbadia           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS=ft_printf.c \
		ft_convert_utohex.c \
		ft_itoa.c \
		ft_print_c.c \
		ft_print_d.c \
		ft_print_p_str.c \
		ft_print_percent.c \
		ft_print_s.c \
		ft_print_u.c \
		ft_printf_flags_utils.c \
		ft_printf_type_utils.c \
		ft_printf_utils.c \
		ft_printf_n_bonus.c \
	

CC = gcc
NAME = libftprintf.a
CFLAGS = -Wall -Wextra -Werror
OBJS= $(SRCS:.c=.o)
LIB_PATH = ./libft
INCLUDES= ./includes

.c.o:
	 ${CC} ${CFLAGS} -c $< -o ${<:.c=.o} -I${INCLUDES}

$(NAME): $(OBJS)
	$(MAKE) bonus -C $(LIB_PATH)
	cp libft/libft.a $(NAME)
	ar -rcs $(NAME) $(OBJS)

bonus : re

all:$(NAME)

clean:
		$(MAKE) clean -C ./libft
		rm -f $(OBJS)

fclean: clean
		$(MAKE) fclean -C ./libft
		rm -f $(NAME)

re: fclean all

.PHONY:	all clean fclean re