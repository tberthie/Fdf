/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tberthie <tberthie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/13 12:57:02 by tberthie          #+#    #+#             */
/*   Updated: 2016/12/16 17:52:51 by tberthie         ###   ########.fr       */
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
	if (!(fdf = setup(av[1])))
		return (0);
//	display(fdf);
	return (0);
}
