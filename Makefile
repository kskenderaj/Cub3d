NAME = cub3D
CC = cc
UNAME_S := $(shell uname -s)

LIBFT = Libft/libft.a

ifeq ($(UNAME_S),Linux)
MLX_PATH = ./minilibx_linux
MLX_BUILD = $(MLX_PATH)/build
MLX = $(MLX_BUILD)/libmlx42.a
MLX_INCLUDE = -isystem$(MLX_PATH)/include    
MLX_LINK = -ldl -lglfw -pthread -lm
CLEAN_MLX = rm -rf $(MLX_BUILD)
else
MLX_PATH = ./minilibx_macos
MLX = $(MLX_PATH)/libmlx42.a
MLX_INCLUDE = -isystem$(MLX_PATH)           
MLX_LINK = -L/opt/homebrew/lib -L/opt/homebrew/opt/glfw/lib -lglfw -framework OpenGL -framework AppKit -framework IOKit -framework CoreFoundation -lm
CLEAN_MLX =
endif

FLAGS = -Wall -Wextra -Werror -I. $(MLX_INCLUDE) -g3 -O0
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
		src/render/norm_helper \
		src/render/extra_norm_helper \

SRCS = $(addsuffix .c, $(SRC))
OBJS = $(addsuffix .o, $(SRC))

HEADERS = cub3d.h

.DEFAULT_GOAL := all

$(OBJS): %.o: %.c
	$(CC) $(FLAGS) -c $< -o $@

all: $(NAME)

$(NAME): $(LIBFT) $(MLX) $(OBJS)
	$(CC) $(FLAGS) $(OBJS) $(LIBFT) $(MLX) $(MLX_LINK) -o $(NAME)

$(LIBFT):
		$(MAKE) -C Libft FLAGS="$(FLAGS)"

ifeq ($(UNAME_S),Linux)
$(MLX):
	cmake -S $(MLX_PATH) -B $(MLX_BUILD)
	$(MAKE) -C $(MLX_BUILD) -j$$(nproc)
endif

clean:
	rm -f *.o src/*/*.o
	$(MAKE) -C Libft clean
	$(CLEAN_MLX)

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C Libft fclean

re: fclean all

.PHONY: all clean fclean re