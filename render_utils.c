/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zfiros-a <zfiros-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 14:58:51 by zfiros-a          #+#    #+#             */
/*   Updated: 2024/02/02 17:56:07 by zfiros-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	my_pixel_put(int x, int y, t_image *image, int color)
{
	int	offset;

	offset = (y * image->line_len) + (x * (image->bitspp / 8));
	*(unsigned int *)(image->pixels_ptr + offset) = color;
}

void	mandel_or_julia(t_cmplex *z, t_cmplex *c, t_fractal *fractol)
{
	if (!ft_strncmp(fractol->name, "julia", 5))
	{
		c->x = fractol->julia_x;
		c->y = fractol->julia_y;
	}
	if (!ft_strncmp(fractol->name, "mandelbrot", 10))
	{
		c->x = z->x;
		c->y = z->y;
	}
}

t_cmplex	get_coordinates(int x, int y, t_fractal *fractol)
{
	t_cmplex		z;
	t_mappingrange	rx;
	t_mappingrange	ry;

	rx.n_min = -2;
	rx.n_max = +2;
	rx.o_min = 0;
	rx.o_max = WIDTH;
	z.x = map(x, rx) * fractol->zoom + fractol->shift_x;
	ry.n_min = +2;
	ry.n_max = -2;
	ry.o_min = 0;
	ry.o_max = HEIGHT;
	z.y = map(y, ry) * fractol->zoom + fractol->shift_y;
	return (z);
}

int	get_color(t_cmplex z, t_cmplex c, t_fractal *fractol)
{
	int				i;
	t_mappingrange	range_color;

	i = 0;
	while (i < fractol->iterations_definition)
	{
		z = sum_complex(square_complex(z), c);
		if ((z.x * z.x) + (z.y * z.y) > fractol->escape_value)
		{
			range_color.n_min = LIME_SHOCK;
			range_color.n_max = BLACK;
			range_color.o_min = 0;
			range_color.o_max = fractol->iterations_definition;
			return (map(i, range_color));
		}
		++i;
	}
	return (LAVA_RED);
}

void	handle_pixel(int x, int y, t_fractal *fractol)
{
	int			color;
	t_cmplex	z;
	t_cmplex	c;

	z = get_coordinates(x, y, fractol);
	mandel_or_julia(&z, &c, fractol);
	color = get_color(z, c, fractol);
	my_pixel_put(x, y, &fractol->image, color);
}
