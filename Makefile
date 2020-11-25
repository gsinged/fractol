# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gsinged <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/11/25 21:24:20 by gsinged           #+#    #+#              #
#    Updated: 2020/11/25 21:24:21 by gsinged          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol

CC = gcc
FLAGS = -Wall -Werror -Wextra -O3
INCLUDES = -I$(INCDIR) -I$(FTDIR)/inc/ -I$(FTDIR)/ft_printf/inc/ -I$(MINILIBX_H)
LIBRARIES = -lmlx -lm -lft -L$(FTDIR) -L$(MINILIBX_DIR) -framework OpenGL -framework AppKit


SRCDIR  = ./src/
INCDIR  = ./inc/
OBJDIR  = ./obj/
FTDIR   = ./libft/

FTNAME = libft.a

INC = fractol.h

SRC =	main.c ft_printerror.c

OBJ	= $(addprefix $(OBJDIR),$(SRC:.c=.o))

LIBFT = $(FTDIR)$(FTNAME)


MINILIBX = $(MINILIBX_DIR)libmlx.a
MINILIBX_DIR = ./minilibx_macos/
MINILIBX_H = $(MINILIBX_DIR)


.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(LIBFT) $(MINILIBX) $(OBJ)
	$(CC) $(OBJ) $(LIBRARIES) -o $(NAME)

$(LIBFT):
	@make -C $(FTDIR)

$(MINILIBX):
	@make -sC $(MINILIBX_DIR)

$(OBJDIR):
	@mkdir -p $(OBJDIR)

$(OBJDIR)%.o: $(SRCDIR)%.c $(INCDIR)$(INC) | $(OBJDIR)
	$(CC) $(FLAGS) -c $(INCLUDES) $< -o $@

clean:
	@make -sC $(FTDIR) clean
	@make -sC $(MINILIBX_DIR) clean
	@rm -rf $(OBJDIR)

fclean: clean
	@make -sC $(FTDIR) fclean
	@rm -f $(NAME)

re: fclean all