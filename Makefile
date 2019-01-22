# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: domelche <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/09/19 11:58:45 by domelche          #+#    #+#              #
#    Updated: 2019/01/22 15:39:23 by domelche         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = RT

LIBFT_NAME = libft.a

LIBFT_PATH = libft/$(LIBFT_NAME)

LIBMLX_NAME = libmlx.a

LIBMLX_PATH = minilibx/$(LIBMLX_NAME)

LIBPNT_NAME = libpnt.a

LIBPNT_PATH = libpnt/$(LIBPNT_NAME)

SRCS = $(wildcard src/*/*.c)

OBJ = $(SRCS:.c=.o)

HEAD = rtv1.h

CFLAGS = -Wall -Wextra -Werror -pthread -Ilibft -Iminilibx -Ilibpnt -I.

# MacOSX flags

FLAGS = -lmlx -framework OpenGL -framework AppKit

# Linux flags

# FLAGS = -lmlx -lXext -lX11

CC = gcc



.PHONY: all clean fclean re

.NOTPARALLEL: all clean fclean re

all: $(NAME)

$(NAME): $(OBJ)
	@$(MAKE) -C libft
	@$(MAKE) -C minilibx
	@$(MAKE) -C libpnt
	@$(CC) $(CFLAGS) $(SRCS) -o $(NAME) \
		$(LIBFT_PATH) $(LIBMLX_PATH) $(LIBPNT_PATH) $(FLAGS)

clean:
	@/bin/rm -f src/*/*.o
	@$(MAKE) clean -C libft
	@$(MAKE) clean -C minilibx
	@$(MAKE) clean -C libpnt

fclean: clean
	@/bin/rm -f $(NAME)
	@/bin/rm -f $(LIBFT_PATH)
	@/bin/rm -f $(LIBMLX_PATH)
	@/bin/rm -f $(LIBPNT_PATH)

re: fclean all
