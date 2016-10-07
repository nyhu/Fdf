/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tboos <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/04 16:46:26 by tboos             #+#    #+#             */
/*   Updated: 2016/10/04 16:54:42 by tboos            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <mlx.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <stdio.h>
# include <math.h>
# include "libft.h"
# ifdef LINUX
#  include "key_linux.h"
# else
#  include "key_mac.h"
# endif
# define WIN_L                            1820
# define WIN_H                            980
# define COLOR_N 00000001
# define COLOR_B 00000002
# define COLOR_V 00000004
# define COLOR_M 00000007
# define PROJ_I  00000010
# define PROJ_O  00000020
# define PROJ_P  00000040
# define PROJ_M  00000070
# define FACE_H  00000100
# define FACE_G  00000200
# define FACE_F  00000400
# define FACE_M  00000700
# define LOOP    00001000

typedef struct	s_cd
{
	double		x;
	double		y;
	double		z;
}				t_cd;

typedef struct	s_c
{
	int			x;
	int			y;
	int			z;
}				t_c;

typedef struct	s_dot
{
	char		exist;
	t_c			c;
	t_cd		p;
	t_cd		f;
	int			color;
}				t_dot;

typedef struct	s_conf
{
	int			mode;
	t_cd		margin;
	t_cd		space;
}				t_conf;

typedef struct	s_fdf
{
	void		*mlx;
	void		*win;
	t_c			s_win;
	void		*img;
	char		*addr;
	double		angle;
	int			bpp;
	int			ls;
	int			endian;
	char		*title;
	t_dot		**map;
	t_c			max;
	int			min;
	t_conf		cf;
}				t_fdf;

int				ft_put_img_to_win(t_fdf *f);
void			ft_print_line(t_fdf *f, t_dot *d1, t_dot *d2, int color);
int				ft_color(t_fdf *f, double z);
void			ft_dot_place_dimetric(t_fdf *f, t_dot *d);
void			ft_dot_place_isometric(t_fdf *f, t_dot *d);
void			ft_dot_place_pers(t_fdf *f, t_dot *d);
void			ft_rotate(t_fdf *f, char c);
void			ft_config(t_fdf *f, int c);
void			ft_img_reset(t_fdf *f);
char			*ft_parse_file(char	*file, t_fdf *f);
int				ft_free_fdf(t_fdf *f);
int				ft_win_fill(t_fdf *f);
void			ft_run_dot(t_fdf *f, void (*ft)(t_fdf *f, t_dot *dot));
void			ft_put_pixel(t_fdf *f, int x, int y, int rgb);
int				ft_cf_reset(t_fdf *f);

#endif
