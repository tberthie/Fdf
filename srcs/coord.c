/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coord.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tberthie <tberthie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/09 15:10:42 by tberthie          #+#    #+#             */
/*   Updated: 2017/01/09 19:30:21 by tberthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

#include <stdlib.h>
#include <math.h>

int				coord(t_fdf *fdf)
{
	int		i;

	i = 0;
	if (!(fdf->x = malloc(sizeof(int) * fdf->size)) ||
	!(fdf->y = malloc(sizeof(int) * fdf->size)))
		return (err_ret("an error has occured", 0));
	while (i < fdf->size)
	{
		fdf->x[i] = (i % fdf->width - i / fdf->width) * fdf->factor +
		(0.025 * SIZE) + (fdf->size / fdf->width - 1) * fdf->factor;
		fdf->y[i] = (i % fdf->width + i / fdf->width) *
		fdf->factor + (0.025 * SIZE);
		i++;
	}
	return (1);
}
