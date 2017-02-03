/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdeclerc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/30 15:02:32 by fdeclerc          #+#    #+#             */
/*   Updated: 2017/02/03 11:19:18 by fdeclerc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void		ft_init(t_data *e)
{
	e->mlx = mlx_init();
	e->win = mlx_new_window(e->mlx, 1000, 650, "Fract'ol");
	e->img = mlx_new_image(e->mlx, 1000, 650);
	e->zoom = 1;
	e->stop = 0;
	e->row = 0;
	e->move_x = 0.0;
	e->move_y = 0.0;
	e->cre = -0.7;
	e->cim = 0.27015;
	e->iter = 50;
	e->x1 = -3;
	e->x2 = -3 + 6 * 1000 / 650;
	e->y1 = -3;
	e->y2 = 3;
}

static void		ft_launch(t_data *e)
{
	ft_init(e);
	if (e->menu == 1)
		ft_julia(e);
	if (e->menu == 2)
		ft_mandelbrot(e);
	if (e->menu == 3)
		ft_burn(e);
	mlx_put_image_to_window(e->mlx, e->win, e->img, 0, 0);
	mlx_key_hook(e->win, ft_key_status, e);
	mlx_mouse_hook(e->win, ft_mouse, e);
	mlx_hook(e->win, 6, (1L << 6), ft_expose, e);
	mlx_loop(e->mlx);
}

int				ft_choice_fractol(void)
{
	char *buff;

	buff = malloc(sizeof(char) * BUFF_SIZE);
	if (buff == NULL)
		return (0);
	while ((read(0, buff, BUFF_SIZE)) > 0)
	{
		if (buff[0] == '1' && buff[1] == '\n')
			return (1);
		else if (buff[0] == '2' && buff[1] == '\n')
			return (2);
		else if (buff[0] == '3' && buff[1] == '\n')
			return (3);
		else if (buff[0] == '4' && buff[1] == '\n')
			return (4);
		else if ((buff[0] != 1 && buff[0] != 2) || buff[1] != '\n')
		{
			ft_putstr(RED);
			ft_putstr("Entrez un chiffre valide");
			ft_putstr(ENDOF);
			return (0);
		}
	}
	return (0);
}

int				main(void)
{
	t_data *e;

	e = malloc(sizeof(t_data));
	e->menu = 0;
	ft_putstr(GREEN);
	ft_putendl("Bienvenue sur Fract'ol:");
	ft_putstr(CYAN);
	ft_putstr("1. Julia\n2. Mandelbrot\n3. Burning ship\n");
	ft_putstr(ENDOF);
	while (e->menu != 1 && e->menu != 2 && e->menu != 3)
	{
		e->menu = ft_choice_fractol();
		if (e->menu == 2 || e->menu == 1 || e->menu == 3)
			ft_launch(e);
		return (0);
	}
	return (0);
}
