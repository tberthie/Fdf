/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tberthie <tberthie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/13 13:49:09 by tberthie          #+#    #+#             */
/*   Updated: 2017/01/09 19:35:35 by tberthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# define SIZE	400

# define TOP	0xff00000
# define MID	0x00ff000
# define BOTTOM	0x0000ff0

typedef struct		s_fdf
{
	int		*height;
	int		*x;
	int		*y;

	int		width;
	int		size;
	int		factor;

	float	zoom;
	float	depth;
	int		posx;
	int		posy;

	int		colors[3];
	int		top;
	int		bottom;

	void	*mlx;
	void	*win;
}					t_fdf;

t_fdf				*setup(char *str);
void				run(t_fdf *fdf);
void				draw(t_fdf *fdf);
int					coord(t_fdf *fdf);

int					err_ret(char *str, int ret);

#endif
