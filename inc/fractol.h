/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsinged <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 20:31:56 by gsinged           #+#    #+#             */
/*   Updated: 2020/11/25 20:31:57 by gsinged          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#ifndef FRACTOL_H
# define FRACTOL_H

# include "libft.h"
# include <mlx.h>
# include <math.h>

typedef struct	s_fdf {
	int			**map;
	int			height;
	int			width;
	int			zoom;
	int			x_shift;
	int			y_shift;
	int			z_shift;
	char		iso;
	int			scale;
	void		*mlx_ptr;
	void		*win_ptr;
	void		*img_ptr;
	char		*data_addr;
	int			bits_per_pixel;
	int			size_line;
	int			endian;

}				t_fdf;


int			fractol(char *argv);

#endif
