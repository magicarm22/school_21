/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   editor.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eharrag- <eharrag-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/15 13:05:37 by djast             #+#    #+#             */
/*   Updated: 2019/09/26 10:02:39 by eharrag-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "editor.h"

void	destroy(t_sdl *sdl)
{
	SDL_DestroyTexture(sdl->floor);
	SDL_DestroyTexture(sdl->wall);
	SDL_DestroyTexture(sdl->player_texture);
	SDL_DestroyTexture(sdl->text);
	SDL_DestroyWindow(sdl->window);
	SDL_Quit();
}

int		main(void)
{
	t_sdl	*sdl;
	int		click;

	sdl = init_sdl();
	init_mesh(&sdl);
	init_map(&(sdl->mesh));
	sdl->player = (t_player *)malloc(sizeof(t_player));
	sdl->player->x = -1;
	sdl->player->y = -1;
	sdl->map_name = init_input_field(BUTTON_X, INPUT_MAP_NAME_Y,
										BUTTON_SIZE_X, BUTTON_SIZE_Y);
	draw_full(sdl);
	click = 0;
	SDL_StopTextInput();
	while (1)
	{
		if (SDL_PollEvent(&(sdl->window_event)))
		{
			if (action_keyboard(sdl) == 1)
				break ;
			action_mouse(sdl, &click);
			draw_full(sdl);
		}
	}
}
