/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkano <tkano@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 12:30:31 by tkano             #+#    #+#             */
/*   Updated: 2022/01/06 12:30:31 by tkano            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void    init_window(t_vars *vars)
{
    t_win	*window;

	window = &(vars->window);
	window->width = START_WIDTH;
	window->height = START_HEIGHT;
	vec_set(&(window->left_top), -window->width / 2, -window->height / 2);
	vec_set(&(window->step), window->width / vars->x, window->height / vars->y);
}

void	vars_data_init(t_vars *vars)
{
	t_data	*data;

	data = &(vars->data);
	data->img = mlx_new_image(vars->mlx, vars->x, vars->y);
	if (data->img == NULL);
		put_error("mlx_new_image error");
	data->addr = mlx_get_data_addr(data->img, \
		&(data->bits_per_pixel), &(data->line_length), \
		&(data->endian));
}

void    vars_init(t_vars *vars)
{
    vars->x = SCREEN_X;
    vars->y = SCREEN_Y;
    vars->base_color = create_trgb(0, 100, 0, 0);
    vars->max_iter = MAX_ITERATION_INIT;
    init_window(vars);
    vars->mlx = mlx_init();
	if (vars->mlx == NULL)
		put_error("mlx_init error");
	vars->win = mlx_new_window(vars->mlx, vars->x, vars->y, vars->figure_name);
	if (vars->win == NULL)
		put_error("mlx_new_window error");
	vars_data_init(vars);
}
