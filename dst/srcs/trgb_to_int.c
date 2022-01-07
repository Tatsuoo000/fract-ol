/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trgb_to_int.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkano <tkano@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 19:14:14 by tkano             #+#    #+#             */
/*   Updated: 2022/01/07 19:15:24 by tkano            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	trgb_to_t_int(int trgb)
{
	return ((trgb >> 24) & 0xFF);
}

int	trgb_to_r_int(int trgb)
{
	return ((trgb >> 16) & 0xFF);
}

int	trgb_to_g_int(int trgb)
{
	return ((trgb >> 8) & 0xFF);
}

int	trgb_to_b_int(int trgb)
{
	return (trgb & 0xFF);
}
