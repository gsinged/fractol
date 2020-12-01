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
# include "keys.h"
# include <mlx.h>
# include <math.h>
# include <stdlib.h>
# include <errno.h>

# define TITLE "Fractol"
# define WIDTH 1000
# define HEIGHT 1000
# define MENU_WIDTH 300
# define ZOOM 40
# define ITER 50

typedef struct	s_mouse
{
	int			x;
	int 		y;
	int			on;
}				t_mouse;

typedef struct	s_complex
{
	double		re;
	double		im;
}				t_complex;

typedef struct	s_fractol {
	int			height;
	int			width;
	char		*name;
	t_mouse		mouse;
	int			julia;
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
	t_complex	min;
	t_complex	max;
	t_complex	c;
	t_complex	k;
	t_complex	fact;
	int			max_iter;
	int 		(*fractal)(struct s_fractol *f);
}				t_fractol;

int				ft_fractol(char *name);
t_complex		init_complex(double re, double im);
void			init_init(t_fractol *f);
void			draw_map(t_fractol *f);

int 			fract_julia(t_fractol *f);
int 			fract_mandelbrot(t_fractol *f);

void			draw(t_fractol *f);
void			control_keys(t_fractol *f);
int				mouse_press(int mouse, int x, int y, t_fractol *f);
int				mouse_release_hook(int mouse, int x, int y, t_fractol *f);
int				motion_hook(int x, int y, t_fractol *f);

void			ft_printerror_mlx(t_fractol *f);
void			print_error(void);


#endif
