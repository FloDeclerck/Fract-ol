/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdeclerc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/30 15:39:49 by fdeclerc          #+#    #+#             */
/*   Updated: 2017/02/01 16:14:17 by fdeclerc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_draw(t_data *e)
{
	e->old_re = e->new_re;
	e->old_im = e->new_im;
	e->new_re = e->old_re * e->old_re - e->old_im * e->old_im + e->cre;
	e->new_im = 2 * e->old_re * e->old_im + e->cim;
}

void	ft_init_coord(t_data *e)
{
	e->old_re = e->new_re;
	e->old_im = e->new_im;
}

void	ft_geometric(t_data *e, int x, int y, int i)
{
	e->color = (i % 256 * (i < e->iter));
	if (e->row == 0)
		ft_img_pixel(mlx_get_color_value(e->mlx, 0x00FFF999 * e->color),
				e, x, y);
	if (e->row == 1)
		ft_img_pixel(mlx_get_color_value(e->mlx, 0x00CC33F * e->color),
				e, x, y);
	if (e->row == 2)
		ft_img_pixel(mlx_get_color_value(e->mlx, 0x006600CC * e->color),
				e, x, y);
}

void	ft_julia(t_data *e)
{
	int i;
	int x;
	int y;

	x = 0;
	while (x < 1000)
	{
		y = 0;
		while (y < 650)
		{
			e->new_re = (double)x / (1000 / (e->x2 - e->x1)) + e->x1;
			e->new_im = (double)y / (650 / (e->y2 - e->y1)) + e->y1;
			ft_init_coord(e);
			i = -1;
			while (i++ < e->iter &&
					(e->new_re * e->new_re + e->new_im * e->new_im) < 4)
				ft_draw(e);
			ft_geometric(e, x, y, i);
			y++;
		}
		x++;
	}
}
