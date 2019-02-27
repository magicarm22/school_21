/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djast <djast@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/27 18:41:23 by djast             #+#    #+#             */
/*   Updated: 2019/02/27 19:53:31 by djast            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

t_ls *init_struct()
{
	t_ls *ls;

	ls = (t_ls *)malloc(sizeof(t_ls));
	ls->is_reversed = 0;
	ls->is_recursive = 0;
	ls->is_with_dot = 0;
	ls->is_sort_by_time = 0;
	ls->long_format = 0;
	ls->dir_struct = NULL;
	ls->path = NULL;
	return (ls);
}

int main(int argc, char const *argv[])
{
	t_ls *ls;

	ls = init_struct();
	if (argc > 1 && parsing_flags(argc, argv, ls) == -1)
	{
		ft_printf("ft_ls: illegal option -- ??\nusage: ls [-Ralrt] [file ...]\n");
		return (-1);
	}
	print_struct(ls);
	return 0;
}