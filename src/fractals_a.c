/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractals_a.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsinged <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 16:25:19 by gsinged           #+#    #+#             */
/*   Updated: 2020/12/02 16:25:20 by gsinged          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

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

int				fract_burning_ship(t_fractol *f)
{
	int			iter;
	t_complex	z;

	iter = 0;
	z = init_complex(f->c.re, f->c.im);
	while ((pow(z.re, 2) + pow(z.im, 2) <= 4) && iter < f->max_iter)
	{
		z = init_complex(
				pow(z.re, 2) - pow(z.im, 2) + f->c.re,
				-2.0 * fabs(z.re * z.im) + f->c.im);
		iter++;
	}
	return (iter);
}
