/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control_mouse.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsinged <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/30 21:48:48 by gsinged           #+#    #+#             */
/*   Updated: 2020/11/30 21:48:49 by gsinged          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int			motion_hook(int x, int y, t_fractol *f)
{
	t_complex	c;
	t_complex	c_prev;

	ft_printf("x = %d, y = %d\n", x, y);
	ft_printf("f->julia = %d\n", f->julia);
	if (f->julia == 1)
	{
		f->k.im = f->max.im - y * f->fact.im;
		f->k.re = f->min.re + x * f->fact.re;
	}
	else if (f->mouse.on)
	{
		c.re = f->min.re + x * f->fact.re;
		c.im = f->max.im - y * f->fact.im;
		c_prev.re = f->min.re + f->mouse.x * f->fact.re;
		c_prev.im = f->max.im - f->mouse.y * f->fact.im;
		f->min.re += c_prev.re - c.re;
		f->min.im += c_prev.im - c.im;
		f->max.re += c_prev.re - c.re;
		f->max.im += c_prev.im - c.im;
	}
	f->mouse.x = x;
	f->mouse.y = y;
	draw(f);
	return (0);
}


void			print_min_max(t_fractol *f)
{
	ft_printf("min.re = %d\nmax.re = %d\n", f->min.re, f->max.re);
	ft_printf("min.im = %d\nmax.im %d\n\n", f->min.im, f->max.im);
}

void			zoom(int mouse, int x, int y, t_fractol *f)
{
	double		z;
	t_complex	c;

//	print_min_max(f);
	c.re = f->min.re + x * f->fact.re;
	c.im = f->max.im - y * f->fact.im;
	z = -1.1;
	if (mouse == MOUSE_UP)
		z = -0.9;
	f->min.re = c.re + (c.re - f->min.re) * z;
	f->min.im = c.im + (c.im - f->min.im) * z;
	f->max.re = c.re + (c.re - f->max.re) * z;
	f->max.im = c.im + (c.im - f->max.im) * z;
//	print_min_max(f);
	draw(f);
}

int			mouse_press(int mouse, int x, int y, t_fractol *f)
{
	ft_printf("%d\n", mouse);
	if (mouse == MOUSE_UP || mouse == MOUSE_DOWN)
		zoom(mouse, x, y, f);
	else if (mouse == MOUSE_1)
		f->mouse.on = 1;
	else if (mouse == MOUSE_2)
	{
		if (f->julia == 1)
			f->julia = 2;
		else if (f->julia == 2)
			f->julia = 1;
	}
	return (0);
}

int			mouse_release_hook(int mouse, int x, int y, t_fractol *f)
{
	if (mouse == MOUSE_1)
		f->mouse.on = 0;
	x = y;
	return (0);
}