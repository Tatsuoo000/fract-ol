/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_mlx_hook.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkano <tkano@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/09 11:48:24 by tkano             #+#    #+#             */
/*   Updated: 2022/01/09 19:04:35 by tkano            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	control_num_key(int *color, int key)
{
	if (key < ONE_KEY || ONE_KEY + 2 < key)
		return (FALSE);
	else if (key == ONE_KEY)
		*color = create_trgb(0, 100, 0, 0);
	else if (key == ONE_KEY + 1)
		*color = create_trgb(0, 0, 100, 0);
	else if (key == ONE_KEY + 2)
		*color = create_trgb(0, 30, 200, 0);
	return (TRUE);
}

int	control_arrow_key(int *x, int *y, int key)
{
	*x = 0;
	*y = 0;
	if (key == RIGHT_KEY)
		*x = SLIDE_STEP;
	if (key == LEFT_KEY)
		*x = -SLIDE_STEP;
	if (key == DOWN_KEY)
		*y = SLIDE_STEP;
	if (key == UP_KEY)
		*y = -SLIDE_STEP;
	return (key == RIGHT_KEY || key == LEFT_KEY || \
			key == DOWN_KEY || key == UP_KEY);
}

int	control_key_hook(int key, t_vars *vars)
{
	int	x;
	int	y;
	int	color;

	if (key == ESC_KEY)
		exit(SUCCESS);
	else if (control_arrow_key(&x, &y, key))
	{
		slide_window(vars, x, y);
		mlx_clear_window(vars->mlx, vars->win);
		clear_image(vars);
		put_image_to_window(vars);
	}
	else if (control_num_key(&color, key))
	{
		vars->base_color = color;
		mlx_clear_window(vars->mlx, vars->win);
		clear_image(vars);
		put_image_to_window(vars);
	}
	return (SUCCESS);
}

int	control_mouse_hook(int button, int x, int y, t_vars *vars)
{
	double	rate;

	rate = 0;
	if (button == SCROLL_UP)
		rate = ZOOMIN_RATE;
	else if (button == SCROLL_DOWN)
		rate = ZOOMOUT_RATE;
	if (rate != 0)
	{
		zoom_window(vars, x, y, rate);
		mlx_clear_window(vars->mlx, vars->win);
		clear_image(vars);
		put_image_to_window(vars);
	}
	return (SUCCESS);
}
