/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control_keys.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsinged <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/29 03:11:52 by gsinged           #+#    #+#             */
/*   Updated: 2020/11/29 03:11:53 by gsinged          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void			ft_exit(t_fractol *f)
{
	ft_fractol_del(f);
	exit(0);
}

void			ft_move(int key, t_fractol *f)
{
	t_complex	delt;

	delt = init_complex(f->max.re - f->min.re, f->max.im - f->min.im);
	if (key == KEY_UP)
	{
		f->min.im -= delt.im * 0.01;
		f->max.im -= delt.im * 0.01;
	}
	else if (key == KEY_DOWN)
	{
		f->min.im += delt.im * 0.01;
		f->max.im += delt.im * 0.01;
	}
	else if (key == KEY_LEFT)
	{
		f->min.re += delt.re * 0.01;
		f->max.re += delt.re * 0.01;
	}
	else if (key += KEY_RIGHT)
	{
		f->min.re -= delt.re * 0.01;
		f->max.re -= delt.re * 0.01;
	}
	draw(f);
}

void			change_color(int key, t_fractol *f)
{
	if (key == KEY_NUM_1)
		f->color = 0;
	else if (key == KEY_NUM_2)
		f->color = 1;
	else if (key == KEY_NUM_3)
		f->color = 2;
	draw(f);
}

void			show_help(t_fractol *f)
{
	if (f->help == 1)
		f->help = 2;
	else if (f->help == 0)
		f->help = 0;
	draw(f);
}

int				press_key(int key, t_fractol *f)
{
	if (key == KEY_ESC)
		ft_exit(f);
	else if (key == KEY_UP || key == KEY_DOWN || key == KEY_LEFT || \
										key == KEY_RIGHT)
		ft_move(key, f);
	else if (key == KEY_H)
		show_help(f);
	else if (key >= KEY_NUM_1 || key <= KEY_NUM_3)
		change_color(key, f);
	return (0);
}
