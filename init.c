/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zfiros-a <zfiros-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 13:52:28 by zfiros-a          #+#    #+#             */
/*   Updated: 2024/02/02 17:02:59 by zfiros-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	malloc_error(void)
{
	perror("malloc issues");
	exit(EXIT_FAILURE);
}

void	data_init(t_fractal *fractol)
{
	fractol->escape_value = 4;
	fractol->iterations_definition = 42;
	fractol->shift_x = 0.0;
	fractol->shift_y = 0.0;
	fractol->zoom = 1.0;
}

void	events_init(t_fractal *fractol)
{
	mlx_key_hook(fractol->mlx_window, key_handle, fractol);
	mlx_mouse_hook(fractol->mlx_window, mouse_handle,
		fractol);
	mlx_hook(fractol->mlx_window, 17, 1L << 17, close_handle,
		fractol);
	mlx_hook(fractol->mlx_window, 6, 1L << 6, julia_map,
		fractol);
}

void	fractol_init(t_fractal *fractol)
{
	fractol->mlx_connection = mlx_init();
	if (fractol->mlx_connection == NULL)
		malloc_error();
	fractol->mlx_window = mlx_new_window(fractol->mlx_connection, WIDTH, HEIGHT,
			fractol->name);
	if (fractol->mlx_window == NULL)
	{
		mlx_destroy_image(fractol->mlx_connection, fractol->image.image_ptr);
		free(fractol->mlx_connection);
		malloc_error();
	}
	fractol->image.image_ptr = mlx_new_image(fractol->mlx_connection,
			WIDTH, HEIGHT);
	if (fractol->image.image_ptr == NULL)
	{
		mlx_destroy_image(fractol->mlx_connection, fractol->image.image_ptr);
		free(fractol->mlx_connection);
		malloc_error();
	}
	fractol->image.pixels_ptr = mlx_get_data_addr(fractol->image.image_ptr,
			&fractol->image.bitspp, &fractol->image.line_len,
			&fractol->image.endian);
	events_init(fractol);
	data_init(fractol);
}
