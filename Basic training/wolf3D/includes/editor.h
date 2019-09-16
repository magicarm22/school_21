/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   editor.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djast <djast@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/15 12:59:27 by djast             #+#    #+#             */
/*   Updated: 2019/09/16 13:19:40 by djast            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EDITOR_H
# define EDITOR_H
# include <SDL.h>
# include <limits.h>
# include "libft.h"
# define SIZE_WIN_X 2880
# define SIZE_WIN_Y 1620
# define MESH_START_X 40
# define MESH_START_Y 40
# define BASIC_MAP_SIZE_X 32
# define BASIC_MAP_SIZE_Y 32

typedef struct		s_sdl
{
	SDL_Window      *window;
    SDL_Renderer    *renderer;
	SDL_Event		windowEvent;
	SDL_Texture		*floor;
	SDL_Texture		*wall;
	SDL_Surface		*surface;
	struct s_mesh	*mesh;
}					t_sdl;

typedef struct		s_mesh
{
	int		x;
	int		y;
	int		size_x;
	int		size_y;
	int		zoom;
	int		**map;
	int		**swaped;
}					t_mesh;

typedef struct	 	s_input_field
{
	int		x;
	int		y;
	int		size_x;
	int		size_y;
	int		max_text_size;
	char	*text;
	int		text_size;
}					t_input_field;

void		draw_full(t_sdl *sdl);
void		init_mesh(t_sdl **sdl);
void		init_map(t_mesh **mesh);
t_sdl 		*init_sdl(void);
void		mouse_action(t_sdl *sdl, int *click);
#endif