/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tberthie <tberthie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/09 14:02:28 by tberthie          #+#    #+#             */
/*   Updated: 2017/01/09 20:26:35 by tberthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fdf.h"

#include <mlx.h>
#include <math.h>

int			gradient(int from, int to, float ratio)
{
	int				color;

	color = 0;
	color |= (int)((unsigned char)(from >> 16) +
	((unsigned char)(to >> 16) - (unsigned char)(from >> 16)) * ratio) << 16;
	color |= (int)((unsigned char)(from >> 8) +
	((unsigned char)(to >> 8) - (unsigned char)(from >> 8)) * ratio) << 8;
	color |= (int)((unsigned char)(from) +
	((unsigned char)(to) - (unsigned char)(from)) * ratio);
	return (color);
}

int			getcolor(t_fdf *fdf, float height)
{
	if (fdf->depth > 0)
	{
		if (height > 0 && fdf->top)
			return (gradient(fdf->colors[1], fdf->colors[0], height /
			(fdf->top * fdf->depth)));
		if (height < 0 && fdf->bottom)
			return (gradient(fdf->colors[1], fdf->colors[2], height /
			(fdf->bottom * fdf->depth)));
	}
	else if (fdf->depth < 0)
	{
		if (height > 0 && fdf->bottom)
			return (gradient(fdf->colors[1], fdf->colors[0], height /
			(fdf->bottom * fdf->depth)));
		if (height < 0 && fdf->top)
			return (gradient(fdf->colors[1], fdf->colors[2], height /
			(fdf->top * fdf->depth)));
	}
	return (fdf->colors[1]);
}

void		line(t_fdf *fdf, int i, int diff)
{
	int			j;
	float		dx;
	float		dy;
	float		ds;
	float		diffy;

	j = 0;
	dx = fdf->x[i] - fdf->x[i - diff];
	diffy = fdf->y[i - diff] - fdf->height[i - diff] *
	(0.1 * fdf->factor * fdf->depth);
	dy = (fdf->y[i] - fdf->height[i] * (0.1 * fdf->factor *
	fdf->depth)) - diffy;
	ds = sqrt(pow(dx, 2) + pow(dy, 2));
	while (j <= ds)
	{
		mlx_pixel_put(fdf->mlx, fdf->win,
		(fdf->x[i - diff] + dx * (j / ds)) * fdf->zoom + fdf->posx,
		(diffy + dy * (j / ds)) * fdf->zoom + fdf->posy,
		getcolor(fdf, (fdf->height[i - diff] + (fdf->height[i] -
		fdf->height[i - diff]) * (j / ds)) * fdf->depth));
		j++;
	}
}

void		draw(t_fdf *fdf)
{
	int		i;

	i = 0;
	mlx_clear_window(fdf->mlx, fdf->win);
	mlx_string_put(fdf->mlx, fdf->win, 0, 0, 0xffffff0, "ZOOM");
	mlx_string_put(fdf->mlx, fdf->win, 45, 0, 0x00ff000,
	ft_itoa(fdf->zoom * 100));
	mlx_string_put(fdf->mlx, fdf->win, 0, 20, 0xffffff0, "DEPTH");
	mlx_string_put(fdf->mlx, fdf->win, 55, 20, 0x00ff000,
	ft_itoa(fdf->depth * 100));
	while (i < fdf->size)
	{
		if (i % fdf->width)
			line(fdf, i, 1);
		if (i >= fdf->width)
			line(fdf, i, fdf->width);
		i++;
	}
}
