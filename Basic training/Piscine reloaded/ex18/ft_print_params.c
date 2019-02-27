/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_params.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djast <djast@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 12:12:23 by djast             #+#    #+#             */
/*   Updated: 2018/11/20 12:23:07 by djast            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

int		main(int argc, char *argv[])
{
	char	*name;
	int		i;
	int		j;

	j = 1;
	while (argc-- != 1)
	{
		name = argv[j];
		i = 0;
		while (name[i++])
			ft_putchar(name[i - 1]);
		ft_putchar('\n');
		j++;
	}
	return (0);
}
