/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tberthie <tberthie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/09 13:18:22 by tberthie          #+#    #+#             */
/*   Updated: 2017/01/09 18:36:57 by tberthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fdf.h"

#include <mlx.h>

int			bind(int keycode, void *param)
{
	param = 0;
/*	if (keycode == 13)
		fdf->py -= 10;
	else if (keycode == 0)
		fdf->px -= 10;
	else if (keycode == 1)
		fdf->py += 10;
	else if (keycode == 2)
		fdf->px += 10;
*/	if (keycode == 53)
		exit(1);
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
