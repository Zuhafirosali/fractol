/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zfiros-a <zfiros-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 14:34:08 by zfiros-a          #+#    #+#             */
/*   Updated: 2024/02/02 17:16:14 by zfiros-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	julia_param_valid(char *param)
{
	int	point_count;
	int	len;
	int	valid;
	int	i;

	valid = 1;
	len = ft_strlen(param);
	i = 0;
	point_count = 0;
	while (i < len)
	{
		if (param[i] == '.')
			point_count++;
		else if (!ft_isdigit(param[i]) && (param[i] != '-' || i != 0))
		{
			valid = 0;
			break ;
		}
		i++;
	}
	if (point_count > 1)
		valid = 0;
	return (valid);
}

int	check_julia_param(t_fractal *fractol, char **av)
{
	if (av[2] == NULL || av[3] == NULL)
	{
		ft_putstr_fd("CHECK ARGS", 2);
		return (0);
	}
	if (!julia_param_valid(av[2]) || !julia_param_valid(av[3]))
	{
		ft_putstr_fd("CHECK ARGS", 2);
		return (0);
	}
	fractol->julia_x = ft_atod(av[2]);
	fractol->julia_y = ft_atod(av[3]);
	if (fractol->julia_x < -2 || fractol->julia_x > 2 || fractol->julia_y < -2
		|| fractol->julia_y > 2)
	{
		ft_putstr_fd("CHECK ARGS", 2);
		return (0);
	}
	return (1);
}

int	main(int ac, char **av)
{
	t_fractal	fractol;

	if (2 == ac && !ft_strncmp(av[1], "mandelbrot", 10))
	{
		fractol.name = av[1];
		fractol_init(&fractol);
		fractal_render(&fractol);
		mlx_loop(fractol.mlx_connection);
	}
	else if (4 == ac && !ft_strncmp(av[1], "julia", 5))
	{
		fractol.name = av[1];
		if (!check_julia_param(&fractol, av))
			exit(EXIT_FAILURE);
		fractol_init(&fractol);
		fractal_render(&fractol);
		mlx_loop(fractol.mlx_connection);
	}
	else
	{
		ft_putstr_fd("CHECK ARGS", 2);
		exit(EXIT_FAILURE);
	}
}
