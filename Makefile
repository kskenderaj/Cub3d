# **************************************************************************** #
#                                 CONFIGURATION                                #
# **************************************************************************** #

NAME		= cub3D
CC			= cc
CFLAGS		= -Wall -Wextra -Werror -g
RM			= rm -rf

# **************************************************************************** #
#                                   MINILIBX                                   #
# **************************************************************************** #

MLX_REPO	= https://github.com/42Paris/minilibx-linux.git
MLX_DIR		= ./minilibx-linux
MLX_LIB		= $(MLX_DIR)/libmlx.a
MLX_FLAGS	= -L$(MLX_DIR) -lmlx -lXext -lX11 -lm

# **************************************************************************** #
#                                    SOURCES                                   #
# **************************************************************************** #

# Add your source files here (adjust names as needed)
SRCS		= main.c \
			  parse.c \
			  raycast.c \
			  movement.c \
			  utils.c

OBJS		= $(SRCS:.c=.o)

# **************************************************************************** #
#                                    RULES                                     #
# **************************************************************************** #

all: $(MLX_LIB) $(NAME)

# Clone and compile minilibx if not already present
$(MLX_LIB):
	@if [ ! -d "$(MLX_DIR)" ]; then \
		echo "Cloning minilibx-linux..."; \
		git clone $(MLX_REPO) $(MLX_DIR); \
	fi
	@echo "Compiling minilibx..."
	cd $(MLX_DIR) && ./configure

# Compile cub3D
$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(MLX_FLAGS) -o $(NAME)

# Compile object files with minilibx header path
%.o: %.c
	$(CC) $(CFLAGS) -I$(MLX_DIR) -c $< -o $@

clean:
	$(RM) $(OBJS)
	@if [ -d "$(MLX_DIR)" ]; then \
		echo "Cleaning minilibx object files..."; \
		cd $(MLX_DIR) && make clean; \
	fi

fclean: clean
	$(RM) $(NAME)
	$(RM) $(MLX_DIR)

re: fclean all

# Optional: remove only the minilibx directory
mlxclean:
	$(RM) $(MLX_DIR)

.PHONY: all clean fclean re mlxclean