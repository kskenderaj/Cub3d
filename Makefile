# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: klejdi <klejdi@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/02/23 17:11:10 by mimacdou          #+#    #+#              #
#    Updated: 2026/07/03 18:29:34 by klejdi           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3D
CC = cc
MLX_PATH = ./minilibx_macos
FLAGS = -Wall -Wextra -Werror -I$(MLX_PATH) -g3 -O0
LIBFT = Libft/libft.a
MLX = $(MLX_PATH)/libmlx42.a
FRAMEWORKS = -L/opt/homebrew/lib -L/opt/homebrew/opt/glfw/lib -lglfw -framework OpenGL -framework AppKit -framework IOKit -framework CoreFoundation -lm
SRC = \
		main \
		src/arg_checks/check_args \
		src/arg_checks/input_content_checks	\
		src/arg_checks/extra_input_content_checks \
		src/arg_checks/ex_ex_input_content_checks \
		src/arg_checks/additional_rgb_checks \
		src/arg_checks/map_checks \
		src/arg_checks/extra_map_checks	\
		src/arg_checks/check_utils \
		src/parsing/first \
		src/parsing/player \
		src/render/test_mlx \
		src/render/exit \
		src/render/hooks \
		src/render/input \
		src/render/mlx_init \
		src/render/render \
		src/render/raycasting \
		src/render/graphics \
		src/clean_up/janitor \

SRCS = $(addsuffix .c, $(SRC))
OBJS = $(addsuffix .o, $(SRC))

HEADERS = cub3D.h

%.o: %.c $(HEADERS)
	$(CC) $(FLAGS) -c $< -o $@

all: $(NAME)

$(LIBFT):
		$(MAKE) -C Libft FLAGS="$(FLAGS)"

$(NAME): $(LIBFT) $(OBJS)
		$(CC) $(FLAGS) $(OBJS) $(LIBFT) $(MLX) $(FRAMEWORKS) -o $(NAME)

clean:
	rm -f *.o src/*/*.o
	$(MAKE) -C Libft clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C Libft fclean

re: fclean all

.PHONY: all clean fclean re
