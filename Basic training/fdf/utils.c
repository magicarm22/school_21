/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djast <djast@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/15 20:15:36 by djast             #+#    #+#             */
/*   Updated: 2019/02/24 16:45:23 by djast            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int				ft_arrc_size(char **str)
{
	int count;

	count = 0;
	while (*str++)
		count++;
	return (count);
}

int				ft_si(int n)
{
	unsigned int	count;

	count = 0;
	if (n < 0)
		count++;
	while ((n = n / 10) != 0)
		count++;
	return (count + 1);
}

int				ft_size_char(char *arr)
{
	int count;

	count = 0;
	while (*arr++)
		count++;
	return (count);
}

intmax_t		ft_recursive_power(intmax_t nb, intmax_t power)
{
	if (power < 0)
		return (0);
	if (power == 0)
		return (1);
	if (power == 1)
		return (nb);
	return (nb * ft_recursive_power(nb, power - 1));
}

void			add_zeroes(t_mlx **info_map, int x, int y)
{
	while (x < (*info_map)->size_map_x)
	{
		(*info_map)->points[y][x].x = x;
		(*info_map)->points[y][x].y = y;
		(*info_map)->points[y][x].z = 0;
		if ((*info_map)->is_color == 0)
			(*info_map)->points[y][x].color = WH;
		x++;
	}
}
