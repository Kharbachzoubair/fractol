/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkharbac <zkharbac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 12:43:08 by zkharbac          #+#    #+#             */
/*   Updated: 2025/04/09 15:50:49 by zkharbac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

long double	parse_number(char *str, int *i)
{
	long double	part;

	part = 0;
	while (str[*i] && str[*i] != '.')
	{
		if (str[*i] < '0' || str[*i] > '9')
			ft_exit();
		if (((part > (INT_MAX - (str[*i] - '0')) / 10)) || 
			(part > (INT_MAX - (str[*i] - '0'))))
			ft_exit();
		part = part * 10 + str[(*i)++] - '0';
	}
	return (part);
}

static int	handle_sign(char *str, int *i)
{
	int	sign;

	sign = 1;
	if (str[*i] == '-')
	{
		sign = -1;
		(*i)++;
	}
	return (sign);
}

static double	parse_integer_part(char *str, int *i)
{
	return (parse_number(str, i));
}

static double	parse_decimal_part(char *str, int *i)
{
	double	dec;

	dec = 0;
	if (str[*i] == '.')
	{
		(*i)++;
		if (str[*i] < '0' || str[*i] > '9')
			ft_exit();
		dec = parse_number(str, i);
	}
	return (dec);
}

double	atodbl(char *str)
{
	double	res;
	double	dec;
	int		sign;
	int		i;

	res = 0;
	dec = 0;
	sign = 1;
	i = 0;
	sign = handle_sign(str, &i);
	res = parse_integer_part(str, &i);
	dec = parse_decimal_part(str, &i);
	if (str[i] != '\0')
		ft_exit();
	return (sign * (res + dec / pow(10, len_num(dec))));
}
