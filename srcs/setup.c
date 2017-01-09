/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tberthie <tberthie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/13 15:19:22 by tberthie          #+#    #+#             */
/*   Updated: 2017/01/09 18:32:59 by tberthie         ###   ########.fr       */
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

int				newline(t_fdf *fdf, char *line)
{
	char	**tab;
	int		alt;

	if (!(tab = ft_strsplit(line, ' ')) || ft_tablen(tab) == 0 ||
	(fdf->width != 0 && ft_tablen(tab) != fdf->width))
		return (0);
	fdf->width == 0 ? fdf->width = ft_tablen(tab) : 0;
	while (*tab)
	{
		if (!getnbr(&alt, *tab++) ||
		!(fdf->height = insert(alt, fdf->height, fdf->size)))
			return (0);
		fdf->size++;
	}
	return (1);
}

t_fdf			*setup(char *str)
{
	t_fdf	*fdf;
	int		fd;
	char	*line;

	if ((fd = open(str, O_RDONLY)) == -1 ||
	!(fdf = malloc(sizeof(t_fdf))))
	{
		err_ret(str, 0);
		return (0);
	}
	fdf->width = 0;
	fdf->size = 0;
	fdf->height = 0;
	while (ft_gnl(fd, &line))
	{
		if (!newline(fdf, line))
		{
			write(2, "fdf: map invalid\n", 17);
			return (0);
		}
		free(line);
	}
	fdf->factor = SIZE / (fdf->size / fdf->width);
	!fdf->size ? write(2, "fdf: map invalid\n", 17) : 0;
	return (fdf->size) ? fdf : 0;
}
