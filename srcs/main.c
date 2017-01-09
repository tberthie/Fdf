/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tberthie <tberthie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/13 12:57:02 by tberthie          #+#    #+#             */
/*   Updated: 2017/01/09 13:53:16 by tberthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

#include <unistd.h>

int				main(int ac, char **av)
{
	ac != 2 ? write(2, "usage: fdf file\n", 16) : 0;
	if (ac != 2)
		return (0);
	if (!setup(av[1]))
		return (0);
	run();
	return (0);
}
