/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djast <djast@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/24 17:42:47 by djast             #+#    #+#             */
/*   Updated: 2019/06/30 14:01:44 by djast            ###   ########.fr       */
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

unsigned int		size_list(t_stack *stack)
{
	unsigned int size;
	t_stack *cur_list;

	cur_list = stack;
	size = 0;
	while (cur_list != NULL)
	{
		size++;
		cur_list = cur_list->next;
	}
	return (size);

}