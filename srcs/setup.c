/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tberthie <tberthie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/13 15:19:22 by tberthie          #+#    #+#             */
/*   Updated: 2016/12/16 17:55:39 by tberthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fdf.h"

#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

int				newline(t_fdf *fdf, char *line)
{

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
	fdf->sy = 0;
	fdf->sx = 0;
	while (ft_gnl(fd, &line))
	{
		if (!newline(fdf, line))
		{
			write(2, "fdf: map invalid\n", 17);
			return (0);
		}
		fdf->sy++;
		free(line);
	}
	return (fdf);
}
