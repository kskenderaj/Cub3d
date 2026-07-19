/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mimacdou <mimacdou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/09 15:51:45 by mimacdou          #+#    #+#             */
/*   Updated: 2026/07/19 09:26:50 by mimacdou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

//////////////////////////LIBRARIES START//////////////////////

# include <math.h>
# include <errno.h>
# include <unistd.h>
# include <sys/time.h>
# include "./Libft/libft.h"
# include "MLX42/MLX42.h"

//////////////////////////LIBRARIES END////////////////////////

//////////////////////////MARCOS START/////////////////////////

# define KEY_ESC 	MLX_KEY_ESCAPE
# define KEY_W 		MLX_KEY_W
# define KEY_A 		MLX_KEY_A
# define KEY_S 		MLX_KEY_S
# define KEY_D 		MLX_KEY_D
# define KEY_LEFT 	MLX_KEY_LEFT
# define KEY_RIGHT 	MLX_KEY_RIGHT

# define START 'N'
# define WALL '1'
# define FLOOR '0'

//////////////////////////MARCOS END///////////////////////////

/////////////////////////STRUCTS START/////////////////////////

typedef enum e_direct
{
	NORTH = 0,
	SOUTH,
	WEST,
	EAST
}	t_dir;

typedef enum e_tex
{
	T_NORTH = 0,
	T_SOUTH,
	T_WEST,
	T_EAST
}	t_tex;

typedef struct s_player
{
	double	x;
	double	y;
	double	dir_x;
	double	dir_y;
	double	plane_x;
	double	plane_y;
	char	starting_direction;
}	t_player;

typedef struct s_mlx
{
	mlx_t		*mlx;
	mlx_image_t	*img;
}	t_mlx;

typedef struct s_texture
{
	void	*img;
	char	*addr;
	int		width;
	int		height;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_texture;

typedef struct s_ray
{
	double	start_x;
	double	start_y;
	double	dir_x;
	double	dir_y;
	double	perp_dist;
	int		side;
	int		step_x;
	int		step_y;
}	t_ray;

typedef struct s_game
{
	t_mlx		mlx;
	t_player	player;
	t_texture	textures[4];
	char		**map;
	char		**floor_color;
	char		**ceiling_color;
}	t_game;

/////////////////////////STRUCTS END///////////////////////////

//////////////////////////FUNCTIONS////////////////////////////

// ARG_CHECKS FUNCTIONS

void		invaild_arg(char *str);
void		f_and_c_checks(char *map);
void		map_checks(char *map_file);
void		actually_xpm_test(char *map);
void		check_args(int ac, char **av);
void		input_content_checks(char *map);
void		extra_input_content_checks(char *map);
void		input_content_extension_checks(char *map);
void		invaild_rgb(int fd, char *line, int flag);
void		additional_rgb_checks(int fd, char *line, int flag);

bool		file_empty(char *file);
bool		exists_check(char *str);
bool		flood_status(int result);
bool		check_first_two_lines(char *texture);
bool		texture_not_empty(char *map, int flag);
bool		flood_matrix(char **matrix, int height);

int			store_house(int flag);

char		*cycle_gnl(int fd, char *to_search);
char		**make_floodfill_matrix(int fd, char *line, char *map_file);

// PARSING FUNCTIONS

void		parser(t_game *game, char *map_file);
void		init_player(t_game *game);
void		init_player(t_game *game);

// FREEING/EXIT FUNCTIONS

void		free_game(t_game *game);
void		free_matrix(char **matrix, int height);

// RENDER FUNCTIONS

void		init_hooks(t_game *game);
void		init_mlx(t_game *game);
void		render_frame(void *param);
void		test_mlx(t_game *game);
void		cast_ray(t_game *game, t_ray *ray, int x);
void		load_textures(t_game *game);
void		put_pixel(t_game *game, int x, int y, int color);
void		game_loop(void *param);
void		load_one_texture(t_game *game, int index);
void		fill_texture_data(t_game *game, t_texture *texture, xpm_t *xpm);

mlx_image_t	*get_texture_image(t_game *game, t_ray *ray);

int			key_press(int keycode, t_game *game);
int			close_window(t_game *game);
int			get_wall_color(t_game *game, t_ray *ray, int y);
int			rgb_to_int(int r, int g, int b);
int			get_texture_index(t_ray *ray);
int			get_tex_x(t_game *game, t_ray *ray, mlx_image_t *image);
int			get_tex_y(int y, mlx_image_t *image);
int			get_tex_pixel(mlx_image_t *image, int tex_x, int tex_y);

////////////////////////FUNCTIONS END//////////////////////////

#endif
