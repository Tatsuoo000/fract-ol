/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkano <tkano@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 11:06:57 by tkano             #+#    #+#             */
/*   Updated: 2022/01/06 11:06:57 by tkano            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	stop_iteration(double x, double y, int iter, int max_iter)
{
	return (iter >= max_iter || x * x + y * y > 4);
}

void	update_value(double *x, double *y, t_vec *vec)
{
	double	tmp;

	tmp = *x;
	*x = *x * *x - *y * *y + vec->x;
	*y = 2 * tmp * *y + vec->y;
}

int	fractol_mandelbrot(t_vars *vars, t_vec *vec)
{
	double	x;
	double	y;
	int		i;

	vars->x = vars->x;
	i = 0;
	x = 0;
	y = 0;
	while (!stop_iteration(x, y, i, vars->max_iter))
	{
		update_value(&x, &y, vec);
		++i;
	}
	if (i >= vars->max_iter)
		return (0);
	return (i);
}

int	fractol_julia(t_vars *vars, t_vec *vec)
{
	double	x;
	double	y;
	int		i;
	t_vec	c;

	vars->x = vars->x;
	vec_set(&c, vars->params[0], vars->params[1]);
	i = 0;
	x = vec->x;
	y = vec->y;
	while (!stop_iteration(x, y, i, vars->max_iter))
	{
		update_value(&x, &y, &c);
		++i;
	}
	if (i >= vars->max_iter)
		return (0);
	return (i);
}
