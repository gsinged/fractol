/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_a.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsinged <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 16:29:05 by gsinged           #+#    #+#             */
/*   Updated: 2020/12/02 16:29:06 by gsinged          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

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
		mlx_string_put(f->mlx_ptr, f->win_ptr, x, y += 25, 0x00ff00, \
					"Move - Arrows; mouse with LButton");
		mlx_string_put(f->mlx_ptr, f->win_ptr, x, y += 25, 0x00ff00, \
					"Zoom - Wheel");
		mlx_string_put(f->mlx_ptr, f->win_ptr, x, y += 25, 0x00ff00, \
					"Lock Julia - RButton mouse");
		mlx_string_put(f->mlx_ptr, f->win_ptr, x, y += 25, 0x00ff00, \
					"Color setup - 1, 2, 3");
		f->help = 0;
	}
}
