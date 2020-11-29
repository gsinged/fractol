/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsinged <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/29 02:59:43 by gsinged           #+#    #+#             */
/*   Updated: 2020/11/29 02:59:45 by gsinged          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_complex		init_complex(double re, double im)
{
	t_complex	c;

	c.re = re;
	c.im = im;
	return (c);
}

void			init_init(t_fractol *f)
{
	f->min = init_complex(-2, -2);
	f->max.re = 2;
	f->max.im = f->min.im + (f->max.re - f->min.re) * HEIGHT / WIDTH;
	f->fact.re = (f->max.re - f->min.re) / (WIDTH - 1);
	f->fact.im = (f->max.im - f->min.im) / (HEIGHT - 1);
	f->max_iter = ITER;
	f->k = init_complex(1, 1.5);
}

void	draw_point(t_fractol *f, int x, int y, int iter)
{
	int		i;
	double	t;

	t = (double)iter / (double)f->max_iter;
	if (x >= 0 && x < WIDTH && y >= 0 && y < HEIGHT)
	{
		i = (x * f->bits_per_pixel / 8) + (y * f->size_line);
		f->data_addr[i] = (int)(8.5 * pow((1-t), 3) * t * 255);
		f->data_addr[++i] = (int)(15 * pow((1 - t), 2) * pow(t, 2)  * 255);
		f->data_addr[++i] = (int)(9 * (1 - t) * pow(t, 3) * 255);
		f->data_addr[++i] = 0;


//		int color;
//
//		color = 0xffffff;
//
//		f->data_addr[i] = color;
//		f->data_addr[++i] = color >> 8;
//		f->data_addr[++i] = color >> 16;
	}
}

void			draw_map(t_fractol *f)
{
	int		x;
	int 	y;
	int		iter;

	y = 0;
	iter = 0;
	while (y < HEIGHT)
	{
		f->c.im = f->max.im - y * f->fact.im;
		x = 0;
		while (x < WIDTH)
		{
			f->c.re = f->min.re + x * f->fact.re;
			iter = f->fractal(f);
			draw_point(f, x, y, iter);
			x++;
		}
		y++;
	}
}

void			draw(t_fractol *f)
{
	init_init(f);
	draw_map(f);
	mlx_put_image_to_window(f->mlx_ptr, f->win_ptr, f->img_ptr, 0, 0);
	control_keys(f);
}
