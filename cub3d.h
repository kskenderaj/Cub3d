#ifndef CUB3D_H
#define CUB3D_H

#include <mlx.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#define SCREEN_WIDTH 1920
#define SCREEN_HEIGHT 1080
#define TEXTURE_SIZE 64

//Player Data
typedef struct s_player
{
    double x;
    double y;
    double angle;
    double fov;
}   t_player;

//Map Data
typedef struct s_map
{
    //partner data
    int **grid;
    int width;
    int height;
    int cell_size;
}t_map;

//Texture data (XPMS)
typedef struct s_texture
{
    int *data;
    int width;
    int height;
}   t_texture;

typedef struct s_textures
{
    t_texture no;//North
    t_texture so;//South
    t_texture we;//West
    t_texture ea;//East
}   t_textures;

typedef struct s_colors
{
    int floor;
    int ceiling;
}   t_colors;

//Image rendering
typedef struct s_image
{
    void    *img;
    int     *data;
    int     bpp;
    int     line_length;
    int     endian;
}   t_image;

//Main Data
typedef struct s_data
{
    void    *mlx;
    void    *win;
    t_image img;
    t_map   map;
    t_player player;
    t_textures textures;
    t_colors colors;
}   t_data;

int render_frame(t_data *data);
int keyhook(int keycode , t_data *data);
int mouse_hook(int x, int y, t_data *data);
int close_window(t_data *data);

#endif