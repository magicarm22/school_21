/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eharrag- <eharrag-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/27 16:02:51 by djast             #+#    #+#             */
/*   Updated: 2019/09/17 12:08:40 by eharrag-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF3D_H
# define WOLF3D_H
# include <SDL.h>
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include <math.h>
# include "libft.h"
# include "get_next_line.h"
# define ERROR_NON_VALID_FILE -1
# define FIELD_OF_VIEW 60.0 //1.047197 // 60 * 3.141593 / 180
# define SIZE_WIN_X 2880
# define SIZE_WIN_Y 1620
# define RESOL_X 320
# define RESOL_Y 200
# define RESOL_RATIO_X SIZE_WIN_X / RESOL_X
# define RESOL_RATIO_Y SIZE_WIN_Y / RESOL_Y
# define RADIAN M_PI / 180

typedef struct		s_SDL
{
	SDL_Window      *window;
    SDL_Renderer    *renderer;
	SDL_Event		windowEvent;
}					t_SDL;

typedef struct		s_map
{
	int size_x;
	int size_y;
	int **map;
}					t_map;

typedef struct		s_player
{
	int 			x;
	int 			y;
	double			check_x;
	double			check_y;
	double			point_of_view;
}					t_player;

t_map				*get_map_from_file(t_player *player, int fd);
int					countwords(char *str, char c);
void				cast_a_ray(t_SDL *sdl, t_player *point, t_map *map_info);
void				draw_a_wall(t_SDL *sdl, int slice, double distance_to_the_wall);

#endif
