/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eharrag- <eharrag-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/27 16:02:51 by djast             #+#    #+#             */
/*   Updated: 2019/09/26 11:11:59 by eharrag-         ###   ########.fr       */
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

# define SKY_IMAGE_X 16200
# define SKY_IMAGE_Y 810

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
	int				ray;
	double			angle;
	double			dist_hor;
	double			dist_vert;
	double			check_hor_x;
	double			check_hor_y;
	double			check_ver_x;
	double			check_ver_y;
	double			delta_x_hor;
	double			delta_y_hor;
	double			radian_angle_hor;
	double			res_hor;
	double			delta_x_vert;
	double			delta_y_vert;
	double			radian_angle_vert;
	double			res_vert;
	double			point_of_view;
	double			distance;
	int				is_shooting;
	int				shooting_frame;
	int				shooting_time;
	int				mouse_x;
	int				mouse_y;
}					t_player;

t_map				*get_map_from_file(t_player *player, int fd);
int					get_info_from_file(t_map *map_info,
						t_player *player, int fd);
int					countwords(char *str, char c);
int					read_map(t_map *map_info, int fd);
void				init_map(t_map *map_info);
void				print_map(t_map *map_info);
void				check_map_info(t_map *map_info);
void				init_player(t_player *player, char **numbers);
void				init_sdl(t_sdl *sdl);
void				big_loop(t_sdl *sdl, t_map *map_info, t_player *player);
void				poll_event(t_sdl *sdl, t_map *map_info, t_player *player);
void				key_a(t_sdl *sdl, t_map *map_info, t_player *player);
void				key_d(t_sdl *sdl, t_map *map_info, t_player *player);
void				key_w(t_sdl *sdl, t_map *map_info, t_player *player);
void				key_s(t_sdl *sdl, t_map *map_info, t_player *player);
void				mousemotion(t_sdl *sdl, t_player *player);
void				mousebutton(t_sdl *sdl, t_player *player);
void				cast_a_ray(t_sdl *sdl, t_player *point, t_map *map_info);
double				find_a_wall_hor(t_map *map_info, t_player *point,
						double angle);
double				find_a_wall_vert(t_map *map_info, t_player *point,
						double angle);
int					count_check_y(t_player *point, double angle);
int					count_check_x(t_player *point, double angle);
int					find_crossing_hor(t_player *point, t_map *map_info);
int					find_crossing_vert(t_player *point, t_map *map_info);
void				choose_the_range(t_sdl *sdl, t_player *point);
void				init_walls(t_player *point, int slice,
						SDL_Rect *rect, SDL_Rect *wall);
void				draw_a_weapon(t_sdl *sdl, t_player *player);
void				draw_a_wall(t_sdl *sdl, t_player *point, int slice,
						double distance_to_the_wall);
void				draw_the_sky(t_sdl *sdl, int point_of_view);
void				draw_the_sky_full(t_sdl *sdl, int point_of_view);
void				draw_the_sky_parts(t_sdl *sdl, int point_of_view);
void				redraw(t_sdl *sdl, t_map *map_info, t_player *player);
void				load_bmps(t_sdl *sdl);
void				happyend(t_sdl *sdl);

#endif
