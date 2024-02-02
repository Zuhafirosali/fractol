/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zfiros-a <zfiros-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 11:13:29 by zfiros-a          #+#    #+#             */
/*   Updated: 2024/02/01 15:24:29 by zfiros-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

double	map(double u_num, t_mappingrange range)
{
	return ((u_num - range.o_min) * (range.n_max - range.n_min) / (range.o_max
			- range.o_min) + range.n_min);
}

t_cmplex	sum_complex(t_cmplex z1, t_cmplex z2)
{
	t_cmplex	result;

	result.x = z1.x + z2.x;
	result.y = z1.y + z2.y;
	return (result);
}

t_cmplex	square_complex(t_cmplex z)
{
	t_cmplex	result;

	result.x = (z.x * z.x) - (z.y * z.y);
	result.y = 2 * z.x * z.y;
	return (result);
}
