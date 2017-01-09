/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tberthie <tberthie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/13 13:49:09 by tberthie          #+#    #+#             */
/*   Updated: 2017/01/09 18:02:51 by tberthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# define SIZE	10

typedef struct		s_fdf
{
	int		*height;
	int		*x;
	int		*y;

	int		width;
	int		size;

	void	*mlx;
	void	*win;
}					t_fdf;

t_fdf				*g_fdf;

int					setup(char *str);
void				run(void);
void				draw(void);
int					coord(void);

int					err_ret(char *str, int ret);

#endif
