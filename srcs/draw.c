/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tberthie <tberthie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/09 14:02:28 by tberthie          #+#    #+#             */
/*   Updated: 2017/01/09 18:26:28 by tberthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

#include <mlx.h>
#include <math.h>

// HEX 0xRRGGBB0

void		line(int i, int diff)
{
	int			j;
	float		dx;
	float		dy;
	float		ds;

	j = 0;
	dx = g_fdf->x[i] - g_fdf->x[i - diff];
	dy = g_fdf->y[i] - g_fdf->y[i - diff];
	ds = sqrt(pow(dx, 2) + pow(dy, 2));
	while (j <= ds)
	{
		mlx_pixel_put(g_fdf->mlx, g_fdf->win,
		g_fdf->x[i - diff] + dx * (j / ds),
		g_fdf->y[i - diff] + dy * (j / ds),
		0xffffff0);
		j++;
	}
}

void		draw(void)
{
	int		i;

	i = 0;
	mlx_clear_window(g_fdf->mlx, g_fdf->win);
	while (i < g_fdf->size)
	{
		if (i % g_fdf->width)
			line(i, 1);
		if (i >= g_fdf->width)
			line(i, g_fdf->width);
		i++;
	}
}
