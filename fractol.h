/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdeclerc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/30 13:01:49 by fdeclerc          #+#    #+#             */
/*   Updated: 2017/02/02 12:16:11 by fdeclerc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <stdio.h>
# include <stdlib.h>
# include <math.h>
# include <mlx.h>
# include "libft/libft.h"
# define BUFF_SIZE 42
# define RED "\033[39;31m"
# define GREEN "\033[39;32m"
# define YELLOW "\033[39;33m"
# define BLUE "\033[39;34m"
# define MAGENTA "\033[39;35m"
# define CYAN "\033[39;36m"
# define WHITE "\033[39;37m"
# define BOLD_RED "\033[1;31m"
# define UNDERLINE_RED "\033[4;31m"
# define BLINK_RED "\033[5;31m"
# define ENDOF "\033[0m"
# define COLOR(c, s) triple_put(c, s, ENDOF)

typedef struct		s_data
{
	void			*mlx;
	void			*win;
	void			*img;
	int				menu;
	int				stop;
	int				zoom;
	int				iter;
	int				row;
	int				backg;
	double			move_x;
	double			move_y;
	double			cre;
	double			cim;
	double			new_re;
	double			new_im;
	double			old_re;
	double			old_im;
	double			pr;
	double			pi;
	double			x1;
	double			x2;
	double			y1;
	double			y2;
	unsigned char	r;
	unsigned char	g;
	unsigned char	b;
	unsigned long	color;
}					t_data;

typedef struct		s_coord
{
	double			x;
	double			y;
}					t_coord;

static void			ft_init(t_data *e);
static void			ft_launch(t_data *e);
int					ft_choice_fractol(void);
void				ft_img_pixel(unsigned long color, t_data *e, int x, int y);
int					ft_expose(int x, int y, t_data *e);
void				ft_zoom_in(t_data *e, double x_tall, double y_tall, t_coord pos)
void				ft_zoom_out(t_data *e, double x_tall, double y_tall);
int					ft_mouse(int button, int x, int y, t_data *e);
int					ft_key_color(int keycode, t_data *e);
int					ft_key_fractol(int keycode, t_data *e);
int					ft_key_status(int keycode, t_data *e);
void				ft_draw(t_data *e);
void				ft_init_coord(t_data *e);
void				ft_geometric(t_data *e, int x, int y, int i);
void				ft_julia(t_data *e);
void				ft_draw_m(t_data *e);
void				ft_init_coord_m(t_data *e);
void				ft_geometric_m(t_data *e, int x, int y, int i);
void				ft_mandelbrot(t_data *e);
void				ft_draw_b(t_data *e);
void				ft_init_coord_b(t_data *e);
void				ft_geometric_b(t_data *e, int x, int y, int i);
void				ft_burn(t_data *e);

#endif
