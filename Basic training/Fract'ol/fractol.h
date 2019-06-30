/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djast <djast@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/20 16:50:55 by djast             #+#    #+#             */
/*   Updated: 2019/06/13 16:41:01 by djast            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "./mlx/mlx.h"
# include "./libft/libft.h"
# include <math.h>
# include <stdio.h>
# include <pthread.h>

# define SIZE_MAP_X 600
# define SIZE_MAP_Y 600
# define NUM_THREADS 4
# define FRACTOL_JULIA 1
# define FRACTOL_MANDEL 2
# define FRACTOL_BURN 3
# define FRACTOL_NEWTON 4
# define FRACTOL_CUBIC 5
# define FRACTOL_QUADRATIC 6
# define FRACTOL_FIFTH 7
# define FRACTOL_BUBBLE 8

typedef struct		s_points
{
	long double			x;
	long double			y;
	long long			color;
}					t_point;

typedef struct		s_complex
{
	long double c;
	long double i;
}					t_complex;

typedef struct		s_mlx
{
	int				size_map_x;
	int				size_map_y;
	void			*m_p;
	void			*w_p;
	void			*img;
	int				*img_data;
	int				bbp;
	int				size_line;
	int				endian;
	long long		zoom;
	char			*type;
	long double		place_x;
	long double		place_y;
	int				max_step;
	t_complex		*clx;
	int				fixed_image : 2;
	int				color_mode;
}					t_mlx;

typedef struct		s_fractol
{
	t_complex		*const_c;
	int				step;
	int				max_step;
	long double		tmp;
}					t_fractol;

typedef struct		s_thread
{
	t_complex		*clx;
	t_mlx			*mlx;
	int				min_x;
	int				min_y;
	int				cur_x;
	int				cur_y;
	int				max_x;
	int				max_y;
	int				num_thread;
	int				type_of_fractol;
}					t_thread;

t_mlx				*init_struct_mlx();
void				*start_to_calc_fractol();
int					key_release(int key, t_mlx *mlx);
int					close_win(t_mlx *mlx);
void				*mandelbrot_fractol();
int					mouse_press(int button, int x, int y, t_mlx *mlx);
void				restart(t_mlx *mlx);
int					init_threads_and_start(t_complex *clx, t_mlx *mlx);
void				mandelbrot_threads(t_complex *clx, t_mlx *mlx);
int					mouse_move(int x, int y, t_mlx *mlx);
void				start_mlx(const char *fractol_name);
void				free_mlx(t_mlx *mlx);
void				free_args(t_thread **args);
void				julia_calculate(t_complex *clx, t_mlx *mlx, t_thread *args,
										t_fractol *fractol_params);
void				mandelbrot_calculate(t_complex *clx, t_mlx *mlx,
									t_thread *args, t_fractol *fractol_params);
void				burning_ship_calculate(t_complex *clx, t_mlx *mlx,
									t_thread *args, t_fractol *fractol_params);
void				newton_calculate(t_complex *clx, t_mlx *mlx, t_thread *args,
									t_fractol *fractol_params);
void				put_color_by_mode(t_mlx *mlx, t_thread *args, int step);
void				cubic_calculate(t_complex *clx, t_mlx *mlx, t_thread *args,
							t_fractol *fractol_params);
void				quadratic_calculate(t_complex *clx, t_mlx *mlx,
				t_thread *args, t_fractol *fractol_params);
void				fifth_calculate(t_complex *clx, t_mlx *mlx, t_thread *args,
							t_fractol *fractol_params);
void				bubble_calculate(t_complex *clx, t_mlx *mlx, t_thread *args,
						t_fractol *fractol_params);

#endif
