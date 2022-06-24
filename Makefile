# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bbali <bbali@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/16 18:17:02 by bbali             #+#    #+#              #
#    Updated: 2022/06/23 23:22:45 by bbali            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	so_long
CC			=	gcc
FLAGS		=	-Wall -Wextra -Werror

MLX			=	./libs/mlx/Makefile.gen
LIBFT		=	./libs/libft/libft.a
LIB			=	-L ./libs/libft -lft -L ./libs/mlx -lmlx -lXext -lX11 -lm -lbsd
LIB_DIR		=	libs/libft libs/mlx

INC			=	-I ./inc/ -I ./libs/libft -I ./libs/mlx
OBJ			=	$(patsubst src%, obj%, $(SRC:.c=.o))
SRC			=	src/so_long.c \
				src/init_map.c \
				src/check_map_utils.c \
				src/end_game.c \
				src/init_root.c \
				src/format_map.c \
				src/mlx_utils.c \
				src/render.c \
				src/player_action.c \
				src/input_event.c \
				src/update.c 

BONUS		=	-DBONUS=0
is_BONUS 	=	-DBONUS=1
# ~~~~~~~~~~~~~~~ MANDATORY ~~~~~~~~~~~~~~~ #
all:		install obj $(NAME)
$(NAME):	$(OBJ)
			$(CC) $(FLAGS) -o $@ $^ $(LIB)
# ~~~~~~~~~~~~~~~~ BONUS ~~~~~~~~~~~~~~~~ #
bonus:		fclean install obj
			@make BONUS=$(is_BONUS) $(NAME)

# ~~~~~~~~~~~~~~ REQUIRED LIB ~~~~~~~~~~~~~~ #
install:
	@$(foreach dir, $(LIB_DIR), make -C $(dir);)
re-install:
	@$(foreach dir, $(LIB_DIR), make -C $(dir) re;)
clean-install:
	@$(foreach dir, $(LIB_DIR), make -C $(dir) clean;)

obj:
			@mkdir -p obj
obj/%.o:	src/%.c
			$(CC) $(FLAGS) $(BONUS) $(INC) -o $@ -c $<
# ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ #
clean:		clean-install
			@rm -rf $(OBJ) obj obj_bonus
			@echo "object files deleted."			
fclean:		clean
			@rm -rf $(NAME)
			@echo "binary file deleted."
re:			fclean all

.PHONY:		all clean fclean re bonus
