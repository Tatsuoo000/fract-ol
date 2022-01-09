/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_num.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkano <tkano@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/09 18:02:26 by tkano             #+#    #+#             */
/*   Updated: 2022/01/09 18:04:12 by tkano            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	parse_int(char **s, int *num)
{
	int	i;

	*num = 0;
	i = 0;
	if (**s == '0' && ft_isdigit((*s)[1]))
		return (ERROR);
	while (ft_isdigit(**s))
	{
		if (i > 8)
			return (ERROR);
		else
			*num = *num * 10 + (**s - '0');
		++(*s);
		++i;
	}
	return (SUCCESS);
}

int	parse_double(char **s, double *v)
{
	int		d;
	char	*p;

	if (parse_int(s, &d))
		return (ERROR);
	*v = d;
	if (**s == '.')
	{
		(*s)++;
		p = *s;
		while (**s == '0')
			(*s)++;
		if (parse_int(s, &d))
			return (ERROR);
		*v += pow(10, -1 * (int)(*s - p)) * d;
	}
	return (SUCCESS);
}

int	parse_num(char *s, double *v)
{
	int	sign;

	sign = 1;
	if (*s == '-')
	{
		sign = -1;
		s++;
	}
	if (!ft_isdigit(*s))
		return (ERROR);
	if (parse_double(&s, v))
		return (ERROR);
	if (*s != '\0')
		return (ERROR);
	*v *= sign;
	return (SUCCESS);
}
