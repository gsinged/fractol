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
		z.re = pow(z.re, 2) - pow(z.im, 2) + f->k.re;
		z.im = 2 * z.re * z.im + f->k.im;
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
		z.re = pow(z.re, 2) - pow(z.im, 2) + f->c.re;
		z.im = 2 * z.re * z.im + f->c.im;
		iter++;
	}
	return (iter);
}
