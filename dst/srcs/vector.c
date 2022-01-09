/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkano <tkano@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 13:05:32 by tkano             #+#    #+#             */
/*   Updated: 2022/01/06 13:05:32 by tkano            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	vec_add(t_vec *vec1, t_vec *vec2, t_vec *vec_dst)
{
	vec_set(vec_dst, vec1->x + vec2->x, vec1->y + vec2->y);
}

void	vec_set(t_vec *vec, double x, double y)
{
	vec->x = x;
	vec->y = y;
}
