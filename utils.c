/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zfiros-a <zfiros-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 12:23:16 by zfiros-a          #+#    #+#             */
/*   Updated: 2024/02/02 17:16:34 by zfiros-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_putstr_fd(char *s, int fd)
{
	int	i;

	i = 0;
	if (!s)
		return ;
	while (s[i] != '\0')
	{
		write(fd, &s[i], 1);
		i++;
	}
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned int	i;
	unsigned char	*st1;
	unsigned char	*st2;

	i = 0;
	st1 = (unsigned char *)s1;
	st2 = (unsigned char *)s2;
	while ((st1[i] != '\0' || st2[i] != '\0') && (i < n))
	{
		if (st1[i] > st2[i])
			return (1);
		else if (st1[i] < st2[i])
			return (-1);
		i++;
	}
	return (0);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (c);
	else
		return (0);
}

double	ft_atod(char *s)
{
	long	integer;
	double	fraction;
	double	pow;
	int		sign;

	integer = 0;
	fraction = 0;
	pow = 1;
	sign = 1;
	while ((*s >= 9 && *s <= 13) || *s == 32)
		s++;
	while (*s == '+' || *s == '-')
		if (*s == '-')
			sign = -1;
	while (*s && *s != '.')
		integer = (integer * 10) + (*s++ - '0');
	if (*s == '.')
		++s;
	while (*s)
	{
		pow = pow / 10;
		fraction = fraction + (*s++ - '0') * pow;
	}
	return ((integer + fraction) * sign);
}
