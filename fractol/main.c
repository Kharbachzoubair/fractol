/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkharbac <zkharbac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 12:48:02 by zkharbac          #+#    #+#             */
/*   Updated: 2025/04/07 13:24:46 by zkharbac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

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

void draw_square(t_data *img, int x0, int y0, int size, int color)
{
    int x, y;
    
    for (x = x0 ; x < x0 +size ; x++)
    {
        for(y=y0; y<y0+size ; y++)
            {
                my_mlx_pixel_put(img, x, y, color); // Draw the pixel
            }
        
    }
}
#include <stdio.h>

int ft_strncmp(char *s1, char *s2, int n)
{
    int i = 0;
    while (n > 0 && ((s1[i] == s2[i]) && (s1[i] || s2[i])))
    {
        i++;
        n--;
    }
    if (n == 0)
        return 0;
    return (s1[i] - s2[i]);
}

int main(int ac, char **av)
{
    t_fractal fractal;
    if (ac == 2 && ft_strncmp(av[1], "mandelbrot", 11) == 0)
    {
        
        printf("✅ it worked\n");
        fractol_init(&fractal);
    }
    else
        printf("❌ ser bhalk\n");

    return 0;
}
