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

int				deal_key(int key, t_fractol *f)
{
	if (key == KEY_ESC)
		ft_exit(f);
//	else if (key == KEY_UP || key == KEY_DOWN || key == KEY_LEFT || \
//										key == KEY_RIGHT)
//		ft_move(key, f);
//	else if (key == KEY_I || key == KEY_P)
//		ft_change_projection(key, f);
//	if (key == KEY_PLUS || key == KEY_MINUS)
//		ft_scale(key, f);
	return (0);
}


void		control_keys(t_fractol *f)
{
	mlx_key_hook(f->win_ptr, deal_key, f);
}

