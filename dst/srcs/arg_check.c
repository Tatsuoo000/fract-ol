/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkano <tkano@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/27 12:08:05 by tkano             #+#    #+#             */
/*   Updated: 2021/12/27 12:08:05 by tkano            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	arg_check(t_vars *vars, int argc, char **argv)
{
	if (argv[1][0] == 'm' && argc > 2)
		put_error();
	else
		set_prams(vars, argc, argv);
}