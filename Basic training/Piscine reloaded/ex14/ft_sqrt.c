/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djast <djast@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 12:07:50 by djast             #+#    #+#             */
/*   Updated: 2018/11/20 12:23:18 by djast            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_sqrt(int nb)
{
	int i;
	int sqr;
	int check;

	i = 0;
	if (nb % 2 == 0)
		check = nb / 2;
	else
		check = (nb - 1) / 2;
	while (i <= check)
	{
		sqr = i * i;
		if (sqr == nb)
			return (i);
		if (sqr > nb)
			return (0);
		if ((i + 10) * (i + 10) < nb)
			i += 10;
		else
			i++;
	}
	return (0);
}
