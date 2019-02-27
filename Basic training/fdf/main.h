/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djast <djast@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/15 19:58:55 by djast             #+#    #+#             */
/*   Updated: 2019/02/24 16:54:39 by djast            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_H
# define MAIN_H
# include "./mlx/mlx.h"
# include "./libft/libft.h"
# include "./gnl/get_next_line.h"
# include <math.h>
# include <unistd.h>
# define WH 0xFFFFFF
# define SIZE_MAP_X 2560
# define SIZE_MAP_Y 1440

typedef struct		s_points
{
	double			x;
	double			y;
	double			z;
	long long		color;
}					t_point;

/*
** size_map_x - размер карты по x
** size_map_y - размер карты по y
** *m_p - указатель на mlx (инициализатор)
** *win_ptr - указатель на окно
** *filename - имя файла, из которого производится чтение
** fd - номер файлого дескриптера.
** delta_x - dx для алгоритма Брезенхема
** delta_y - dy для алгоритма Брезенхема
** sign_x - направление (выбор четверти) по x для алгоритма Брезенхема
** sign_y - направление (выбор четверти) по y для алгоритма Брезенхема
** delta_max - самое длинная разница (x или y)
** zoom - значение приближения/отдаления
** place_x - расположение фигуры относительно окна по оси x
** place_y - расположение фигуры относительно окна по оси y
** middle_x - координата середины фигуры по оси x
** middle_y - координата середины фигуры по оси y
** delta_error - переменная для выбора закраски пикселя для алгоритма
** Брезенхема
** **points - двумерный массив точек из файла
*/

typedef struct		s_mlx
{
	int				size_map_x;
	int				size_map_y;
	void			*m_p;
	void			*w_p;
	const char		*filename;
	int				fd;
	int				delta_x;
	int				delta_y;
	int				sign_x;
	int				sign_y;
	int				delta_max;
	int				zoom;
	int				place_x;
	int				place_y;
	double			middle_x;
	double			middle_y;
	double			delta_error;
	int				is_color;
	int				is_legend;
	void			*img;
	int				*img_data;
	t_point			**points;
	int				bbp;
	int				size_line;
	int				endian;
}					t_mlx;

int					ft_arrc_size(char **str);
int					ft_si(int n);
int					ft_size_char(char *arr);
intmax_t			ft_recursive_power(intmax_t nb, intmax_t power);
void				rotate_in_out(t_mlx *mlx, int direction);
void				rotate_up_down(t_mlx *mlx, int direction);
void				rotate_left_right(t_mlx *mlx, int direction);
void				create_legend(t_mlx *mlx);
void				change_state_legend(t_mlx *mlx);
void				move(t_mlx *mlx, int direction);
void				zoom_in_out(t_mlx *mlx, int direction);
int					key_release(int key, t_mlx *mlx);
int					mouse_press(int button, int x, int y, t_mlx *mlx);
void				iso(t_mlx *mlx);
int					close_win(t_mlx *mlx);
void				make_image(t_mlx *mlx);
void				draw_line(t_mlx *mlx, t_point coord1, t_point coord2);
void				create_map(int fd, t_mlx **info_map);
int					check_map(int fd, t_mlx *info_map);
int					check_line(t_mlx *mlx, char *line);
void				fill_mlx(t_mlx *info_map, int flag);
long long			parse_color(char *line);
t_mlx				*init_struct_mlx(const char *filename, int fd);
void				free_mem(t_mlx *mlx);
void				reset(t_mlx *mlx);
void				restart(t_mlx *mlx);
void				add_zeroes(t_mlx **info_map, int x, int y);
#endif
