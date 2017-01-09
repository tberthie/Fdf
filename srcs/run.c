/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tberthie <tberthie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/09 13:18:22 by tberthie          #+#    #+#             */
/*   Updated: 2017/01/09 18:23:27 by tberthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fdf.h"

#include <mlx.h>

int			bind(int keycode, void *param)
{
	param = 0;
/*	if (keycode == 13)
		g_fdf->py -= 10;
	else if (keycode == 0)
		g_fdf->px -= 10;
	else if (keycode == 1)
		g_fdf->py += 10;
	else if (keycode == 2)
		g_fdf->px += 10;
*/	if (keycode == 53)
		exit(1);
	return (1);
}

int			expose(void *param)
{
	param = 0;
	draw();
	return (1);
}

void		run(void)
{
	int		wins;

	wins = ((g_fdf->size / g_fdf->width - 1) +
	g_fdf->width - 1) * g_fdf->factor + 0.05 * SIZE;
	if ((g_fdf->mlx = mlx_init()) &&
	(g_fdf->win = mlx_new_window(g_fdf->mlx, wins, wins, "hi")))
	{
		draw();
		mlx_key_hook(g_fdf->win, bind, 0);
		mlx_expose_hook(g_fdf->win, expose, 0);
		mlx_loop(g_fdf->mlx);
	}
	else
		write(2, "fdf: an error occured\n", 22);
}
