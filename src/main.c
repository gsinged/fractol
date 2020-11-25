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
	ft_putendl("usage: ./fractol [Name]");
	ft_putendl("Name:\tJulia\n\tMandelbrot\n");
	return (0);
}

int			main(int argc, char **argv)
{
	if (argc != 2)
		return (print_usage());
	fractol(argv[1]);
	return (0);
}
