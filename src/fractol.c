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

static void		init_fdf(t_fdf *f)
{
	f->zoom = ZOOM;
	f->iso = 1;
	f->x_shift = (WIDTH - f->width * f->zoom + MENU_WIDTH) / 2;
	f->y_shift = (HEIGHT - f->height * f->zoom) / 2;
	if (!(f->mlx_ptr = mlx_init()))
		ft_printerror_mlx(f);
	if (!(f->win_ptr = mlx_new_window(f->mlx_ptr, WIDTH, HEIGHT, TITLE)))
		ft_printerror_mlx(f);
	if (!(f->img_ptr = mlx_new_image(f->mlx_ptr, WIDTH, HEIGHT)))
		ft_printerror_mlx(f);
	if (!(f->data_addr = mlx_get_data_addr(f->img_ptr, &f->bits_per_pixel, \
								&f->size_line, &f->endian)))
		ft_printerror_mlx(f);
}

int		check_name(char *name)
{
	if (!(ft_strcmp(name, "Julia")))
		return (1);
	else if (!(ft_strcmp(name, "Mandelbrot")))
		return (2);
	return (0);
}

int				ft_fractol1(char *name)
{
	*name = '\0';

	return (0);
}
