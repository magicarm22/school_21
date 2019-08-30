/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djast <djast@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/28 15:10:30 by djast             #+#    #+#             */
/*   Updated: 2019/08/30 14:11:34 by djast            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "commands.h"

void			draw_stack(t_sdl *sdl, t_stack *stack, int status)
{
	t_stack		*cur_list;
	SDL_Rect	r;
	int			i;

	cur_list = stack;
	i = 0;
	while (cur_list != NULL)
	{
		r.x = status == 0 ? 0 : SIZE_STACKS_X / 2;
		r.y = i * SIZE_WINDOW_Y / sdl->stack_size;
		r.h = SIZE_WINDOW_Y / sdl->stack_size;
		r.w = (double)cur_list->data / (double)sdl->stack_size *
														SIZE_STACKS_X / 2;
		SDL_SetRenderDrawColor(sdl->renderer, 255, 0, 0, 255);
		SDL_RenderFillRect(sdl->renderer, &r);
		cur_list = cur_list->next;
		i++;
	}
}

void			draw(t_sdl *sdl)
{
	SDL_SetRenderDrawColor(sdl->renderer, 0, 0, 0, 255);
	SDL_RenderClear(sdl->renderer);
	draw_stack(sdl, sdl->stacks->head_a, 0);
	draw_stack(sdl, sdl->stacks->head_b, 1);
	SDL_RenderPresent(sdl->renderer);
}
