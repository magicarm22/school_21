/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visualize.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djast <djast@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/20 16:59:23 by djast             #+#    #+#             */
/*   Updated: 2019/07/21 20:16:18 by djast            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "commands.h"


void create_window(t_SDL *SDL)
{
	SDL_Init(SDL_INIT_VIDEO);
    SDL->window = SDL_CreateWindow("Hello", SDL_WINDOWPOS_UNDEFINED,
    				SDL_WINDOWPOS_UNDEFINED, SIZE_WINDOW_X, SIZE_WINDOW_Y,
    				SDL_WINDOW_OPENGL);
	SDL->renderer =  SDL_CreateRenderer( SDL->window, -1, SDL_RENDERER_ACCELERATED);
	SDL_SetWindowFullscreen(SDL->window, SDL_WINDOW_FULLSCREEN_DESKTOP);
}

void make_command(t_stacks *stacks, t_commands *commands)
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


void draw_stack(t_SDL *SDL, t_stack *stack, int status)
{
	t_stack *cur_list;
	SDL_Rect r;
	int i;
	cur_list = stack;
	i = 0;
	while (cur_list != NULL)
	{
		r.x = status == 0 ? 0 : SIZE_STACKS_X / 2;
		r.y = i * SIZE_WINDOW_Y / SDL->stack_size ;
		r.h = SIZE_WINDOW_Y / SDL->stack_size ;
		r.w = (double)cur_list->data / (double)SDL->stack_size  * SIZE_STACKS_X / 2;
		SDL_SetRenderDrawColor( SDL->renderer, 255, 0, 0, 255 );
		SDL_RenderFillRect( SDL->renderer, &r );
		cur_list = cur_list->next;
		i++;
	}
}

void draw(t_SDL *SDL)
{
	
	SDL_SetRenderDrawColor( SDL->renderer, 0, 0, 0, 255 );
	SDL_RenderClear(SDL->renderer);
	draw_stack(SDL, SDL->stacks->head_a, 0);
	draw_stack(SDL, SDL->stacks->head_b, 1);
	SDL_RenderPresent(SDL->renderer);
}

void pressed(int key, t_SDL *SDL, t_commands **commands)
{
	int i;

	i = SDL->speed;
	if (key == SDLK_ESCAPE)
		exit(0);
	else if (key == SDLK_SPACE)
	{
		if (*commands != NULL)
		{
			while (i-- != 0 && *commands != NULL)
			{
				make_command(SDL->stacks, *commands);
				(*commands) = (*commands)->next;
			}
			draw(SDL);
		}
	}
	else if (key == SDLK_1)
		SDL->speed = 1;
	else if (key == SDLK_2)
		SDL->speed = 2;
	else if (key == SDLK_3)
		SDL->speed = 4;
	else if (key == SDLK_4)
		SDL->speed = 8;
	else if (key == SDLK_5)
		SDL->speed = 16;
	else if (key == SDLK_6)
		SDL->speed = 32;
	else if (key == SDLK_6)
		SDL->speed = 64;
}

t_commands *make_push_swap(int argc, const char **argv)
{
	t_stacks *stacks;
	t_commands *commands;

	stacks = init_lists();
	commands = (t_commands *) malloc(sizeof(t_commands));
	commands->data = NULL;
	commands->next = NULL;

	if (check_params(argc, argv, stacks) == CHECK_ERROR)
	{
		write(1, "ERROR\n", 6);
		return (NULL);
	}
	translate_to_1_N(stacks->head_a);
	sorting(stacks, &commands);
	optimizate_commands(&commands, "rb", "ra", "rr");
	optimizate_commands(&commands, "sb", "sa", "ss");
	optimizate_commands(&commands, "rrb", "rra", "rrr");
	return commands;
}



int main(int argc, const char **argv) 
{
	t_SDL *SDL;
	t_commands *commands;

	if (argc < 2)
		return 0;
	SDL = (t_SDL *)malloc(sizeof(t_SDL));
	create_window(SDL);


	commands = make_push_swap(argc, argv);
	
	SDL->stacks = init_lists();
	check_params(argc, argv, SDL->stacks);
	translate_to_1_N(SDL->stacks->head_a);
	SDL->stack_size = size_list(SDL->stacks->head_a);
	SDL->speed = 1;

    SDL_Event windowEvent;
    draw(SDL);

 	while ( 1 )
    {
        if ( SDL_PollEvent( &windowEvent ) )
        {
            if ( SDL_QUIT == windowEvent.type )
                break;
            else if (windowEvent.type == SDL_KEYDOWN)
            	pressed(windowEvent.key.keysym.sym, SDL, &commands);
        }
    }
    SDL_DestroyWindow(SDL->window);
    SDL_Quit();
    free(SDL);
    return 0;
}