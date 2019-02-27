/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djast <djast@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 12:18:51 by djast             #+#    #+#             */
/*   Updated: 2018/11/20 12:23:07 by djast            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

int		check(char *first, char *second)
{
	int		count_first;
	int		count_second;
	char	*min;
	int		flag;

	count_first = 0;
	count_second = 0;
	while (first[count_first])
		count_first++;
	while (second[count_second])
		count_second++;
	flag = 0;
	min = first;
	if (count_second < count_first)
	{
		flag = 1;
		min = second;
	}
	count_first = 0;
	while (min[count_first++])
		if (first[count_first - 1] > second[count_first - 1])
			return (1);
		else if (first[count_first - 1] < second[count_first - 1])
			return (0);
	return (flag);
}

void	print_argv(int argc, char *argv[])
{
	char	*tmp;
	int		i;
	int		j;

	i = 2;
	j = 1;
	while (argc-- != 1)
	{
		tmp = argv[j];
		i = 0;
		while (tmp[i++])
			ft_putchar(tmp[i - 1]);
		ft_putchar('\n');
		j++;
	}
}

int		ft_swap(char **a, char **b)
{
	char	*tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
	return (1);
}

int		main(int argc, char *argv[])
{
	int		i;
	int		flag;

	i = 2;
	if (argc < 2)
		return (0);
	while (1)
	{
		i = 2;
		flag = 0;
		while (argv[i++])
		{
			if (check(argv[i - 2], argv[i - 1]) == 1)
				flag = ft_swap(&argv[i - 2], &argv[i - 1]);
		}
		if (flag == 0)
		{
			print_argv(argc, argv);
			break ;
		}
	}
	return (0);
}
