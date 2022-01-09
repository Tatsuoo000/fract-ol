/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom_window.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkano <tkano@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/09 13:11:36 by tkano             #+#    #+#             */
/*   Updated: 2022/01/09 19:01:43 by tkano            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	slide_window(t_vars *vars, int x, int y)
{
	t_vec	vec;
	t_win	*window;

	window = &(vars->window);
	if ((x < 0 && window->left_top.x < -2 * vars->x) || \
		(x > 0 && window->left_top.x + window->width > 2 * vars->x) || \
		(y < 0 && window->left_top.y < -2 * vars->y) || \
		(y > 0 && window->left_top.y + window->height > 2 * vars->y))
		return ;
	vec_set(&vec, x * window->step.x, y * window->step.y);
	vec_add(&(window->left_top), &vec, &(window->left_top));
}

void	zoom_window(t_vars *vars, int x, int y, double r)
{
	t_win	*window;
	t_vec	vec;

	window = &(vars->window);
	if (r < 1 && (window->width < 1e-15 || window->height < 1e-15))
		return ;
	pos_vec_set(vars, x, y, &vec);
	vec_set(&(window->left_top), \
			r * window->left_top.x + (1 - r) * vec.x, \
			r * window->left_top.y + (1 - r) * vec.y);
	window->width *= r;
	window->height *= r;
	vec_set(&(window->step), \
			window->width / vars->x, \
			window->height / vars->y);
	if (r > 1)
		vars->max_iter -= ZOOM_ITER_PLUS;
	else
		vars->max_iter += ZOOM_ITER_PLUS;
	if (vars->max_iter <= 10)
		vars->max_iter = 10;
}
