/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printerror.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsinged <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 22:32:12 by gsinged           #+#    #+#             */
/*   Updated: 2020/11/25 22:32:14 by gsinged          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void			ft_printerror_mlx(t_fractol *f)
{
	ft_fractol_del(f);
	ft_putendl_fd("MLX error", 2);
	exit(0);
}

void			print_error(void)
{
	ft_putendl_fd(strerror(errno), 2);
	exit(0);
}
