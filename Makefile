# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aulamber <aulamber@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/04/27 19:56:54 by aulamber          #+#    #+#              #
#    Updated: 2014/05/18 23:39:17 by aulamber         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 	=			ft_minishell2

SRC		=	./

INCDIR 	=	includes/

SOURCE 	=	main.c \
			other_functions.c \
			builtins.c \
			builtin_cd.c \
			other1.c \
			other2.c \
			other3.c \

OBJ 	=		$(SOURCE:.c=.o)

LIBDIR 	=	libft/

LIB 	=		$(LIBDIR)libft.a

LIB_COMP =	-L ./$(LIBDIR) -lft

CC 		=		gcc

FLAG =		-I $(INCDIR) -Wall -Wextra -Werror -g

RED = \033[33;31m
BLUE = \033[33;34m
GREEN = \033[33;32m
RESET = \033[0m

.PHONY: all re fclean

all: $(NAME)

$(LIB):
		@$(MAKE) -C $(LIBDIR)

$(NAME): $(LIB) $(OBJ)
		@$(CC) -o $(NAME) $(FLAG) $^ $(LIB_COMP)
		@echo "[$(GREEN)Compilation $(BLUE)$(NAME) $(GREEN)ok$(RESET)]"

%.o: %.c
		@$(CC) -c -o $@ $(FLAG) $^

clean:
	@cd $(LIBDIR) && $(MAKE) $@
	@rm -f $(OBJ)
	@echo "[$(RED)Supression des .o de $(BLUE)$(NAME) $(GREEN)ok$(RESET)]"

fclean: clean
		@cd $(LIBDIR) && $(MAKE) $@
		@rm -f $(NAME)
		@echo "[$(RED)Supression de $(BLUE)$(NAME) $(GREEN)ok$(RESET)]"

re: fclean all
