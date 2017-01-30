/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdeclerc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/30 13:01:49 by fdeclerc          #+#    #+#             */
/*   Updated: 2017/01/30 16:03:35 by fdeclerc         ###   ########.fr       */
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
	int				fond;
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

#endif
