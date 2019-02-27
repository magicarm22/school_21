/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djast <djast@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 12:20:00 by djast             #+#    #+#             */
/*   Updated: 2018/11/20 14:10:39 by djast            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strdup(char *src)
{
	int		len_src;
	char	*dest;

	len_src = 0;
	while (src[len_src])
		len_src++;
	dest = (char *)malloc(len_src + 1);
	if (dest != NULL)
	{
		len_src = 0;
		while (src[len_src++])
			dest[len_src - 1] = src[len_src - 1];
	}
	dest[len_src - 1] = '\0';
	return (dest);
}
