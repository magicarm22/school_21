/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   happyend.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djast <djast@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/25 14:56:08 by eharrag-          #+#    #+#             */
/*   Updated: 2019/10/08 13:36:31 by djast            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	happyend(t_sdl *sdl)
{
	SDL_DestroyWindow(sdl->window);
	Mix_FreeChunk(sdl->steps);
	Mix_FreeChunk(sdl->shooting);
	Mix_CloseAudio();
	SDL_Quit();
}

void	free_map(t_map *map)
{
	int i;

	i = 0;
	while (i != map->size_y)
		free(map->map[i++]);
	free(map->map);
}

void	free_strsplit(char **res, int count)
{
	int i;

	i = 0;
	while (i < count)
		free(res[i++]);
	free(res);
}
