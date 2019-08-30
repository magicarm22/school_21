/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visualize.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djast <djast@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/20 16:59:23 by djast             #+#    #+#             */
/*   Updated: 2019/08/30 13:54:34 by djast            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "commands.h"

static t_sdl		*create_window(void)
{
	t_sdl	*sdl;

	sdl = (t_sdl *)malloc(sizeof(t_sdl));
	SDL_Init(SDL_INIT_VIDEO);
	sdl->window = SDL_CreateWindow("Hello", SDL_WINDOWPOS_UNDEFINED,
					SDL_WINDOWPOS_UNDEFINED, SIZE_WINDOW_X, SIZE_WINDOW_Y,
					SDL_WINDOW_OPENGL);
	sdl->renderer = SDL_CreateRenderer(sdl->window, -1,
											SDL_RENDERER_ACCELERATED);
	SDL_SetWindowFullscreen(sdl->window, SDL_WINDOW_FULLSCREEN_DESKTOP);
	return (sdl);
}

static t_commands	*make_push_swap(int argc, const char **argv)
{
	t_stacks	*stacks;
	t_commands	*commands;

	stacks = init_lists();
	commands = (t_commands *)malloc(sizeof(t_commands));
	commands->data = NULL;
	commands->next = NULL;
	if (check_params(argc, argv, stacks) == CHECK_ERROR)
	{
		write(1, "ERROR\n", 6);
		return (NULL);
	}
	translate_to_1_n(stacks->head_a);
	translate_to_1_n(stacks->head_a);
	sorting(stacks, &commands);
	optimizate_commands(&commands, "rb", "ra", "rr");
	optimizate_commands(&commands, "sb", "sa", "ss");
	optimizate_commands(&commands, "rrb", "rra", "rrr");
	return (commands);
}

static t_sdl		*show(int argc, const char **argv, t_sdl *sdl)
{
	sdl->stacks = init_lists();
	check_params(argc, argv, sdl->stacks);
	translate_to_1_n(sdl->stacks->head_a);
	sdl->stack_size = size_list(sdl->stacks->head_a);
	sdl->speed = 1;
	draw(sdl);
	return (sdl);
}

int					main(int argc, const char **argv)
{
	t_sdl		*sdl;
	t_commands	*commands;
	SDL_Event	window_event;

	if (argc < 2)
		return (-1);
	sdl = create_window();
	commands = make_push_swap(argc, argv);
	show(argc, argv, sdl);
	while (1)
	{
		if (SDL_PollEvent(&window_event))
		{
			if (SDL_QUIT == window_event.type)
				break ;
			else if (window_event.type == SDL_KEYDOWN)
				pressed(window_event.key.keysym.sym, sdl, &commands);
		}
	}
	SDL_DestroyWindow(sdl->window);
	SDL_Quit();
	free(sdl);
	return (0);
}
