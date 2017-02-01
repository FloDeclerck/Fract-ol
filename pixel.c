/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixel.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdeclerc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/01 15:01:29 by fdeclerc          #+#    #+#             */
/*   Updated: 2017/02/01 16:42:48 by fdeclerc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_img_pixel(unsigned long color, t_data *e, int x, int y)
{
	char	*pic;
	int		bit;
	int		size;
	int		end;

	pic = mlx_get_data_addr(e->img, &bit, &size, &end);
	e->r = ((color & 0xFF0000) >> 16);
	e->g = ((color & 0xFF00) >> 8);
	e->b = ((color & 0xFF));
	pic[x * bit / 8 + y * size] = e->b;
	pic[x * bit / 8 + 1 + y * size] = e->g;
	pic[x * bit / 8 + 2 + y * size] = e->r;
}
