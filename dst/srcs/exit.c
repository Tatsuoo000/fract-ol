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
	ft_putendl_fd("Usage: ./fractol [TYPE] [PARAM1] [PARAM2]\n", 1);
	ft_putendl_fd("-- type list --\n", 1);
	ft_putendl_fd("- m (mandelbrot)", 1);
	ft_putendl_fd("z_0 = 0, z_n+1 = (z_n)^2 + c", 1);
	ft_putendl_fd("example: ./fractol m\n", 1);
	ft_putendl_fd("- j (julia)", 1);
	ft_putendl_fd("param: [a: default(0.32)] [b: default(0.043)]", 1);
	ft_putendl_fd("z_n+1 = (z_n)^2 + c, c = a + bi", 1);
	ft_putendl_fd("example: ./fractol j 0.1 0.4", 1);
	exit(EXIT_SUCCESS);
}

int	put_error(char *str)
{
	ft_putendl_fd("Error", 2);
	ft_putendl_fd(str, 2);
	exit(EXIT_FAILURE);
}
