/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkharbac <zkharbac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 13:15:47 by zkharbac          #+#    #+#             */
/*   Updated: 2025/04/07 13:15:48 by zkharbac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>

void    *factal_init(t_fractal *fractal)
{
    fractal->mlx_connection=mlx_init();
    if(fractal->mlx_connection==NULL)
    {
        malloc_error();
    }
    fractal->mlx_window = mlx_new_window(fractal->mlx_connection,
                                        WIDTH,
                                        HEIGHT,
                                        fractal->name);
    if(fractal->mlx_window==NULL)
    {
        mlx_destroy_display(fractal->mlx_window,fractal->mlx_connection);
        free(fractal->mlx_connection);
        malloc_error();
    }
}
