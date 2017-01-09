/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tberthie <tberthie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/13 12:57:02 by tberthie          #+#    #+#             */
/*   Updated: 2017/01/09 18:31:50 by tberthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

#include <unistd.h>

int				main(int ac, char **av)
{
	t_fdf	*fdf;

	ac != 2 ? write(2, "usage: fdf file\n", 16) : 0;
	if (ac != 2)
		return (0);
	if (!(fdf = setup(av[1])) || !coord(fdf))
		return (0);
	run(fdf);
	return (0);
}
