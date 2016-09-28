#ifndef FDF_H
# define FDF_H

# include <mlx.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <stdio.h>
# include <math.h>
# include "libft.h"

typedef struct	s_c
{
	int			x;
	int			y;
	int			z;
}				t_c;

typedef struct	s_dot
{
	t_c			c;
	t_c			p;
	int			color;
}				t_dot;

typedef struct	s_conf
{
	t_c			margin;
	t_c			space;
}				t_conf;

typedef struct	s_fdf
{
	void		*mlx;
	void		*win;
	t_c			s_win;
	void		*img;
	char		*addr;
	int			bpp;
	int			ls;
	int			endian;
	char		*title;
	t_dot		**map;
	t_c			max;
	int			min;
	t_conf		cf;
}				t_fdf;

char	*ft_parse_file(char	*file, t_fdf *f);
void	ft_free_fdf(t_fdf *f);
int		ft_win_fill(t_fdf *f);
void	ft_run_dot(t_fdf *f, void (*ft)(t_fdf *f, t_dot *dot));
void	ft_put_pixel(t_fdf *f, int x, int y, int rgb);
int		ft_cf_reset(t_fdf *f);

#endif
