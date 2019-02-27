/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djast <djast@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 12:20:41 by djast             #+#    #+#             */
/*   Updated: 2018/11/20 14:10:45 by djast            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int *arr_range;
	int i;
	int j;

	j = min;
	if (min >= max)
		return (0);
	arr_range = (int *)malloc((max - min) * sizeof(int));
	i = 0;
	while (i < max - min)
	{
		arr_range[i] = j++;
		i++;
	}
	return (arr_range);
}
