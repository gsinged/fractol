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
}

t_color			get_color(t_fractol *f, int iter, double t, int c)
{
	t_color		color;

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
		color.r = c >> 16;
		color.g = c >> 8;
		color.b = c;
	}
	return (color);
}

void			draw_help(t_fractol *f)
{
	int	x;
	int y;

	if (!f->help)
	{
		x = 0.4 * WIDTH;
		y = 0.9 * HEIGHT;
		mlx_string_put(f->mlx_ptr, f->win_ptr, x, y, 0xff00, "HELP - Press H");
		f->help = 1;
	}
	if (f->help == 2)
	{
		x = 0.35 * WIDTH;
		y = 0.02 * HEIGHT;
		mlx_string_put(f->mlx_ptr, f->win_ptr, x, y += 25, 0x00ff00,
					   "Move - Arrows; mouse with LButton");
		mlx_string_put(f->mlx_ptr, f->win_ptr, x, y += 25, 0x00ff00,
					   "Zoom - Wheel");
		mlx_string_put(f->mlx_ptr, f->win_ptr, x, y += 25, 0x00ff00,
					   "Lock Julia - RButton mouse");
		mlx_string_put(f->mlx_ptr, f->win_ptr, x, y += 25, 0x00ff00,
					   "Color setup - 1, 2, 3");
		f->help = 0;
	}
}

void			draw_point(t_fractol *f, int x, int y, t_color color)
{
	int		i;

	if (x >= 0 && x < WIDTH && y >= 0 && y < HEIGHT)
	{
		i = (x * f->bits_per_pixel / 8) + (y * f->size_line);
		f->data_addr[i] = color.b;
		f->data_addr[++i] = color.g;
		f->data_addr[++i] = color.r;
		f->data_addr[++i] = 0;
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
			draw_point(f, x, y, get_color(f, iter, 0, 0));
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
	draw_help(f);
	control_keys(f);
}
