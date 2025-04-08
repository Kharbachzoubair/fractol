/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkharbac <zkharbac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 12:21:37 by zkharbac          #+#    #+#             */
/*   Updated: 2025/04/08 18:10:17 by zkharbac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	key_handler(int key, t_fractal *fractol)
{
	if (key == ESC_KEY)
		close_handler(fractol);
	else if (key == PLUS_KEY)
		fractol->iterations_defintion += 1;
	else if (key == MINUS_KEY)
		fractol->iterations_defintion -= 1;
	fractal_render(fractol);
	return (0);
}

int	mouse_handler(int button, int x, int y, t_fractal *fractol)
{
	(void)x;
	(void)y;
	if (button == 4)
		fractol->zoom *= 1.05;
	else if (button == 5)
		fractol->zoom /= 1.05;
	fractal_render(fractol);
	return (0);
}

int	close_handler(t_fractal *fractol)
{
	mlx_destroy_window(fractol->mlx_connection, fractol->mlx_window);
	free(fractol->mlx_connection);
	ft_putstr("\033[1;31m.\n..\n...\n👀 Whoa! \nEscaping? Fine... "
		"shutting down Fract'ol.\n\nSee you in another dimension! 🌌🔮\033[0m\n");
	exit(0);
}

int	julia_track(int x, int y, t_fractal *fractal)
{
	if (!ft_strncmp(fractal->name, "julia", 5))
	{
		fractal->julia_x = (map(x, -2, +2, WIDTH) * fractal->zoom)
			+ fractal->shift_x;
		fractal->julia_y = (map(y, +2, -2, HEIGHT) * fractal->zoom)
			+ fractal->shift_y;
		fractal_render(fractal);
	}
	return (0);
}
