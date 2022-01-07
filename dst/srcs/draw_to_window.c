/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_to_window.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkano <tkano@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/27 16:07:48 by tkano             #+#    #+#             */
/*   Updated: 2021/12/27 16:07:48 by tkano            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	pos_vec_set(t_vars *vars, int x, int y, t_vec *dst)
{
	vec_set(dst, vars->window.left_top.x + x *vars->window.step.x, \
			vars->window.left_top.y + y * vars->window.step.y);
}

void	clear_image(t_vars *vars)
{
	int	point[2];

	point[0] = 0;
	while (point[0] < vars->x)
	{
		point[1] = 0;
		while (point[1] < vars->y)
		{
			my_mlx_pixel_put(&(vars->data), point[0], point[1], 0);
			++point[1];
		}
		++point[0];
	}
}

int	draw_image(t_vars *vars)
{
	int		color;
	int		point[2];
	t_vec	vec;
	int		n;

	point[1] = 0;
	while (point[1] < vars->x)
	{
		point[0] = 0;
		while (point[0] < vars->y)
		{
			pos_vec_set(vars, point[0], point[1], &vec);
			n = vars->func(vars, &vec);
			color = color_add(vars->base_color, n * 10);
			if (n < 0)
				return (ERROR);
			if (n > 0)
				my_mlx_pixel_put(&(vars->data), point[0], point[1], color);
			++point[0];
		}
		++point[1];
	}
	return (SUCCESS);
}
