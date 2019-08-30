/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djast <djast@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/28 15:38:06 by djast             #+#    #+#             */
/*   Updated: 2019/08/30 14:28:19 by djast            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "commands.h"

void				make_command(t_stacks *stacks, t_commands *commands)
{
	if (ft_strcmp(commands->data, "sa") == 0)
		stack_sa(stacks);
	else if (ft_strcmp(commands->data, "sb") == 0)
		stack_sb(stacks);
	else if (ft_strcmp(commands->data, "ss") == 0)
		stack_ss(stacks);
	else if (ft_strcmp(commands->data, "pa") == 0)
		stack_pa(stacks);
	else if (ft_strcmp(commands->data, "pb") == 0)
		stack_pb(stacks);
	else if (ft_strcmp(commands->data, "ra") == 0)
		stack_ra(stacks);
	else if (ft_strcmp(commands->data, "rb") == 0)
		stack_rb(stacks);
	else if (ft_strcmp(commands->data, "rr") == 0)
		stack_rr(stacks);
	else if (ft_strcmp(commands->data, "rra") == 0)
		stack_rra(stacks);
	else if (ft_strcmp(commands->data, "rrb") == 0)
		stack_rrb(stacks);
	else if (ft_strcmp(commands->data, "rrr") == 0)
		stack_rrr(stacks);
}

static void			check_speed(int key, t_sdl *sdl)
{
	if (key == SDLK_1)
		sdl->speed = 1;
	else if (key == SDLK_2)
		sdl->speed = 2;
	else if (key == SDLK_3)
		sdl->speed = 4;
	else if (key == SDLK_4)
		sdl->speed = 8;
	else if (key == SDLK_5)
		sdl->speed = 16;
	else if (key == SDLK_6)
		sdl->speed = 32;
	else if (key == SDLK_6)
		sdl->speed = 64;
}

void				pressed(int key, t_sdl *sdl, t_commands **commands)
{
	int i;

	i = sdl->speed;
	if (key == SDLK_ESCAPE)
		exit(0);
	else if (key == SDLK_SPACE)
	{
		if (*commands != NULL)
		{
			while (i-- != 0 && *commands != NULL)
			{
				make_command(sdl->stacks, *commands);
				(*commands) = (*commands)->next;
			}
			draw(sdl);
		}
	}
	else
		check_speed(key, sdl);
}
