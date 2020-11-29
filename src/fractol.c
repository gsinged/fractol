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

void				check_name(t_fractol *f)
{
	if (!(ft_strcmp(f->name, "Julia")))
		f->fractal = fract_julia;
	else if (!(ft_strcmp(f->name, "Mandelbrot")))
		f->fractal = fract_mandelbrot;
}

void		init_fractol(t_fractol *f, char *name)
{
//	f->zoom = ZOOM;
//	f->x_shift = (WIDTH - f->width * f->zoom + MENU_WIDTH) / 2;
//	f->y_shift = (HEIGHT - f->height * f->zoom) / 2;
	if (!(f->mlx_ptr = mlx_init()))
		ft_printerror_mlx(f);
	if (!(f->win_ptr = mlx_new_window(f->mlx_ptr, WIDTH, HEIGHT, name)))
		ft_printerror_mlx(f);
	if (!(f->img_ptr = mlx_new_image(f->mlx_ptr, WIDTH, HEIGHT)))
		ft_printerror_mlx(f);
	if (!(f->data_addr = mlx_get_data_addr(f->img_ptr, &f->bits_per_pixel, \
								&f->size_line, &f->endian)))
		ft_printerror_mlx(f);
	f->name = name;
	check_name(f);
}



t_fractol		*ft_fractol_new(void)
{
	t_fractol		*f;

	if (!(f = (t_fractol*)malloc(sizeof(t_fractol))))
		return (NULL);
	ft_bzero(f, sizeof(t_fractol));
	return (f);
}

int				ft_fractol(char *name)
{
	t_fractol		*f;

	if (!(f = ft_fractol_new()))
		print_error();
	init_fractol(f, name);
	init_init(f);
	draw(f);
	mlx_loop(f->mlx_ptr);
	return (0);
}
