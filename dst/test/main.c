/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkano <tkano@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/29 17:57:34 by tkano             #+#    #+#             */
/*   Updated: 2021/12/30 21:43:02 by tkano            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minilibx-linux/mlx.h"

int main()
{
	void	*mlx;
	void	*mlx_win;
	int		i;
	int		j;
	int		width = 1000;
	int		height = 1000;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, width, height, "test");
	i = 0;
	while (i < width)
	{
		j = 0;
		while (j < height)
		{
			mlx_pixel_put(mlx, mlx_win, i, j, 126);
			j++;
		}
		i++;
	}
	mlx_loop(mlx);
	return (1);
}