/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkano <tkano@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/27 11:36:39 by tkano             #+#    #+#             */
/*   Updated: 2021/12/27 11:36:39 by tkano            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "../minilibx-linux/mlx.h"
# include "../libft/libft.h"
# include <unistd.h>
# include <math.h>
# include <stdlib.h>
# include <stdio.h>

# define TRUE 1
# define FALSE 0
# define SUCCESS 0
# define ERROR -1

# define ESC_KEY 65307
# define LEFT_KEY 65361
# define RIGHT_KEY 65363
# define UP_KEY 65362
# define DOWN_KEY 65364
# define ONE_KEY 49
# define SCROLL_UP 4
# define SCROLL_DOWN 5

# define SLIDE_STEP 20
# define SCREEN_X 500
# define SCREEN_Y 500
# define ZOOMIN_RATE 0.8
# define ZOOMOUT_RATE 1.2

# define MAX_ITERATION_INIT 100
# define ZOOM_ITER_PLUS 4
# define STOP_DIVERGENCE 2

# define START_WIDTH 4
# define START_HEIGHT 4

typedef struct s_vec {
	double	x;
	double	y;
}				t_vec;

typedef struct s_win {
	t_vec	left_top;
	t_vec	step;
	double	width;
	double	height;
}				t_win;

typedef struct s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

typedef struct s_vars {
	void		*mlx;
	void		*win;
	t_data		data;
	int			x;
	int			y;
	int			base_color;
	int			(*func)(struct s_vars *, t_vec *);
	char		*figure_name;
	t_win		window;
	double		*params;
	int			max_iter;
}				t_vars;

void	arg_parse(t_vars *vars, int argc, char **argv);
int		fractol_mandelbrot(t_vars *vars, t_vec *vec);
void	put_help(void);
int		put_error(char *str);
void	vars_init(t_vars *vars);
void	vec_set(t_vec *vec, double x, double y);
int		fractol_mandelbrot(t_vars *vars, t_vec *vec);
int		draw_image(t_vars *vars);
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
int		create_trgb(int t, int r, int g, int b);
int		color_add(int trgb, int value);
int		trgb_to_t_int(int trgb);
int		trgb_to_r_int(int trgb);
int		trgb_to_g_int(int trgb);
int		trgb_to_b_int(int trgb);
void	put_image_to_window(t_vars *vars);
int		control_key_hook(int key, t_vars *vars);
int		control_mouse_hook(int button, int x, int y, t_vars *vars);
void	zoom_window(t_vars *vars, int x, int y, double r);
void	clear_image(t_vars *vars);
void	pos_vec_set(t_vars *vars, int x, int y, t_vec *dst);
void	slide_window(t_vars *vars, int x, int y);
void	vec_add(t_vec *vec1, t_vec *vec2, t_vec *vec_dst);
int		parse_num(char *s, double *v);
int		fractol_julia(t_vars *vars, t_vec *vec);

#endif