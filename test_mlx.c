#include <mlx.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct s_data {
    void    *mlx;
    void    *win;
}   t_data;

int key_hook(int keycode ,t_data data)
{
    if(keycode == 65307)
    {
        mlx_destroy_display(data->mlx);
    }
}