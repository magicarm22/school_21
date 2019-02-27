/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_file.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djast <djast@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 13:12:16 by djast             #+#    #+#             */
/*   Updated: 2018/11/20 14:09:03 by djast            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	int a;

	a = 0;
	while (str[a])
	{
		ft_putchar(str[a]);
		a++;
	}
}

void	clear_buf(char buf[1024])
{
	int i;

	i = 0;
	while (i < 1024)
		buf[i++] = 0;
}

int		main(int argc, char const *argv[])
{
	int		fd;
	int		bytes;
	char	buf[1024];

	if (argc == 1)
		ft_putstr("File name missing.\n");
	if (argc > 2)
		ft_putstr("Too many arguments.\n");
	if (argc != 2)
		return (0);
	fd = open(argv[1], O_RDONLY);
	while ((bytes = read(fd, buf, 1023)) != 0)
	{
		ft_putstr(buf);
		clear_buf(buf);
	}
	close(fd);
	return (0);
}
