/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tberthie <tberthie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/09 13:18:22 by tberthie          #+#    #+#             */
/*   Updated: 2017/01/09 19:15:05 by tberthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fdf.h"

#include <mlx.h>

int			bind(int keycode, void *param)
{
	t_fdf	*fdf;

	fdf = param;
	if (keycode == 13 || keycode == 1)
		fdf->posy += keycode == 13 ? (SIZE * 0.1) : -(SIZE * 0.1);
	else if (keycode == 0 || keycode == 2)
		fdf->posx += keycode == 0 ? (SIZE * 0.1) : -(SIZE * 0.1);
	else if (keycode == 69 || keycode == 78)
		fdf->zoom += keycode == 69 ? 0.1 : -0.1;
	else if (keycode == 24 || keycode == 27)
		fdf->depth += keycode == 24 ? 0.1 : -0.1;
	else if (keycode == 53)
		exit(1);
	else
		return (1);
	draw(fdf);
	return (1);
}

int			expose(void *param)
{
	draw(param);
	return (1);
}

void		run(t_fdf *fdf)
{
	int		wins;

	wins = ((fdf->size / fdf->width - 1) +
	fdf->width - 1) * fdf->factor + 0.05 * SIZE;
	if ((fdf->mlx = mlx_init()) &&
	(fdf->win = mlx_new_window(fdf->mlx, wins, wins, "hi")))
	{
		draw(fdf);
		mlx_key_hook(fdf->win, bind, fdf);
		mlx_expose_hook(fdf->win, expose, fdf);
		mlx_loop(fdf->mlx);
	}
	else
		write(2, "fdf: an error occured\n", 22);
}
