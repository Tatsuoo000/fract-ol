/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkano <tkano@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/27 11:57:25 by tkano             #+#    #+#             */
/*   Updated: 2021/12/27 11:57:25 by tkano            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * \
						(data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	put_image_to_window(t_vars *vars)
{
	if (draw_image(vars))
		put_error("error");
	mlx_put_image_to_window(vars->mlx, vars->win, vars->data.img, 0, 0);
}

int	main(int argc, char **argv)
{
	t_vars	vars;

	arg_parse(&vars, argc, argv);
	vars_init(&vars);
	put_image_to_window(&vars);
	mlx_loop(vars.mlx);
}
