/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coord.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tberthie <tberthie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/09 15:10:42 by tberthie          #+#    #+#             */
/*   Updated: 2017/01/09 18:05:08 by tberthie         ###   ########.fr       */
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
		g_fdf->x[i] = (i % g_fdf->width - i /
		g_fdf->width) * SIZE;
		g_fdf->y[i] = (i % g_fdf->width + i /
		g_fdf->width) * SIZE - g_fdf->height[i];
		i++;
	}
	return (1);
}
