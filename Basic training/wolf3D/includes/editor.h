/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   editor.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eharrag- <eharrag-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/15 12:59:27 by djast             #+#    #+#             */
/*   Updated: 2019/09/26 11:11:07 by eharrag-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EDITOR_H
# define EDITOR_H
# include <SDL.h>
# include <SDL_ttf.h>
# include <limits.h>
# include <fcntl.h>
# include "libft.h"
# include "get_next_line.h"

# define SIZE_WIN_X 2560
# define SIZE_WIN_Y 1440

# define MESH_START_X 40
# define MESH_START_Y 40

# define BASIC_MAP_SIZE_X 32
# define BASIC_MAP_SIZE_Y 32

# define COLOR_UNPUSHED 0
# define COLOR_PUSHED 1
# define COLOR_NEUTRAL 2

# define FLOOR_PUSH 0
# define WALL_PUSH 1
# define PLAYER_PUSH 2

# define BUTTON_X SIZE_WIN_X * 0.81875
# define BUTTON_SIZE_X SIZE_WIN_X * 0.04
# define BUTTON_SIZE_Y 40

# define BUTTON_SAVE_X BUTTON_X
# define BUTTON_SAVE_Y SIZE_WIN_Y * 0.85
# define BUTTON_SAVE_SIZE_X BUTTON_SIZE_X

# define BUTTON_LOAD_X BUTTON_X + BUTTON_SIZE_X * 3
# define BUTTON_LOAD_Y SIZE_WIN_Y * 0.85
# define BUTTON_LOAD_SIZE_X BUTTON_SIZE_X

# define BUTTON_WALL_X BUTTON_X
# define BUTTON_FLOOR_X BUTTON_X + BUTTON_SIZE_X * 1.5
# define BUTTON_PLAYER_X BUTTON_X + BUTTON_SIZE_X * 3

# define BUTTON_WALL_Y SIZE_WIN_Y * 0.05
# define BUTTON_FLOOR_Y SIZE_WIN_Y * 0.05
# define BUTTON_PLAYER_Y SIZE_WIN_Y * 0.05

# define INPUT_MAP_NAME_SIZE_X SIZE_WIN_X * 0.16
# define INPUT_MAP_NAME_Y SIZE_WIN_Y * 0.8

# define TEXT_RESULT_Y SIZE_WIN_Y * 0.75

# define TEXT_MAP_X SIZE_WIN_X * 0.86
# define TEXT_MAP_Y SIZE_WIN_Y * 0.1
# define TEXT_MAP_SIZE_X SIZE_WIN_X * 0.08
# define TEXT_MAP_SIZE_Y 40

# define TEXT_X_X BUTTON_X
# define TEXT_X_Y SIZE_WIN_Y * 0.15
# define TEXT_X_SIZE_X SIZE_WIN_X * 0.03
# define TEXT_X_SIZE_Y 40

# define BUTTON_UP_X_X TEXT_X_X + TEXT_X_SIZE_X + 0.015
# define BUTTON_UP_X_Y TEXT_X_Y
# define BUTTON_UP_X_SIZE_X 20
# define BUTTON_UP_X_SIZE_Y 20

# define BUTTON_DOWN_X_X TEXT_X_X + TEXT_X_SIZE_X + 0.015
# define BUTTON_DOWN_X_Y TEXT_X_Y + 20
# define BUTTON_DOWN_X_SIZE_X 20
# define BUTTON_DOWN_X_SIZE_Y 20

# define TEXT_Y_X BUTTON_X + BUTTON_SIZE_X * 2.8
# define TEXT_Y_Y SIZE_WIN_Y * 0.15
# define TEXT_Y_SIZE_X SIZE_WIN_X * 0.03
# define TEXT_Y_SIZE_Y 40

# define BUTTON_UP_Y_X TEXT_Y_X + TEXT_Y_SIZE_X + 0.015
# define BUTTON_UP_Y_Y TEXT_Y_Y
# define BUTTON_UP_Y_SIZE_X 20
# define BUTTON_UP_Y_SIZE_Y 20

# define BUTTON_DOWN_Y_X TEXT_Y_X + TEXT_Y_SIZE_X + 0.015
# define BUTTON_DOWN_Y_Y TEXT_Y_Y + 20
# define BUTTON_DOWN_Y_SIZE_X 20
# define BUTTON_DOWN_Y_SIZE_Y 20

# define INPUT_LETTER_SIZE 20

# define COLOR_RESULT_ERROR 0
# define COLOR_RESULT_OK 1

# define ERROR_OK 1
# define ERROR_NO_PLAYER -1
# define ERROR_NO_FILENAME -2
# define ERROR_NO_FILE -3
# define ERROR_NON_VALID_FILE -4

typedef struct				s_sdl
{
	SDL_Window				*window;
	SDL_Renderer			*renderer;
	SDL_Event				window_event;
	SDL_Texture				*floor;
	SDL_Texture				*wall;
	SDL_Texture				*player_texture;
	SDL_Texture				*text;
	SDL_Texture				*backgroud;
	SDL_Texture				*panel;
	SDL_Texture				*arrow_up;
	SDL_Texture				*arrow_down;
	SDL_Surface				*surface;
	struct s_input_field	*map_name;
	TTF_Font				*font;
	int						button_pushed;
	int						input_pushed;
	struct s_mesh			*mesh;
	struct s_player			*player;
	int						status_save;
}							t_sdl;

typedef struct				s_player
{
	int						x;
	int						y;
}							t_player;

typedef struct				s_mesh
{
	int						x;
	int						y;
	int						size_x;
	int						size_y;
	int						zoom;
	int						**map;
}							t_mesh;

typedef struct				s_input_field
{
	int						x;
	int						y;
	int						size_x;
	int						size_y;
	int						max_text_size;
	char					*text;
	int						text_size;
}							t_input_field;

void						draw_full(t_sdl *sdl);
void						init_mesh(t_sdl **sdl);
void						init_map(t_mesh **mesh);
int							change_map_size(t_sdl *sdl);
t_sdl						*init_sdl(void);
t_input_field				*init_input_field(int x, int y,
								int size_x, int size_y);
void						action_mouse(t_sdl *sdl, int *click);
void						choose_mesh_zoom(t_sdl *sdl);
void						draw_right_panel(t_sdl *sdl);
void						draw_button(t_sdl *sdl, SDL_Rect r,
								char *name, int color);
void						draw_text(t_sdl *sdl, char *text, SDL_Rect r,
								SDL_Color color);
void						draw_result_text(t_sdl *sdl, char *text,
								int color_status);
SDL_Color					*create_sdl_color(int r, int g, int b, int a);
SDL_Rect					*create_sdl_rect(int x, int y, int w, int h);
int							action_keyboard(t_sdl *sdl);
void						textinput(t_sdl *sdl);
void						save_map(t_sdl *sdl);
void						load_map(t_sdl *sdl);
void						change_player_position(t_sdl *sdl, int x, int y);
int							ft_num_len(int n);
void						reset_swaped(t_sdl *sdl);
int							countwords(char *str, char c);
void						free_map(t_mesh *mesh);
void						destroy(t_sdl *sdl);
#endif
