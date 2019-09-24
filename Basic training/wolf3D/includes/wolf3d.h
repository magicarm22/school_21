/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eharrag- <eharrag-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/27 16:02:51 by djast             #+#    #+#             */
/*   Updated: 2019/09/24 14:33:33 by eharrag-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF3D_H
# define WOLF3D_H
# include <SDL.h>
# include <SDL_mixer.h>
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include <math.h>
# include "libft.h"
# include "get_next_line.h"
# define ERROR_NON_VALID_FILE -1
# define FIELD_OF_VIEW 60.0
# define SIZE_WIN_X 2880
# define SIZE_WIN_Y 1620
# define RESOL_X 960
# define RESOL_Y 200
# define RESOL_RATIO_X SIZE_WIN_X / RESOL_X
# define RESOL_RATIO_Y SIZE_WIN_Y / RESOL_Y
# define RADIAN M_PI / 180
# define ABS(x) ((x) >= 0 ? (x) : ((x) * -1))

# define PISTOL_X SIZE_WIN_X / 2 - 700
# define PISTOL_Y SIZE_WIN_Y * 2 / 5
# define PISTOL_SIZE_X SIZE_WIN_X / 2 - 300
# define PISTOL_SIZE_Y SIZE_WIN_Y * 3 / 5

# define PISTOL_IMAGE_X 192
# define PISTOL_IMAGE_Y 80
# define PISTOL_IMAGE_SIZE_X 192
# define PISTOL_IMAGE_SIZE_Y 192
# define PISTOL_LAST_FRAME 4

# define SKY_IMAGE_X 8000
# define SKY_IMAGE_Y 2000

typedef struct		s_sdl
{
	SDL_Window		*window;
	SDL_Renderer	*renderer;
	SDL_Event		window_event;
	SDL_Texture		*texture_north;
	SDL_Texture		*texture_south;
	SDL_Texture		*texture_east;
	SDL_Texture		*texture_west;
	SDL_Texture		*texture_sky;
	SDL_Texture		*pistol;
	Mix_Chunk		*shooting;
	Mix_Chunk		*steps;
	SDL_Surface		*temp;
}					t_sdl;

typedef struct		s_map
{
	int size_x;
	int size_y;
	int **map;
}					t_map;

typedef struct		s_player
{
	int				x;
	int				y;
	int				strip;
	int				hor_or_vert;
	double			check_hor_x;
	double			check_hor_y;
	double			check_ver_x;
	double			check_ver_y;
	double			point_of_view;
	double			distance;
	int				is_shooting;
	int				shooting_frame;
	int				shooting_time;
	int				mouse_x;
	int				mouse_y;
}					t_player;

t_map				*get_map_from_file(t_player *player, int fd);
int					countwords(char *str, char c);
void				cast_a_ray(t_sdl *sdl, t_player *point, t_map *map_info);
void				init_walls(t_player *point, int slice,
						SDL_Rect *rect, SDL_Rect *wall);
void				draw_a_wall(t_sdl *sdl, t_player *point, int slice,
						double distance_to_the_wall);
void				draw_the_sky(t_sdl *sdl, int point_of_view);
void				draw_the_sky_full(t_sdl *sdl, int point_of_view);
void				draw_the_sky_parts(t_sdl *sdl, int point_of_view);
void				load_bmps(t_sdl *sdl);

#endif
