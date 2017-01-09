/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tberthie <tberthie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/13 15:19:22 by tberthie          #+#    #+#             */
/*   Updated: 2017/01/09 18:21:59 by tberthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fdf.h"

#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

int				*insert(int nb, int *tab, int size)
{
	int		*new;

	if (!(new = malloc(sizeof(int) * (size + 1))))
		return (0);
	new[size] = nb;
	while (size--)
		new[size] = tab[size];
	tab ? free(tab) : 0;
	return (new);
}

int				getnbr(int *ptr, char *str)
{
	int		nb;
	int		neg;

	nb = 0;
	neg = 1;
	if (*str == '-' && *(str + 1) && (neg = -1))
		str++;
	while (*str)
	{
		if (*str >= '0' && *str <= '9')
			nb = nb * 10 + *str - '0';
		else
			return (0);
		str++;
	}
	*ptr = nb * neg;
	return (1);
}

int				newline(char *line)
{
	char	**tab;
	int		alt;

	if (!(tab = ft_strsplit(line, ' ')) || ft_tablen(tab) == 0 ||
	(g_fdf->width != 0 && ft_tablen(tab) != g_fdf->width))
		return (0);
	g_fdf->width == 0 ? g_fdf->width = ft_tablen(tab) : 0;
	while (*tab)
	{
		if (!getnbr(&alt, *tab++) ||
		!(g_fdf->height = insert(alt, g_fdf->height, g_fdf->size)))
			return (0);
		g_fdf->size++;
	}
	return (1);
}

int				setup(char *str)
{
	int		fd;
	char	*line;

	if ((fd = open(str, O_RDONLY)) == -1 ||
	!(g_fdf = malloc(sizeof(t_fdf))))
	{
		err_ret(str, 0);
		return (0);
	}
	g_fdf->width = 0;
	g_fdf->size = 0;
	g_fdf->height = 0;
	while (ft_gnl(fd, &line))
	{
		if (!newline(line))
		{
			write(2, "fdf: map invalid\n", 17);
			return (0);
		}
		free(line);
	}
	g_fdf->factor = SIZE / (g_fdf->size / g_fdf->width);
	!g_fdf->size ? write(2, "fdf: map invalid\n", 17) : 0;
	return (g_fdf->size);
}
