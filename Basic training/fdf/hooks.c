/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djast <djast@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/24 13:02:30 by djast             #+#    #+#             */
/*   Updated: 2019/02/24 17:07:49 by djast            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int		key_release(int key, t_mlx *mlx)
{
	if (key == 126)
		rotate_up_down(mlx, 1);
	else if (key == 125)
		rotate_up_down(mlx, 2);
	else if (key == 123)
		rotate_left_right(mlx, 1);
	else if (key == 124)
		rotate_left_right(mlx, 2);
	else if (key == 84)
		rotate_in_out(mlx, 1);
	else if (key == 91)
		rotate_in_out(mlx, 2);
	else if (key == 15)
		reset(mlx);
	else if (key == 0 || key == 2 || key == 1 || key == 13)
		move(mlx, key);
	else if (key == 53)
		close_win(mlx);
	else if (key == 4)
		change_state_legend(mlx);
	else if (key == 34)
		iso(mlx);
	return (0);
}

int		mouse_press(int button, int x, int y, t_mlx *mlx)
{
	(void)x;
	(void)y;
	if (button == 4)
		zoom_in_out(mlx, 1);
	else if (button == 5)
		zoom_in_out(mlx, 2);
	return (0);
}

int		close_win(t_mlx *mlx)
{
	free_mem(mlx);
	exit(0);
	return (0);
}

void	reset(t_mlx *mlx)
{
	close(mlx->fd);
	if (!(mlx->fd = open(mlx->filename, O_RDONLY)))
	{
		perror("Can't open file");
		exit(-1);
	}
	if (check_map(mlx->fd, mlx) == -1)
	{
		perror("Non valid file!");
		exit(-1);
	}
	close(mlx->fd);
	if (!(mlx->fd = open(mlx->filename, O_RDONLY)))
	{
		perror("Can't open file");
		exit(-1);
	}
	create_map(mlx->fd, &mlx);
	fill_mlx(mlx, 1);
	restart(mlx);
}
