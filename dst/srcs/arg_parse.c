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

void    set_figure_name(t_vars *vars, char *argv)
{
    if (argv[0] == '\0' || argv[1] != '\0')
        put_help();
    if (argv[0] == 'm')
    {
        vars->func = fractol_mandelbrot;
        vars->figure_name = "madelbrot";
    }
    else
        put_help();
}

//void    set_params(t_vars *vars, int argc, char **argv)
//{

//}

void    arg_parse(t_vars *vars, int argc, char **argv)
{
    if (argc == 1 || argc > 5)
        put_help();
    set_figure_name(vars, argv[1]);
    if (argv[1][0] == 'm' && argc > 2)
        put_help();
    //else
        //set_params(vars, argc, argv);
}
