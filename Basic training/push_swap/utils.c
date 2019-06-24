/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djast <djast@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/24 17:42:47 by djast             #+#    #+#             */
/*   Updated: 2019/06/24 17:50:54 by djast            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "commands.h"

unsigned int		ft_num_size_with_sign(intmax_t n)
{
	unsigned int	count;

	count = 0;
	if (n < 0)
		count++;
	while ((n = n / 10) != 0)
		count++;
	return (count + 1);
}