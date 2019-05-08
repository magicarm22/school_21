/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djast <djast@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/20 16:50:55 by djast             #+#    #+#             */
/*   Updated: 2019/03/29 16:43:19 by djast            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
#define FRACTOL_H

# include "./mlx/mlx.h"
# include "./libft/libft.h"
# include <math.h>
# include <stdio.h>
# include <pthread.h>

# define SIZE_MAP_X 600
# define SIZE_MAP_Y 600
# define NUM_THREADS 4
# define FRACTOL_fractol_params 1
# define FRACTOL_MANDEL 2

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
	t_point			**points;
	int				bbp;
	int				size_line;
	int				endian;
	long long		zoom;
	char			*type;
	int				place_x;
	int				place_y;
	int				max_step;
	t_complex		*clx;
	int 			fixed_image : 2;
}					t_mlx;


typedef struct		s_fractol	
{
	t_complex		*const_C;
	long double		const_R;
	int				step;
	int 			max_step;
	long double		xMin;
    long double		yMin;
    long double		xMax;
    long double		yMax;
    long double		xStep;
    long double		yStep;
    int				max_idx;
    long double		tmp;
}					t_fractol;

typedef struct		s_thread
{
	t_complex		*clx;
	t_mlx 			*mlx;
	int 			min_x;
	int 			min_y;
	int 			cur_x;
	int 			cur_y;
	int 			max_x;
	int 			max_y;
	int				num_thread;
	int				type_of_fractol;
}					t_thread;




t_mlx		*init_struct_mlx();
void		*init_fractol_and_start_to_calc();
int			key_release(int key, t_mlx *mlx);
int			close_win(t_mlx *mlx);
void		*mandelbrot_fractol();
int			mouse_press(int button, int x, int y, t_mlx *mlx);
void		restart(t_mlx *mlx);
int		init_threads_and_start(t_complex *clx, t_mlx *mlx);
void		mandelbrot_threads(t_complex *clx, t_mlx *mlx);
int			mouse_move(int x, int y, t_mlx *mlx);

#endif