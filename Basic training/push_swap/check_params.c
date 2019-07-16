/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_params.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djast <djast@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/24 17:17:34 by djast             #+#    #+#             */
/*   Updated: 2019/07/16 15:48:00 by djast            ###   ########.fr       */
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

int check_params(int argc, char const *argv[], t_stacks *stacks)
{
	int i;
	int success;

	if (argc < 2)
		return (CHECK_ERROR);
	i = 1;
	while (argv[i++] != '\0')
	{
		success = check_one_argv(argv[i - 1]);
		if (success == 1)
			add_list_to_back(&(stacks->head_a), ft_atoi(argv[i - 1]));
		else
			return (CHECK_ERROR);
	}
	//print_list("A: ", stacks->head_a);
	return (CHECK_SUCCESS);
}