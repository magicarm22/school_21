/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eharrag- <eharrag-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/27 13:51:14 by eharrag-          #+#    #+#             */
/*   Updated: 2019/09/17 12:07:37 by eharrag-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void redraw(t_SDL *SDL, t_map *map_info, t_player *player)
{
//	SDL_Texture	*texture_sky;
	SDL_Rect	sky;
//	SDL_Surface *temp;

	SDL_SetRenderDrawColor(SDL->renderer, 0, 0, 0, 255);
	SDL_RenderClear(SDL->renderer);
	//load bmp to a temporary surface
//	temp = SDL_LoadBMP("sdl_pic.bmp"); // чтобы не загружать картинку и не создавать текстуру каждый раз,
//	texture_sky = SDL_CreateTextureFromSurface(SDL->renderer, temp);//перенести лоад и креате в мэйн + структура
	//free memory allocated to the temp SDL_Surface
//	SDL_FreeSurface(temp);
	sky.x = 0;
	sky.y = 0;
	sky.w = SIZE_WIN_X;
//	sky.h = SIZE_WIN_Y / 2;
	sky.h = SIZE_WIN_Y;
	// Set render color (rect will be rendered in this color)
	SDL_SetRenderDrawColor(SDL->renderer, 051, 051, 051, 0);

	// Render rect
	SDL_RenderFillRect(SDL->renderer, &sky);
//	SDL_RenderCopy(SDL->renderer, texture_sky, NULL, &sky);
	cast_a_ray(SDL, player, map_info);
	SDL_RenderPresent(SDL->renderer);
}

int	main (int argc, char **argv)
{
	t_map		*map_info;
	t_player	*player;
	int			fd;

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
	while (1)
	{
		if ( SDL_PollEvent(&(SDL->windowEvent)))
		{
			if (SDL_QUIT == SDL->windowEvent.type)
				break;
			else if (SDLK_ESCAPE == SDL->windowEvent.key.keysym.sym)
				break;
			else if (SDLK_a == SDL->windowEvent.key.keysym.sym)
			{
				if (map_info->map[(int)(player->y + (-10 * sin((player->point_of_view + 90) * RADIAN))) / 64][(int)(player->x + 10 * cos((player->point_of_view + 90) * RADIAN)) / 64] == 0)
				{
					player->x += 10 * cos((player->point_of_view + 90) * RADIAN); // sin a = cos (a + 90)
					player->y += -10 * sin((player->point_of_view + 90) * RADIAN); // если смотреть в ноль, то шагание влево происходит с отклонением назад
				}
			}
			else if (SDLK_d == SDL->windowEvent.key.keysym.sym)
			{
				if (map_info->map[(int)(player->y + (-10 * sin((player->point_of_view + 270) * RADIAN))) / 64][(int)(player->x + 10 * cos((player->point_of_view + 270) * RADIAN)) / 64] == 0)
				{
					player->x += 10 * cos((player->point_of_view + 270) * RADIAN);// после застревания в стене не хочет ходить дэшкой
					player->y += -10 * sin((player->point_of_view + 270) * RADIAN);
				}
			}
			else if (SDLK_w == SDL->windowEvent.key.keysym.sym)
			{
				if (map_info->map[(int)(player->y + (-10 * sin(player->point_of_view * RADIAN))) / 64][(int)((player->x + 10 * cos(player->point_of_view * RADIAN)) / 64)] == 0)
				{
					player->x += 10 * cos(player->point_of_view * RADIAN);
					player->y += -10 * sin(player->point_of_view * RADIAN);
				}
			}
			else if (SDLK_s == SDL->windowEvent.key.keysym.sym)
			{
				if (map_info->map[(int)(player->y + 10 * sin(player->point_of_view * RADIAN)) / 64][(int)(player->x + (-10 * cos(player->point_of_view * RADIAN))) / 64] == 0)
				{
					player->x += -10 * cos(player->point_of_view * RADIAN);
					player->y += 10 * sin(player->point_of_view * RADIAN);
				}
			}
			else if (SDLK_q == SDL->windowEvent.key.keysym.sym)
			{
				player->point_of_view += 1;
				if (player->point_of_view == 361)
					player->point_of_view = 1;
			}
			else if (SDLK_e == SDL->windowEvent.key.keysym.sym)
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
