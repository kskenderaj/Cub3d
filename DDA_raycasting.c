#include "cub3d.h"

void get_ray_direction(t_data *data, int column, double *ray_dx, double *ray_dy) //calculate ray direction
{
    double camera_x;
    double ray_angle;

    camera_x = 2.0 * column / SCREEN_WIDTH - 1.0;
    ray_angle = data->player.angle + atan(camera_x * tan(data->player.fov / 2.0));

    *ray_dx = cos(ray_angle);
    *ray_dy = cos(ray_angle);
}

double dda_cast(t_data *data, double ray_dx, double ray_dy) //DDA stepping
{
    double x;
    double y;
    double step_size;

    step_size = 0.05;
    while(1)
    {
        x += ray_dx * step_size;
        y += ray_dy * step_size;

        int grid_x = (int)(x / data->map.cell_size);
        int grid_y = (int)(y / data->map.cell_size);

        if(grid_x < 0 || grid_x >= data->map.width || 
            grid_y < 0 || grid_y >= data->map.height ||
            data->map.grid[grid_y][grid_x] == 1)
            {
                double distance = sqrt(pow(x - data->player.x, 2) +
                                       pow(y - data->player.y, 2));
                return(distance);
            }
    }
}

double cast_ray(t_data *data, int column)
{
    double ray_dx, ray_dy;

    get_ray_direction(data, column, &ray_dx, &ray_dy);
    return(dda_cast(data, ray_dx, ray_dy));
}