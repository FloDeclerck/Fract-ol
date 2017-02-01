/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdeclerc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/01 11:37:28 by fdeclerc          #+#    #+#             */
/*   Updated: 2017/02/01 13:29:22 by fdeclerc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		ft_expose(int x, int y, t_data *e)
{
	if (e->stop != 1 && e->menu == 1)
	{
		mlx_destroy_image(e->mlx, e->img);
		mlx_clear_window(e->mlx, e->win);
		e->img = mlx_new_image(e->mlx, 1000, 650);
		if (x < 1000 && x > 1)
			e->cre = (double)x / 1000;
		if (y < 1000 && y > 1)
			e->cim = (double)y / 1000;
		if (e->menu == 1)
			ft_julia(e);
		mlx_put_image_to_window(e->mlx, e->win, e->img, 0, 0);
	}
	return (0);
}

void	ft_zoom_in(t_data *e, double x_tall, double y_tall, t_coord pos)
{
	double tmp;

	if (e->iter < 300)
		e->iter += 4;
	tmp = e->x1;
	e->x1 = (pos.x + (e->x2 + e->x1) / 2) / 2 - (x_tall * 0.4);
	e->x2 = (pos.x + (e->x2 + tmp) / 2) / 2 + (x_tall * 0.4);
	tmp = e->y1;
	e->y1 = (pos.y + (e->y2 + e->y1) / 2) / 2 - (y_tall * 0.4);
	e->y2 = (pos.y + (e->y2 + tmp) / 2) / 2 - (y_tall * 0.4);
}

void	ft_zoom_out(t_data *e, double x_tall, double y_tall)
{
	e->x1 = e->x1 - (x_tall * 0.52);
	e->x2 = e->x2 - (x_tall * 0.52);
	e->y1 = e->y1 - (y_tall * 0.52);
	e->y2 = e->y2 - (y_tall * 0.52);
}

int			ft_mouse(int button, int x, int y, t_data *e)
{
	t_coord pos;
	double	x_tall;
	double	y_tall;

	x_tall = e->x2 - e->x1;
	y_tall = e->y2 - e->y1;
	pos.x = x / (1000 / (e->x2 - e->x1)) + e->x1;
	pos.y = y / (650 / (e->y2 - e->y1)) + e->y1;
	if (button == 5)
		ft_zoom_in(e, x_tall, y_tall, pos);
	mlx_destroy_image(e->mlx, e->img);
	mlx_clear_window(e->mlx, e->win);
	e->img = mlx_new_image(e->mlx, 1000, 650);
	if (e->menu == 1)
		ft_julia(e);
	if (e->menu == 2)
		ft_mandelbrot(e);
	if (e->menu == 3)
		ft_burn(e);
	mlx_put_image_to_window(e->mlx, e->win, e->img, 0, 0);
	return (0);
}
