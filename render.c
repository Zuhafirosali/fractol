/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zfiros-a <zfiros-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 14:58:53 by zfiros-a          #+#    #+#             */
/*   Updated: 2024/02/02 17:08:42 by zfiros-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	fractal_render(t_fractal *fractol)
{
	int	x;
	int	y;

	y = -1;
	while (++y < HEIGHT)
	{
		x = -1;
		while (++x < WIDTH)
		{
			handle_pixel(x, y, fractol);
		}
	}
	mlx_put_image_to_window(fractol->mlx_connection,
		fractol->mlx_window,
		fractol->image.image_ptr,
		0, 0);
}

int	julia_map(int x, int y, t_fractal *fractol)
{
	t_mappingrange	rx;
	t_mappingrange	ry;

	if (!ft_strncmp(fractol->name, "julia", 5) && !fractol->lock)
	{
		rx.n_min = -2;
		rx.n_max = +2;
		rx.o_min = 0;
		rx.o_max = WIDTH;
		fractol->julia_x = map(x, rx) * fractol->zoom;
		ry.n_min = +2;
		ry.n_max = -2;
		ry.o_min = 0;
		ry.o_max = HEIGHT;
		fractol->julia_y = map(y, ry) * fractol->zoom;
		fractal_render(fractol);
	}
	return (0);
}
