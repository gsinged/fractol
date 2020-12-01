/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractals.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsinged <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/29 00:14:07 by gsinged           #+#    #+#             */
/*   Updated: 2020/11/29 00:14:10 by gsinged          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int 			fract_julia(t_fractol *f)
{
	int			iter;
	t_complex	z;

	iter = 0;
	z = init_complex(f->c.re, f->c.im);
	while ((pow(z.re, 2) + pow(z.im, 2) <= 4) && iter < f->max_iter)
	{
		z = init_complex(
				pow(z.re, 2) - pow(z.im, 2) + f->k.re,
				2 * z.re * z.im + f->k.im);
		iter++;
	}
	return (iter);
}

int				fract_mandelbrot(t_fractol *f)
{
	int			iter;
	t_complex	z;

	iter = 0;
	z = init_complex(f->c.re, f->c.im);
	while ((pow(z.re, 2) + pow(z.im, 2) <= 4) && iter < f->max_iter)
	{
		z = init_complex(
				pow(z.re, 2) - pow(z.im, 2) + f->c.re,
				2.0 * z.re * z.im + f->c.im);
		iter++;
	}
	return (iter);
}

int				fract_julia4(t_fractol *f)
{
	int			iter;
	t_complex	z;

	iter = 0;
	z = init_complex(f->c.re, f->c.im);
	while ((pow(z.re, 2) + pow(z.im, 2) <= 4) && iter < f->max_iter)
	{
		z = init_complex(
				pow(z.re, 4) + pow(z.im, 4) + f->k.re,
				4 * pow(z.re, 3) * z.im - 4 * z.re * pow(z.im, 3) + f->k.im);
		iter++;
	}
	return (iter);
}

int				fract_mandelbrot4(t_fractol *f)
{
	int			iter;
	t_complex	z;

	iter = 0;
	z = init_complex(f->c.re, f->c.im);
	while ((pow(z.re, 2) + pow(z.im, 2) <= 4) && iter < f->max_iter)
	{
		z = init_complex(
				pow(z.re, 4) + pow(z.im, 4) + f->c.re,
				4 * pow(z.re, 3) * z.im - 4 * z.re * pow(z.im, 3) + f->c.im);
		iter++;
	}
	return (iter);
}


int				fract_mandelbar(t_fractol *f)
{
	int			iter;
	t_complex	z;

	iter = 0;
	z = init_complex(f->c.re, f->c.im);
	while ((pow(z.re, 2) + pow(z.im, 2) <= 4) && iter < f->max_iter)
	{
		z = init_complex(
				pow(z.re, 2) - pow(z.im, 2) + f->c.re,
				-2.0 * z.re * z.im + f->c.im);
		iter++;
	}
	return (iter);
}

int				fract_celtic_mandelbar(t_fractol *f)
{
	int			iter;
	t_complex	z;

	iter = 0;
	z = init_complex(f->c.re, f->c.im);
	while ((pow(z.re, 2) + pow(z.im, 2) <= 4) && iter < f->max_iter)
	{
		z = init_complex(
				fabs(pow(z.re, 2) - pow(z.im, 2)) + f->c.re,
				-2.0 * z.re * z.im + f->c.im);
		iter++;
	}
	return (iter);
}
