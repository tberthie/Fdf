/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tberthie <tberthie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/09 13:18:22 by tberthie          #+#    #+#             */
/*   Updated: 2017/01/09 14:03:06 by tberthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fdf.h"

#include <mlx.h>

int			bind(int keycode, void *param)
{
	param = 0;
	if (keycode == 53)
		exit(1);
	return (1);
}

void		run(void)
{
	draw();
	if ((g_fdf->mlx = mlx_init()) &&
	(g_fdf->win = mlx_new_window(g_fdf->mlx, 1920, 1080, "hi")))
	{
		mlx_key_hook(g_fdf->win, bind, 0);
		mlx_loop(g_fdf->mlx);
	}
	else
		write(2, "fdf: an error occured\n", 22);
}
