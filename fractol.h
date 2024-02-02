/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zfiros-a <zfiros-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 14:50:52 by zfiros-a          #+#    #+#             */
/*   Updated: 2024/02/02 17:16:27 by zfiros-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <stdio.h>
# include <unistd.h>
# include <math.h>
# include <stdlib.h>
# include "mlx/mlx.h"
# include "./mlx/mlx.h"

# define HEIGHT 800
# define WIDTH 800

# define BLACK 0x000000 
# define WHITE 0xFFFFFF 
# define RED 0xFF0000   // RGB(255, 0, 0)
# define GREEN 0x00FF00 // RGB(0, 255, 0)
# define BLUE 0x0000FF  // RGB(0, 0, 255)

// Psychedelic colors
# define MAGENTA_BURST 0xFF00FF      // A vibrant magenta
# define LIME_SHOCK 0xCCFF00         // A blinding lime
# define NEON_ORANGE 0xFF6600        // A blazing neon orange
# define PSYCHEDELIC_PURPLE 0x660066 // A deep purple
# define AQUA_DREAM 0x33CCCC         // A bright turquoise
# define HOT_PINK 0xFF66B2           // As the name suggests!
# define ELECTRIC_BLUE 0x0066FF      // A radiant blue
# define LAVA_RED 0xFF3300           // A bright, molten red
# define NUDE_PINK 0xF2DADF

typedef struct s_cmplex
{
	double	x;
	double	y;
}			t_cmplex;

typedef struct s_image
{
	void	*image_ptr;
	char	*pixels_ptr;
	int		bitspp;
	int		endian;
	int		line_len;
}			t_image;

typedef struct s_fractal
{
	char		*name;
	void		*mlx_connection;
	void		*mlx_window;
	t_image		image;
	double		escape_value;
	int			iterations_definition;
	double		shift_x;
	double		shift_y;
	double		zoom;
	double		julia_x;
	double		julia_y;
	int			lock;
}				t_fractal;

typedef struct s_mappingrange
{
	double		n_min;
	double		n_max;
	double		o_min;
	double		o_max;
}				t_mappingrange;

int			ft_strlen(char *str);
int			ft_strncmp(const char *s1, const char *s2, size_t n);
void		ft_putstr_fd(char *s, int fd);
void		fractol_init(t_fractal *fractol);
void		malloc_error(void);
double		map(double uns_num, t_mappingrange range);
t_cmplex	sum_complex(t_cmplex z1, t_cmplex z2);
t_cmplex	square_complex(t_cmplex z);
void		handle_pixel(int x, int y, t_fractal *fractol);
void		fractal_render(t_fractal *fractol);
void		my_pixel_put(int x, int y, t_image *image, int color);
int			get_color(t_cmplex z, t_cmplex c, t_fractal *fractol);
t_cmplex	get_coordinates(int x, int y, t_fractal *fractol);
void		mandel_or_julia(t_cmplex *z, t_cmplex *c, t_fractal *fractol);

int			close_handle(t_fractal *fractol);
int			key_handle(int key, t_fractal *fractol);
void		left_right(t_fractal *fractol, int key);
void		up_down(t_fractal *fractol, int key);
int			mouse_handle(int key, int x, int y, t_fractal *fractol);

int			check_julia_param(t_fractal *fractol, char **av);
int			julia_param_valid(char *param);
double		ft_atod(char *s);
int			ft_isdigit(int c);
int			julia_map(int x, int y, t_fractal *fractol);

#endif