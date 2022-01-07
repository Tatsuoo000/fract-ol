/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkano <tkano@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/29 17:57:34 by tkano             #+#    #+#             */
/*   Updated: 2022/01/06 13:25:44 by tkano            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int main(int argc, char **argv)
{
	t_vars	vars;

	arg_parse(&vars, argc, argv);
	vars_init(&vars);
	mlx_image_to_window(&vars);
	mlx_loop(vars.mlx);
}