/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkano <tkano@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/29 17:57:34 by tkano             #+#    #+#             */
/*   Updated: 2022/01/05 19:04:57 by tkano            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minilibx-linux/mlx.h"
#include "../includes/fractol.h"
#include <stdlib.h>

void end(void)__attribute__((destructor));

void end(void)
{
    system("leaks fractol");
}

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int	key_hook(int keycode, t_vars *vars)
{
	printf("Hello from key_hook!: %d\n", keycode);
	printf("key base_colour: %d\n", vars->base_color);
	return (0);
}

int	mouse_hook(int keycode,int x, int y)
{
	printf("Hello from key_hook!: %d\n", keycode);
	printf("mouse posx: %d, posy: %d\n", x, y);
	return (0);
}

int	ft_close(int keycode, t_vars *vars)
{
	printf("close key!: %d\n", keycode);
	mlx_destroy_window(vars->mlx, vars->win);
	return (0);
}

int	main(void)
{
	t_vars	vars;
	int		i;

	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, 1920, 1080, "Hello world!");
	vars.data.img = mlx_new_image(vars.mlx, 1920, 1080);
	vars.data.addr = mlx_get_data_addr(vars.data.img, &(vars.data.bits_per_pixel), &(vars.data.line_length),
								&(vars.data.endian));
	i = 0;
	while (i < 500)
	{
		my_mlx_pixel_put(&(vars.data), 5, 5 + i, 0x00FF0000);
		my_mlx_pixel_put(&(vars.data), 5 + i, 5, 0x00FF0000);
		i++;
	}
	mlx_put_image_to_window(vars.mlx, vars.win, vars.data.img, 0, 0);
	mlx_key_hook(vars.win, key_hook, &vars);
	mlx_mouse_hook(vars.win, mouse_hook, &vars);
	mlx_hook(vars.win, 2, 1L<<5, ft_close, &vars);
	mlx_loop(vars.mlx);
}

