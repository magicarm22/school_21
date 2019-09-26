/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   happyend.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eharrag- <eharrag-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/25 14:56:08 by eharrag-          #+#    #+#             */
/*   Updated: 2019/09/25 14:57:15 by eharrag-         ###   ########.fr       */
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
