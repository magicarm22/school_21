/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eharrag- <eharrag-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/27 13:51:14 by eharrag-          #+#    #+#             */
/*   Updated: 2019/09/24 11:42:30 by eharrag-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	draw_a_weapon(t_SDL *sdl, t_player *player)
{
	SDL_Rect	weapon_screen;
	SDL_Rect	weapon_file;

	weapon_screen.x = PISTOL_X;
	weapon_screen.y = PISTOL_Y;
	weapon_screen.w = PISTOL_SIZE_X;
	weapon_screen.h = PISTOL_SIZE_Y;

	if (player->shooting_frame != PISTOL_LAST_FRAME)
		player->shooting_frame = ((SDL_GetTicks() - player->shooting_time) * 12 / 1000) % (PISTOL_LAST_FRAME + 1);
	weapon_file.x = PISTOL_IMAGE_X * player->shooting_frame;
	weapon_file.y = PISTOL_IMAGE_Y;
	weapon_file.w = PISTOL_IMAGE_SIZE_X;
	weapon_file.h = PISTOL_IMAGE_SIZE_Y;

	SDL_RenderCopy(sdl->renderer, sdl->pistol, &weapon_file, &weapon_screen);
}

void redraw(t_SDL *SDL, t_map *map_info, t_player *player)
{
	// SDL_Rect	sky;
	SDL_Rect	floor;

	SDL_SetRenderDrawColor(SDL->renderer, 0, 0, 0, 255);
	SDL_RenderClear(SDL->renderer);

	// sky.x = 0;
	// sky.y = 0;
	// sky.w = SIZE_WIN_X;
	// sky.h = SIZE_WIN_Y / 2;

	floor.x = 0;
	floor.y = SIZE_WIN_Y / 2;
	floor.w = SIZE_WIN_X;
	floor.h = SIZE_WIN_Y / 2;

	// // Set render color (rect will be rendered in this color)
	// SDL_SetRenderDrawColor(SDL->renderer, 102, 102, 102, 0);
	// // Render rect
	// SDL_RenderFillRect(SDL->renderer, &sky);

	// Set render color (rect will be rendered in this color)
	SDL_SetRenderDrawColor(SDL->renderer, 051, 051, 051, 0);
	// Render rect
	SDL_RenderFillRect(SDL->renderer, &floor);
	draw_the_sky(SDL, player->point_of_view);
	cast_a_ray(SDL, player, map_info);
	draw_a_weapon(SDL, player);
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
	SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO);
	Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048);

	SDL->shooting = Mix_LoadWAV("resources/game/shoot.wav");
    SDL->steps = Mix_LoadWAV("resources/game/step.wav");

	SDL->window = SDL_CreateWindow("Wolf3d", SDL_WINDOWPOS_UNDEFINED,
					SDL_WINDOWPOS_UNDEFINED, SIZE_WIN_X, SIZE_WIN_Y,
					SDL_WINDOW_OPENGL);
	SDL->renderer =  SDL_CreateRenderer( SDL->window, -1, SDL_RENDERER_ACCELERATED);
	SDL_SetWindowFullscreen(SDL->window, SDL_WINDOW_FULLSCREEN_DESKTOP);
	SDL_ShowCursor(0);
	SDL_SetRelativeMouseMode(SDL_TRUE);

	//load bmp to a temporary surface
	SDL->temp = SDL_LoadBMP("resources/game/north.bmp"); // чтобы не загружать картинку и не создавать текстуру каждый раз,
	SDL->texture_north = SDL_CreateTextureFromSurface(SDL->renderer, SDL->temp);//перенести лоад и креате в мэйн + структура
	//free memory allocated to the temp SDL_Surface
	SDL_FreeSurface(SDL->temp);

	SDL->temp = SDL_LoadBMP("resources/game/south.bmp"); // чтобы не загружать картинку и не создавать текстуру каждый раз,
	SDL->texture_south = SDL_CreateTextureFromSurface(SDL->renderer, SDL->temp);//перенести лоад и креате в мэйн + структура
	//free memory allocated to the temp SDL_Surface
	SDL_FreeSurface(SDL->temp);

	SDL->temp = SDL_LoadBMP("resources/game/east.bmp"); // чтобы не загружать картинку и не создавать текстуру каждый раз,
	SDL->texture_east = SDL_CreateTextureFromSurface(SDL->renderer, SDL->temp);//перенести лоад и креате в мэйн + структура
	//free memory allocated to the temp SDL_Surface
	SDL_FreeSurface(SDL->temp);

	SDL->temp = SDL_LoadBMP("resources/game/west.bmp"); // чтобы не загружать картинку и не создавать текстуру каждый раз,
	SDL->texture_west = SDL_CreateTextureFromSurface(SDL->renderer, SDL->temp);//перенести лоад и креате в мэйн + структура
	//free memory allocated to the temp SDL_Surface
	SDL_FreeSurface(SDL->temp);

	SDL->temp = SDL_LoadBMP("resources/game/animated_pistol.bmp"); // чтобы не загружать картинку и не создавать текстуру каждый раз,
	SDL->pistol = SDL_CreateTextureFromSurface(SDL->renderer, SDL->temp);//перенести лоад и креате в мэйн + структура
	//free memory allocated to the temp SDL_Surface
	SDL_FreeSurface(SDL->temp);

	SDL->temp = SDL_LoadBMP("resources/game/night.bmp");
	SDL->texture_sky = SDL_CreateTextureFromSurface(SDL->renderer, SDL->temp);
	//free memory allocated to the temp SDL_Surface
	SDL_FreeSurface(SDL->temp);

	redraw(SDL, map_info, player);
	while (1)
	{
		if ( SDL_PollEvent(&(SDL->windowEvent)))
		{
			if (SDL->windowEvent.type == SDL_KEYDOWN && SDL_QUIT == SDL->windowEvent.type)
				break;
			else if (SDL->windowEvent.type == SDL_KEYDOWN && SDLK_ESCAPE == SDL->windowEvent.key.keysym.sym)
				break;
			else if (SDL->windowEvent.type == SDL_KEYDOWN && SDLK_a == SDL->windowEvent.key.keysym.sym)
			{
				printf("Mix_PlayingMusic\n");
				if (map_info->map[(int)(player->y + (-30 * sin((player->point_of_view + 90) * RADIAN))) / 64][(int)(player->x + 30 * cos((player->point_of_view + 90) * RADIAN)) / 64] == 0)
				{
					if( Mix_Playing(1) == 0 )
						Mix_PlayChannel(1, SDL->steps, 0);
					player->x += 10 * cos((player->point_of_view + 90) * RADIAN); // sin a = cos (a + 90)
					player->y += -10 * sin((player->point_of_view + 90) * RADIAN); // если смотреть в ноль, то шагание влево происходит с отклонением назад
				}
			}
			else if (SDL->windowEvent.type == SDL_KEYDOWN && SDLK_d == SDL->windowEvent.key.keysym.sym)
			{
				if (map_info->map[(int)(player->y + (-30 * sin((player->point_of_view + 270) * RADIAN))) / 64][(int)(player->x + 30 * cos((player->point_of_view + 270) * RADIAN)) / 64] == 0)
				{
					if( Mix_Playing(1) == 0 )
						Mix_PlayChannel(1, SDL->steps, 0);
					player->x += 10 * cos((player->point_of_view + 270) * RADIAN);// после застревания в стене не хочет ходить дэшкой
					player->y += -10 * sin((player->point_of_view + 270) * RADIAN);
				}
			}
			else if (SDL->windowEvent.type == SDL_KEYDOWN && SDLK_w == SDL->windowEvent.key.keysym.sym)
			{
				if (map_info->map[(int)(player->y + (-40 * sin(player->point_of_view * RADIAN))) / 64][(int)((player->x + 40 * cos(player->point_of_view * RADIAN)) / 64)] == 0)
				{
					if( Mix_Playing(1) == 0 )
						Mix_PlayChannel(1, SDL->steps, 0);
					player->x += 20 * cos(player->point_of_view * RADIAN);
					player->y += -20 * sin(player->point_of_view * RADIAN);
				}
			}
			else if (SDL->windowEvent.type == SDL_KEYDOWN && SDLK_s == SDL->windowEvent.key.keysym.sym)
			{
				if (map_info->map[(int)(player->y + 40 * sin(player->point_of_view * RADIAN)) / 64][(int)(player->x + (-40 * cos(player->point_of_view * RADIAN))) / 64] == 0)
				{
					if( Mix_Playing(1) == 0 )
						Mix_PlayChannel(1, SDL->steps, 0);
					player->x += -20 * cos(player->point_of_view * RADIAN);
					player->y += 20 * sin(player->point_of_view * RADIAN);
				}
			}
			// else if (SDL->windowEvent.type == SDL_KEYDOWN && SDLK_q == SDL->windowEvent.key.keysym.sym)
			// {
			// 	player->point_of_view += 3;
			// 	if (player->point_of_view == 361)
			// 		player->point_of_view = 1;
			// }
			// else if (SDL->windowEvent.type == SDL_KEYDOWN && SDLK_e == SDL->windowEvent.key.keysym.sym)
			// {
			// 	player->point_of_view -= 3;
			// 	if (player->point_of_view == 0)
			// 		player->point_of_view = 360;
			// }
			else if (SDL->windowEvent.type == SDL_MOUSEMOTION)
			{
				player->point_of_view -= SDL->windowEvent.motion.xrel / 12;
				if (player->point_of_view >= 361)
					player->point_of_view = 1;
				else if (player->point_of_view <= 0)
					player->point_of_view = 360;
			}

			if (SDL->windowEvent.type == SDL_MOUSEBUTTONDOWN &&
					SDL->windowEvent.button.button == SDL_BUTTON_LEFT)
			{
				if (player->is_shooting == 0)
				{
					Mix_PlayChannel(2, SDL->shooting, 0);
					player->is_shooting = 1;
					player->shooting_frame = 0;
					player->shooting_time = SDL_GetTicks();
				}
			}
			redraw(SDL, map_info, player);
		}
		if (player->shooting_frame != PISTOL_LAST_FRAME)
			redraw(SDL, map_info, player);
		else
			player->is_shooting = 0;
	}
	SDL_DestroyWindow(SDL->window);
    Mix_FreeChunk(SDL->steps);
    Mix_FreeChunk(SDL->shooting);
    Mix_CloseAudio();
	SDL_Quit();
}
