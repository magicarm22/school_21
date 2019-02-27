/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_alphabet.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djast <djast@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 11:41:45 by djast             #+#    #+#             */
/*   Updated: 2018/11/20 13:23:23 by djast            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	ft_print_alphabet(void)
{
	char symbol;

	symbol = 'a';
	while (symbol <= 'z')
	{
		ft_putchar(symbol);
		symbol++;
	}
}
