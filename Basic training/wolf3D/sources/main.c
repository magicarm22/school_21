/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eharrag- <eharrag-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/27 13:51:14 by eharrag-          #+#    #+#             */
/*   Updated: 2019/09/14 12:42:57 by eharrag-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void redraw(t_SDL *SDL, t_map *map_info, t_player *player)
{
	SDL_SetRenderDrawColor(SDL->renderer, 0, 0, 0, 255);
	SDL_RenderClear(SDL->renderer);
	cast_a_ray(SDL, player, map_info);
	SDL_RenderPresent(SDL->renderer);
}

int	main (int argc, char **argv)
{
	t_map *map_info;
	t_player *player;
	int fd;

	if (argc < 2)
	{
		write(1, "Error, write map name\n", 22);
		return (-1);
	}
	fd = open(argv[1], O_RDONLY);
	if (read(fd, NULL, 0) == -1)
	{
		write(1, "Error, no such map\n", 19);
		return (-1);
	}
	player = (t_player *)malloc(sizeof(t_player));
	map_info = get_map_from_file(player, fd);
	if (map_info == NULL)
	{
		write(1, "Wrong with map format\n", 22);
		return (-1);
	}
	t_SDL *SDL;

	SDL = (t_SDL *)malloc(sizeof(t_SDL));
	SDL_Init(SDL_INIT_VIDEO);
   	SDL->window = SDL_CreateWindow("Wolf3d", SDL_WINDOWPOS_UNDEFINED,
                   SDL_WINDOWPOS_UNDEFINED, SIZE_WIN_X, SIZE_WIN_Y,
                   SDL_WINDOW_OPENGL);
    SDL->renderer =  SDL_CreateRenderer( SDL->window, -1, SDL_RENDERER_ACCELERATED);


    SDL_SetWindowFullscreen(SDL->window, SDL_WINDOW_FULLSCREEN_DESKTOP);
	redraw(SDL, map_info, player);
	while ( 1 )
	{
		if ( SDL_PollEvent( &(SDL->windowEvent) ) )
		{
			if ( SDL_QUIT == SDL->windowEvent.type )
				break;
			else if ( SDLK_ESCAPE == SDL->windowEvent.key.keysym.sym )
				break;
			else if ( SDLK_a == SDL->windowEvent.key.keysym.sym )
			{
				player->x += 10 * sin(player->point_of_view * 0.0175); // sin a = cos (a + 90)//ДОДЕЛАТЬ
				player->y += -10 * cos(player->point_of_view * 0.0175);
			}
			else if ( SDLK_d == SDL->windowEvent.key.keysym.sym )
			{
				player->x += -10 * sin(player->point_of_view * 0.0175); //ДОДЕЛАТЬ
				player->y += 10 * cos(player->point_of_view * 0.0175);
			}
			else if ( SDLK_w == SDL->windowEvent.key.keysym.sym )
			{
				player->x += 10 * cos(player->point_of_view * 0.0175);
				player->y += -10 * sin(player->point_of_view * 0.0175);
			}
			else if ( SDLK_s == SDL->windowEvent.key.keysym.sym )
			{
				player->x += -10 * cos(player->point_of_view * 0.0175);
				player->y += 10 * sin(player->point_of_view * 0.0175);
			}
			else if ( SDLK_q == SDL->windowEvent.key.keysym.sym )
			{
				player->point_of_view += 1;
				if (player->point_of_view == 361)
					player->point_of_view = 1;
			}
			else if ( SDLK_e == SDL->windowEvent.key.keysym.sym )
			{
				player->point_of_view -= 1;
				if (player->point_of_view == 0)
					player->point_of_view = 360;
			}
			redraw(SDL, map_info, player);
		}
	}
	SDL_DestroyWindow(SDL->window);
	SDL_Quit();
}
