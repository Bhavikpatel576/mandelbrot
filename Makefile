# /* ************************************************************************** */
# /*                                                                            */
# /*                                                        :::      ::::::::   */
# /*   makefile                                           :+:      :+:    :+:   */
# /*                                                    +:+ +:+         +:+     */
# /*   By: bpatel <marvin@42.fr>                      +#+  +:+       +#+        */
# /*                                                +#+#+#+#+#+   +#+           */
# /*   Created: 2017/03/09 14:36:11 by bpatel            #+#    #+#             */
# /*   Updated: 2017/03/09 14:36:13 by bpatel           ###   ########.fr       */
# /*                                                                            */
# /* ************************************************************************** */


FILENAMES	= draw.c init_window.c keyhooks.c fractals.c threads.c\
	main.c

ASAN		= -fsanitize=address
NAME		= frac
CC			= gcc
CFLAGS		+= -Wall -Werror -Wextra -Ofast
INC			+= -Iincludes/

SRCS		= $(addprefix srcs/, $(FILENAMES))
OBJS		= $(addprefix build/, $(FILENAMES:.c=.o))

LIBFT		= ./libft/libft.a
LIBFTINC	= -I./libft/includes
LIBFTLINK	= -L./libft -lft

LIBMLX		= ./minilibx_macos/libmlx.a 
LIBMLXINC	= -I./minilibx_macos/
LIBMLXLINK	= -L./minilibx_macos -lmlx -framework OpenGL -framework AppKit -Iminilibx_macos

.PHONY: all clean fclean re

all: libft $(NAME) clean

build:
	mkdir $@

build/%.o: srcs/%.c | build
	$(CC) $(CFLAGS) $(ASAN) $(INC) $(LIBFTINC) $(LIBMLXINC) -o $@ -c $<

libft: $(LIBFT)

$(LIBFT):
	make -C ./libft

libmlx: $(LIBMLX)

$(LIBMLX):
	make -C ./minilibx_macos

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(ASAN) $(AFLAGS) $(INC) $(LIBFTLINK) $(LIBMLXLINK) -o $@ $^

clean:
	rm -rf build/

fclean: clean
	rm -f $(NAME)

re: fclean all
