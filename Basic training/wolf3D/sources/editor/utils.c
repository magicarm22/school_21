/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djast <djast@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/17 12:19:51 by djast             #+#    #+#             */
/*   Updated: 2019/09/19 16:20:22 by djast            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "editor.h"

int		ft_num_len(int n)
{
	int	count;

	count = 0;
	while ((n = n / 10) != 0)
		count++;
	return (count + 1);
}

void change_player_position(t_sdl *sdl, int x, int y)
{
	int i;
	int j;

	i = 0;
	while (i < sdl->mesh->size_y)
	{
		j = 0;
		while (j < sdl->mesh->size_x)
		{
			if (sdl->mesh->map[i][j] == 2)
				sdl->mesh->map[i][j] = 0;
			j++;
		}
		i++;
	}
	sdl->mesh->map[y][x] = 2;
	sdl->player->x = x * 64 + 32;
	sdl->player->y = y * 64 + 32;
}

int		countwords(char *str, char c)
{
	int i;
	int result;

	i = 0;
	result = 0;
	while (str[i] && str[i] == c)
		i++;
	while (str[i])
	{
		while (str[i] && str[i] != c)
			i++;
		result++;
		while (str[i] && str[i] == c)
			i++;
	}
	return (result);
}
