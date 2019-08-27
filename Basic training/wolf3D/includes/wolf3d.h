/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djast <djast@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/27 16:02:51 by djast             #+#    #+#             */
/*   Updated: 2019/08/27 19:21:38 by djast            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF3D_H
# define WOLF3D_H
# include <SDL.h>
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include "libft.h"
# include "get_next_line.h"
# define ERROR_NON_VALID_FILE -1

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
	int coord_x;
	int coord_y;
}					t_player;

t_map				*get_map_from_file(t_player *player, int fd);
int					countwords(char *str, char c);

#endif