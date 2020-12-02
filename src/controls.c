/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsinged <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 16:21:48 by gsinged           #+#    #+#             */
/*   Updated: 2020/12/02 16:21:50 by gsinged          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int				exit_hook(t_fractol *f)
{
	ft_fractol_del(f);
	exit(0);
	return (0);
}

void			control_keys(t_fractol *f)
{
	mlx_hook(f->win_ptr, 2, 0, press_key, f);
	mlx_hook(f->win_ptr, 4, 0, mouse_press, f);
	mlx_hook(f->win_ptr, 5, 0, mouse_release_hook, f);
	mlx_hook(f->win_ptr, 6, 0, motion_hook, f);
	mlx_hook(f->win_ptr, 17, 0, exit_hook, f);
}
