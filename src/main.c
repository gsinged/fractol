/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsinged <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 20:32:03 by gsinged           #+#    #+#             */
/*   Updated: 2020/11/25 20:32:04 by gsinged          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int			print_usage(void)
{
	ft_putendl("usage: ./fractol [Name fractal]");
	ft_putstr("Name:\tJulia\n\tMandelbrot\n\tJulia4\n\tMandelbrot4\n");
	ft_putstr("\tMandelbar\n\tCeltic_Mandelbar\n");
	return (0);
}

int				check_name_main(char *name)
{
	if (!(ft_strcmp(name, "Julia")))
		return (1);
	else if (!(ft_strcmp(name, "Mandelbrot")))
		return (1);
	else if (!(ft_strcmp(name, "Julia4")))
		return (1);
	else if (!(ft_strcmp(name, "Mandelbrot4")))
		return (1);
	else if (!(ft_strcmp(name, "Mandelbar")))
		return (1);
	else if (!(ft_strcmp(name, "Celtic_Mandelbar")))
		return (1);
	return (0);
}

int			main(int argc, char **argv)
{
	if (argc != 2)
		return (print_usage());
	if (!(check_name_main(argv[1])))
		return (print_usage());
	ft_fractol(argv[1]);
	return (0);
}
