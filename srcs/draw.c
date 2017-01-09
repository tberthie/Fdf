/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tberthie <tberthie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/09 14:02:28 by tberthie          #+#    #+#             */
/*   Updated: 2017/01/09 18:35:01 by tberthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

#include <mlx.h>
#include <math.h>

// HEX 0xRRGGBB0

void		line(t_fdf *fdf, int i, int diff)
{
	int			j;
	float		dx;
	float		dy;
	float		ds;

	j = 0;
	dx = fdf->x[i] - fdf->x[i - diff];
	dy = fdf->y[i] - fdf->y[i - diff];
	ds = sqrt(pow(dx, 2) + pow(dy, 2));
	while (j <= ds)
	{
		mlx_pixel_put(fdf->mlx, fdf->win,
		fdf->x[i - diff] + dx * (j / ds),
		fdf->y[i - diff] + dy * (j / ds),
		0xffffff0);
		j++;
	}
}

void		draw(t_fdf *fdf)
{
	int		i;

	i = 0;
	mlx_clear_window(fdf->mlx, fdf->win);
	while (i < fdf->size)
	{
		if (i % fdf->width)
			line(fdf, i, 1);
		if (i >= fdf->width)
			line(fdf, i, fdf->width);
		i++;
	}
}
