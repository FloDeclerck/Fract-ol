/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdeclerc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/01 11:12:12 by fdeclerc          #+#    #+#             */
/*   Updated: 2017/02/01 16:30:22 by fdeclerc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		ft_key_color(int keycode, t_data *e)
{
	mlx_destroy_image(e->mlx, e->img);
	mlx_clear_window(e->mlx, e->win);
	e->img = mlx_new_image(e->mlx, 1000, 650);
	if (keycode == 19 && e->row < 3)
		e->row += 1;
	if (keycode == 18 && e->row > 0)
		e->row -= 1;
	if (e->menu == 1)
		ft_julia(e);
	if (e->menu == 2)
		ft_mandelbrot(e);
	if (e->menu == 3)
		ft_burn(e);
	mlx_put_image_to_window(e->mlx, e->win, e->img, 0, 0);
	if (keycode == 53)
		exit(0);
	return (0);
}

int		ft_key_fractol(int keycode, t_data *e)
{
	if (keycode == 69)
		e->iter += 4;
	return (ft_key_color(keycode, e));
}

int		ft_key_status(int keycode, t_data *e)
{
	if (keycode == 49)
		e->stop = 1;
	if (keycode == 258)
		e->stop = 0;
	if (keycode == 78)
		e->iter -= 4;
	return (ft_key_fractol(keycode, e));
}
