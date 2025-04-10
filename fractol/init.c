/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkharbac <zkharbac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 12:40:44 by zkharbac          #+#    #+#             */
/*   Updated: 2025/04/09 16:04:00 by zkharbac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	malloc_error(void)
{
	ft_putstr("Problems with malloc");
	exit(EXIT_FAILURE);
}

static void	data_init(t_fractal *fractal)
{
	fractal->escape_value = 4;
	fractal->iterations_definition = 42;
	fractal->zoom = 1.0;
}

static void	events_init(t_fractal *fractol)
{
	mlx_hook(fractol->mlx_window, KEYPRESS, 0, key_handler, fractol);
	mlx_hook(fractol->mlx_window, BUTTONPRESS, 0, mouse_handler, fractol);
	mlx_hook(fractol->mlx_window, DESTROYNOTIFY, 0, close_handler, fractol);
}

void	fractal_init(t_fractal *fractal)
{
	fractal->mlx_connection = mlx_init();
	if (NULL == fractal->mlx_connection)
		malloc_error();
	fractal->mlx_window = mlx_new_window(fractal->mlx_connection, 
			WIDTH, HEIGHT, fractal->name);
	if (NULL == fractal->mlx_window)
	{
		mlx_destroy_window(fractal->mlx_connection, fractal->mlx_window);
		free(fractal->mlx_connection);
		malloc_error();
	}
	fractal->img.img_ptr = mlx_new_image(fractal->mlx_connection, 
			WIDTH, HEIGHT);
	if (NULL == fractal->img.img_ptr)
	{
		mlx_destroy_window(fractal->mlx_connection, fractal->mlx_window);
		free(fractal->mlx_connection);
		malloc_error();
	}
	fractal->img.pixels_ptr = mlx_get_data_addr(fractal->img.img_ptr,
			&fractal->img.bpp, &fractal->img.line_len, &fractal->img.endian);
	events_init(fractal);
	data_init(fractal);
}
