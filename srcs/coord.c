/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coord.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tberthie <tberthie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/09 15:10:42 by tberthie          #+#    #+#             */
/*   Updated: 2017/01/09 18:24:42 by tberthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

#include <stdlib.h>
#include <math.h>

int				coord(void)
{
	int		i;

	i = 0;
	if (!(g_fdf->x = malloc(sizeof(int) * g_fdf->size)) ||
	!(g_fdf->y = malloc(sizeof(int) * g_fdf->size)))
		return (err_ret("an error has occured", 0));
	while (i < g_fdf->size)
	{
		g_fdf->x[i] = (i % g_fdf->width - i / g_fdf->width) * g_fdf->factor +
		(0.025 * SIZE) + (g_fdf->size / g_fdf->width - 1) * g_fdf->factor;
		g_fdf->y[i] = (i % g_fdf->width + i / g_fdf->width) * g_fdf->factor -
		g_fdf->height[i] * (0.1 * g_fdf->factor) + (0.025 * SIZE);
		i++;
	}
	return (1);
}
