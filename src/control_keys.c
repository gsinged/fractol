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
	f->iso = 0;
	exit (0);
}

void		ft_move(int key, t_fractol *f)
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

int				press_key(int key, t_fractol *f)
{
	ft_printf("%d\n", key);
	if (key == KEY_ESC)
		ft_exit(f);
	else if (key == KEY_UP || key == KEY_DOWN || key == KEY_LEFT || \
										key == KEY_RIGHT)
		ft_move(key, f);
	else if (key >= KEY_NUM_1 || key <= KEY_NUM_3)
		change_color(key, f);
	return (0);
}

int			exit_hook(t_fractol *f)
{
	f->iso = 0;
	exit(0);
	return (0);
}

void		control_keys(t_fractol *f)
{
	mlx_hook(f->win_ptr, 2, 0, press_key, f);
	mlx_hook(f->win_ptr, 4, 0, mouse_press, f);
	mlx_hook(f->win_ptr, 5, 0, mouse_release_hook, f);
	mlx_hook(f->win_ptr, 6, 0, motion_hook, f);
	mlx_hook(f->win_ptr, 17, 0, exit_hook, f);
}
