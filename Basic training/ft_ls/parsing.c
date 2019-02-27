/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djast <djast@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/27 19:21:58 by djast             #+#    #+#             */
/*   Updated: 2019/02/27 19:51:23 by djast            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

static int fill_flags(const char **str, t_ls *ls)
{
	int flag;

	flag = 0;
	while (**str == 'r' || **str == 'R' || **str == 'l' || **str == 'a' || **str == 't')
	{
		if (**str == 'r')
			ls->is_reversed = 1;
		else if (**str == 'R')
			ls->is_recursive = 1;
		else if (**str == 'l')
			ls->long_format = 1;
		else if (**str == 'a')
			ls->is_with_dot = 1;
		else if (**str == 't')
			ls->is_sort_by_time = 1;
		flag = 1;
		(*str)++;
	}
	return (flag);
}

int parsing_flags(int argc, char const *flags[], t_ls *ls)
{
	int i;
	int flag;

	i = 0;
	while (i++ < argc - 1)
	{
		flag = 0;
		if (*flags[i] == '-')
		{
			++flags[i];
			flag = fill_flags(&(flags[i]), ls);
		}
		if (*flags[i] != '\0' || flag != 1 )
			return (-1);
	}
	return (0);
}