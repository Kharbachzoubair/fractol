/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkharbac <zkharbac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 12:48:02 by zkharbac          #+#    #+#             */
/*   Updated: 2025/04/05 16:25:32 by zkharbac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <unistd.h>
#include <math.h>

typedef struct s_data {
    void    *img;
    char    *addr;
    int     bits_per_pixel;
    int     line_length;
    int     endian;
}             t_data;

void my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
    char *dst;

    dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
    *(unsigned int*)dst = color;
}

void draw_circle(t_data *data, int win_width, int win_height)
{
    int x, y;
    int cx = win_width / 2; // center x
    int cy = win_height / 2; // center y
    int r = 100; // radius
    int color = 0x00FF0000; // Red color

    for (x = 0; x < win_width; x++)
    {
        for (y = 0; y < win_height; y++)
        {
            // Check if the point (x, y) lies on the circle
            if (pow(x - cx, 2) + pow(y - cy, 2) <= pow(r, 2))
            {
                my_mlx_pixel_put(data, x, y, color); // Draw the pixel
            }
        }
    }
}

int main(void)
{
    void    *mlx;
    void    *mlx_win;
    t_data  img;
    int     win_width = 800;
    int     win_height = 600;

    mlx = mlx_init();
    mlx_win = mlx_new_window(mlx, win_width, win_height, "Circle");
    img.img = mlx_new_image(mlx, win_width, win_height);
    img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);

    // Draw the circle in the middle of the window
    draw_circle(&img, win_width, win_height);

    // Put the image on the window
    mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);

    // Enter the main loop to display the window
    mlx_loop(mlx);

    return (0);
}
 