/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klejdi <klejdi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/09 15:51:45 by mimacdou          #+#    #+#             */
/*   Updated: 2026/07/03 18:29:32 by klejdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
#define CUB3D_H

//////////////////////////LIBRARIES START//////////////////////

#include <math.h>
#include <errno.h>
#include <sys/time.h>
#include "./Libft/libft.h"
#include "MLX42/MLX42.h"

//////////////////////////LIBRARIES END////////////////////////

//////////////////////////MARCOS START/////////////////////////

#define KEY_ESC MLX_KEY_ESCAPE
#define KEY_W MLX_KEY_W
#define KEY_A MLX_KEY_A
#define KEY_S MLX_KEY_S
#define KEY_D MLX_KEY_D
#define KEY_LEFT MLX_KEY_LEFT
#define KEY_RIGHT MLX_KEY_RIGHT

#define START 'N'
#define WALL '1'
#define FLOOR '0'

//////////////////////////MARCOS END///////////////////////////

/////////////////////////STRUCTS START/////////////////////////

typedef enum e_direct
{
	NORTH = 0,
	SOUTH,
	WEST,
	EAST
} t_dir; // not sure where to use this? - Michael

typedef enum e_tex
{
	T_NORTH = 0,
	T_SOUTH,
	T_WEST,
	T_EAST
} t_tex;

typedef struct s_player
{
	double x; // double? because the player will be moving between cells = e.g. x = 2.5 y = 3.5
	double y;
	double dir_x; // direction vector to where the player looks at - used for back and forward moves & raycasting direction e.g.dir_x = 0 dir_y = -1 = looking to north
	double dir_y;
	double plane_x;			 // represents the camera's view plan, defines FOV (campo de vision) e.g. dir_x = -1; dir_y = 0;plane_x = 0; plane_y = 0.66; 0.66 = FOV of 66"
	double plane_y;			 // used for calculate each camera window laser direction & generate 3D efect
	char starting_direction; // added by Michael
} t_player;

typedef struct s_mlx
{
	mlx_t *mlx;
	mlx_image_t *img;
} t_mlx;

typedef struct s_texture // each texture has its own image, its own buffer & its own dimensions - used to pick what pixel to draw in the wall (raycasting)
{
	void *img;	// off-screen buffer (image in memory) - to draw here not directly to the window(no parpadeos)
	char *addr; // image memory address - to write the pixels e.g. addr[y * line_length + x * (bpp / 8)] = color;
	int width;
	int height;
	int bits_per_pixel; // usually 32 - bytes in a pixel
	int line_length;	// bytes per line/row - it's not always width * bpp, can't be calculated by hand
	int endian;			// bytes order - MLX gives this, we only use it - orden de bytes
} t_texture;

typedef struct s_ray
{
	double start_x;
	double start_y;
	double dir_x;
	double dir_y;
	double perp_dist;
	int side;
} t_ray;

typedef struct s_game
{
	t_mlx mlx;			   // for all graphic related - mlx context and rendering data
	t_player player;	   // player state (position + direction)
	t_texture textures[4]; // wall textures NO,SO,WE,EA - orden tbc with parsing - indexed by t_tex enum - floor & ceiling are not textures - they're colours(int)
	char **map;			   // parsed map, each char represents a tile e.g. map[y][x] == '1' = the wall
	char **floor_color;	   // color RGB converted to an int,parsing fills it and render uses it (same for ceiling)
	char **ceiling_color;  // Done by Michael, changed to char ** so we can store the individual rgb numbers from ft_split
} t_game;

/////////////////////////STRUCTS END///////////////////////////

//////////////////////////FUNCTIONS////////////////////////////

// ARG_CHECKS FUNCTIONS

void invaild_arg(char *str);
void f_and_c_checks(char *map);
void map_checks(char *map_file);
void actually_xpm_test(char *map);
void check_args(int ac, char **av);
void input_content_checks(char *map);
void extra_input_content_checks(char *map);
void input_content_extension_checks(char *map);
void invaild_rgb(int fd, char *line, int flag);
void additional_rgb_checks(int fd, char *line, int flag);

bool file_empty(char *file);
bool exists_check(char *str);
bool flood_status(int result);
bool check_first_two_lines(char *texture);
bool texture_not_empty(char *map, int flag);
bool flood_matrix(char **matrix, int height);

int store_house(int flag);

char *cycle_gnl(int fd, char *to_search);
char **make_floodfill_matrix(int fd, char *line, char *map_file);

// PARSING FUNCTIONS

void parser(t_game *game, char *map_file);
void init_player(t_game *game);
void init_player(t_game *game);

// FREEING/EXIT FUNCTIONS

void free_game(t_game *game);
void free_matrix(char **matrix, int height);

// RENDER FUNCTIONS

int key_press(int keycode, t_game *game);
void init_hooks(t_game *game);
int close_window(t_game *game);
void init_mlx(t_game *game);
void render_frame(t_game *game);
void test_mlx(t_game *game);
void cast_ray(t_game *game, t_ray *ray, int x);
void put_pixel(t_game *game, int x, int y, int color);
int get_wall_color(t_game *game, t_ray *ray, int y);
int rgb_to_int(int r, int g, int b);
void game_loop(void *param);
////////////////////////FUNCTIONS END//////////////////////////

#endif
