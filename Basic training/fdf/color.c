/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djast <djast@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/24 13:07:39 by djast             #+#    #+#             */
/*   Updated: 2019/02/24 16:53:24 by djast            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

long long		parse_color(char *line)
{
	int			size;
	long long	result;

	result = 0;
	size = ft_size_char(line);
	while (*line)
	{
		result += (*line - 48) * ft_recursive_power(16, size--);
		line++;
	}
	return (result);
}
