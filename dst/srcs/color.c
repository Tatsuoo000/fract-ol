/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkano <tkano@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 19:06:27 by tkano             #+#    #+#             */
/*   Updated: 2022/01/09 19:10:52 by tkano            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

int	color_add(int trgb, int value)
{
	int	trgb_array[3];

	trgb_array[0] = (trgb_to_r_int(trgb) + value) % 256;
	trgb_array[1] = (trgb_to_r_int(trgb) + value) % 256;
	trgb_array[2] = (trgb_to_r_int(trgb) + value) % 256;
	return (create_trgb(0, trgb_array[0], trgb_array[2], trgb_array[3]));
}
