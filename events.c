/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zfiros-a <zfiros-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 16:28:37 by zfiros-a          #+#    #+#             */
/*   Updated: 2024/02/02 17:16:43 by zfiros-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	close_handle(t_fractal *fractol)
{
	mlx_destroy_image(fractol->mlx_connection, fractol->image.image_ptr);
	mlx_destroy_window(fractol->mlx_connection, fractol->mlx_window);
	free(fractol->mlx_connection);
	exit(EXIT_SUCCESS);
}

int	key_handle(int key, t_fractal *fractol)
{
	if (key == 53)
		close_handle(fractol);
	if (key == 4)
		fractol->lock = !fractol->lock;
	else if (key)
	{
		if (key == 124 || key == 123)
			left_right(fractol, key);
		else if (key == 125 || key == 126)
			up_down(fractol, key);
	}
	return (0);
}

void	left_right(t_fractal *fractol, int key)
{
	double	shifting;

	shifting = 0.5 * fractol->zoom;
	if (key == 124)
		fractol->shift_x += shifting;
	if (key == 123)
		fractol->shift_x -= shifting;
}

void	up_down(t_fractal *fractol, int key)
{
	double	shifting;

	shifting = 0.5 * fractol->zoom;
	if (key == 125)
		fractol->shift_y -= shifting;
	if (key == 126)
		fractol->shift_y += shifting;
}

int	mouse_handle(int key, int x, int y, t_fractal *fractol)
{
	(void)x;
	(void)y;
	if (key == 4)
		fractol->zoom *= 0.95;
	else if (key == 5)
		fractol->zoom *= 1.05;
	fractal_render(fractol);
	return (0);
}
