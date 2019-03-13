/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vurrigon <vurrigon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/27 19:21:58 by djast             #+#    #+#             */
/*   Updated: 2019/03/10 15:01:14 by vurrigon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

//FIX multiple files

static int fill_flags(const char **str, t_ls *ls)
{
	int flag;

	flag = 0;
	while (**str == 'r' || **str == 'R' || **str == 'l' || **str == 'a' ||
	**str == 't' || **str == 'f' || **str == 'S' || **str == 'A' || **str == 'n')
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
		else if (**str == 'f')
		{
			ls->not_sort = 1;
			ls->is_with_dot = 1;
		}
		else if (**str == 'n')
		{
			ls->is_numb_gr_user = 1;
			ls->long_format = 1;
		}
		else if (**str == 'S')
			ls->is_sort_by_size = 1;
		else if (**str == 'A')
			ls->is_almost_all = 1;
		flag = 1;
		(*str)++;
	}
	if (**str != '\0')
		return (0);
	return (flag);
}

int parsing_flags(int argc, char const **flags, t_ls *ls)
{
	int i;

	i = 0;
	while (i++ < argc - 1)
	{
		ls->path = (char *)flags[i];
		if (*flags[i] == '-')
		{
			++flags[i];
			if (!(fill_flags(&(flags[i]), ls)))
				return (-1);
			ls->path = ".";
		}
		else if (opendir(flags[i]) == NULL)
			return (-2);
		else
		{
			ls->path = (char *)flags[i];
			return (0);
		}
	}
	return (0);
}