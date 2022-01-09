/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_parse.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkano <tkano@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/27 12:08:05 by tkano             #+#    #+#             */
/*   Updated: 2021/12/27 12:08:05 by tkano            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	set_figure_name(t_vars *vars, char *argv)
{
	if (argv[0] == '\0' || argv[1] != '\0')
		put_help();
	if (argv[0] == 'm')
	{
		vars->func = fractol_mandelbrot;
		vars->figure_name = "madelbrot";
	}
	else if (argv[0] == 'j')
	{
		vars->func = fractol_julia;
		vars->figure_name = "julia";
	}
	else
		put_help();
}

void	set_params(t_vars *vars, int argc, char **argv)
{
	if (argv[1][0] == 'j' && argc > 4)
		put_help();
	if (ft_malloc(&(vars->params), sizeof(double), 2))
		put_error("malloc error");
	vars->params[0] = 0.32;
	vars->params[1] = 0.043;
	if (argc > 2 && ((parse_num(argv[2], &vars->params[0]))))
		put_help();
	if (argc > 3 && parse_num(argv[3], &(vars->params[1])))
		put_help();
}

void	arg_parse(t_vars *vars, int argc, char **argv)
{
	if (argc == 1 || argc > 5)
		put_help();
	set_figure_name(vars, argv[1]);
	if (argv[1][0] == 'm' && argc > 2)
		put_help();
	else
		set_params(vars, argc, argv);
}
