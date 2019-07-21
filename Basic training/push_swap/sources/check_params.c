/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_params.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djast <djast@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/24 17:17:34 by djast             #+#    #+#             */
/*   Updated: 2019/07/21 17:18:49 by djast            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "commands.h"

static int check_one_argv(const char *argv)
{
	int j;
	int success;

	j = 0;
	success = 0;
	if (argv[j] == '-' || argv[j] == '+')
		j++;
	while (argv[j++] != '\0')
	{

		success = 1;
		if (!ft_isdigit(argv[j - 1]))
		{
			success = 0;
			break;
		}
	}
	return (success);
}

int parse_var(const char *str, t_stacks *stacks)
{
	char **argv;
	int success;
	int i;

	argv = ft_strsplit((char *)str, ' ');
	i = 0;
	while (argv[i++] != '\0')
	{
		success = check_one_argv(argv[i - 1]);
		if (success == 1)
		{
			if (get_index_by_elem(stacks->head_a, ft_atoi(argv[i - 1])) != -1)
				return (CHECK_ERROR);
			add_list_to_back(&(stacks->head_a), ft_atoi(argv[i - 1]));
		}
		else
			return (CHECK_ERROR);
	}
	return (CHECK_SUCCESS);
}

int check_params(int argc, char const *argv[], t_stacks *stacks)
{
	int i;
	int success;

	if (argc == 1)
		return (CHECK_ERROR);
	if (argc == 2)
		return parse_var(argv[1], stacks);
	i = 1;
	while (argv[i++] != '\0')
	{
		success = check_one_argv(argv[i - 1]);
		if (success == 1)
		{
			if (get_index_by_elem(stacks->head_a, ft_atoi(argv[i - 1])) != -1)
				return (CHECK_ERROR);
			add_list_to_back(&(stacks->head_a), ft_atoi(argv[i - 1]));
		}
		else
			return (CHECK_ERROR);
	}
	return (CHECK_SUCCESS);
}