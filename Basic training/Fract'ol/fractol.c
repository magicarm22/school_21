/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djast <djast@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/20 14:18:33 by djast             #+#    #+#             */
/*   Updated: 2019/06/08 15:51:22 by djast            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	main(int argc, char const *argv[])
{
	if (argc < 2 || (ft_strcmp(argv[1], "julia") != 0 &&
		ft_strcmp(argv[1], "mandelbrot") != 0 &&
		ft_strcmp(argv[1], "burning ship") != 0 &&
		ft_strcmp(argv[1], "newton") != 0 &&
		ft_strcmp(argv[1], "cubic") != 0 &&
		ft_strcmp(argv[1], "quadratic") != 0 && 
		ft_strcmp(argv[1], "fifth") != 0))
	{
		ft_putstr("Invalid argument\n");
		ft_putstr("Usage: ./fractol [julia/mandelbrot/burning ship/newton/"
			"cubic/quadratic/fifth/phoenix]");
		return (-1);
	}
	start_mlx(argv[1]);
	return (0);
}
