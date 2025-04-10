/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkharbac <zkharbac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 12:56:23 by zkharbac          #+#    #+#             */
/*   Updated: 2025/04/09 14:11:50 by zkharbac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] && s2[i] && s1[i] == s2[i])
		i++;
	return (s1[i] - s2[i]);
}

void	ft_putstr(char *s)
{
	while (*s)
		write(1, s++, 1);
}

void	ft_exit(void)
{
	ft_putstr("\033[1;31m🚨 ERROR: Invalid input! "
		"Please provide a valid number.\033[0m\n");
	exit(1);
}

int	len_num(double num)
{
	int	len;

	len = 0;
	while (num > 1)
	{
		num /= 10;
		len++;
	}
	return (len);
}
