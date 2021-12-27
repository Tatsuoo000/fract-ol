/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minilibx_cal.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkano <tkano@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/27 16:21:59 by tkano             #+#    #+#             */
/*   Updated: 2021/12/27 16:21:59 by tkano            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	set_all_mlx_hook(t_vars *vars)
{
	mlx_key_hook(vars->win, control_key_code, vars);
	mlx_mouse_hook(vars->win, control_mouse_hook, vars);
}