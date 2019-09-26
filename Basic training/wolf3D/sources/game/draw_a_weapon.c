/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_a_weapon.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eharrag- <eharrag-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/25 14:54:14 by eharrag-          #+#    #+#             */
/*   Updated: 2019/09/26 09:45:04 by eharrag-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	draw_a_weapon(t_sdl *sdl, t_player *player)
{
	SDL_Rect	weapon_screen;
	SDL_Rect	weapon_file;

	weapon_screen.x = PISTOL_X;
	weapon_screen.y = PISTOL_Y;
	weapon_screen.w = PISTOL_SIZE_X;
	weapon_screen.h = PISTOL_SIZE_Y;
	if (player->shooting_frame != PISTOL_LAST_FRAME)
		player->shooting_frame = ((SDL_GetTicks() - player->shooting_time) *
		12 / 1000) % (PISTOL_LAST_FRAME + 1);
	weapon_file.x = PISTOL_IMAGE_X * player->shooting_frame;
	weapon_file.y = PISTOL_IMAGE_Y;
	weapon_file.w = PISTOL_IMAGE_SIZE_X;
	weapon_file.h = PISTOL_IMAGE_SIZE_Y;
	SDL_RenderCopy(sdl->renderer, sdl->pistol, &weapon_file, &weapon_screen);
}
