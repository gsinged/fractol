/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsinged <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 22:04:45 by gsinged           #+#    #+#             */
/*   Updated: 2020/11/25 22:04:46 by gsinged          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		check_name(char *name)
{
	if (!(ft_strcmp(name, "Julia")))
		return (1);
	else if (!(ft_strcmp(name, "Mandelbrot")))
		return (2);
	return (0);
}

int		fractol(char *argv)
{

	return (0);
}
