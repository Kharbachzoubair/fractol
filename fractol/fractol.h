/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkharbac <zkharbac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 13:16:39 by zkharbac          #+#    #+#             */
/*   Updated: 2025/04/07 17:12:25 by zkharbac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

#include <mlx.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

#define WIDTH	800
#define	HEIGHT	800

typedef struct s_img
{
    void    *img_ptr;
    char    *pixels_ptr;
    int     bpp;
    int     endian;
    int     line_len;
}t_img;

typedef struct s_fractal

{
    char    *name;
    void    *mlx_connection;
    void    *mlx_window;
    t_img   img;
}t_fractal;








#endif

