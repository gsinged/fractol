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
	f->max_iter = ITER;
//	f->k = init_complex(-0.75, 0.25);
}

t_color			get_color(t_fractol *f, int iter)
{
	double		t;
	t_color		color;
	int			c;

	t = (double) iter / (double) f->max_iter;
	ft_bzero(&color, sizeof(t_color));
	if (f->color == 0)
	{
		color.r = (int)(9 * (1 - t) * pow(t, 3) * 255);
		color.g = (int)(15 * pow((1 - t), 2) * pow(t, 2) * 255);
		color.b = (int)(8.5 * pow((1 - t), 3) * t * 255);
	}
	else if (f->color == 1)
	{
		c = (int)((double)(0xffffff) * (int)t);
		color.r = c >> 16;
		color.g = c >> 8;
		color.b = c;
	}
	else if (f->color == 2)
	{
		c = (int)((double)(0xffffff) * (1 - t));
//		ft_printf("iter = %d, c = %d\n", iter, c);
		color.r = c >> 16;
		color.g = c >> 8;
		color.b = c;
	}

//	ft_printf("setup_color %d\n", f->color);
	return (color);
}

void			draw_point(t_fractol *f, int x, int y, t_color color)
{
	int		i;
//	double	t;

	if (x >= 0 && x < WIDTH && y >= 0 && y < HEIGHT)
	{
		i = (x * f->bits_per_pixel / 8) + (y * f->size_line);
		f->data_addr[i] = color.b;
		f->data_addr[++i] = color.g;
		f->data_addr[++i] = color.r;
		f->data_addr[++i] = 0;

//		ft_printf("#RGB %d %d %d\n", color.r, color.g, color.b);

//		int color;
//
//		t = 1 - t;
//		color = 0xffffff;
//		color = (int)((double)color * t);
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
			draw_point(f, x, y, get_color(f, iter));
			x++;
		}
		y++;
	}
}

void			draw(t_fractol *f)
{
	f->fact.re = (f->max.re - f->min.re) / (WIDTH - 1);
	f->fact.im = (f->max.im - f->min.im) / (HEIGHT - 1);
	draw_map(f);
	mlx_put_image_to_window(f->mlx_ptr, f->win_ptr, f->img_ptr, 0, 0);
	control_keys(f);
}
