/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tberthie <tberthie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/13 13:49:09 by tberthie          #+#    #+#             */
/*   Updated: 2017/01/09 18:37:25 by tberthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# define SIZE	400

typedef struct		s_fdf
{
	int		*height;
	int		*x;
	int		*y;

	int		width;
	int		size;

	int		factor;

	void	*mlx;
	void	*win;
}					t_fdf;

t_fdf				*setup(char *str);
void				run(t_fdf *fdf);
void				draw(t_fdf *fdf);
int					coord(t_fdf *fdf);

int					err_ret(char *str, int ret);

#endif
