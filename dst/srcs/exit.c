/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkano <tkano@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 12:26:06 by tkano             #+#    #+#             */
/*   Updated: 2022/01/06 12:26:06 by tkano            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	put_help(void)
{
	ft_putendl_fd("fractol accepts parameters as follows.", 1);
	ft_putendl_fd("./fractol [type] [param]", 1);
	ft_putendl_fd("-- type list --\n", 1);
	ft_putendl_fd("- m (mandelbrot)", 1);
	ft_putendl_fd("The Mandelbrot set is given as the set of points C\n\
that converge with the following asymptotic formula", 1);
	ft_putendl_fd("z_0 = 0, z_n+1 = (z_n)^2 + c", 1);
	ft_putendl_fd("example: ./fractol m\n", 1);
	ft_putendl_fd("- n (mandelbrot2)", 1);
	ft_putendl_fd("change the squared to the nth power.", 1);
	ft_putendl_fd("example: ./fractol n 3\n", 1);
	ft_putendl_fd("- j (julia)", 1);
	ft_putendl_fd("param: [a(double)] [b(double)]", 1);
	ft_putendl_fd("The Julia set is given as the set of points z_0\n\
that converge with the following asymptotic formula", 1);
	ft_putendl_fd("z_n+1 = (z_n)^2 + c, c = a + bi", 1);
	ft_putendl_fd("example: ./fractol j 0.1 0.4", 1);
	ft_putendl_fd("If you don't specify a or b,\n\
the default values will be applied. (a = 0.3, b = 0.2)\n", 1);
	ft_putendl_fd("- k (julia2)", 1);
	ft_putendl_fd("change the squared to the nth power.", 1);
	ft_putendl_fd("example: ./fractol k 0.1 0.4 3\n", 1);
	exit(EXIT_SUCCESS);
}

int	put_error(char *str)
{
	ft_putendl_fd("Error", 2);
	ft_putendl_fd(str, 2);
	exit(EXIT_FAILURE);
}
