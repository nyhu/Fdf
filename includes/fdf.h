#ifndef FDF_H
# define FDF_H

# include <mlx.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <stdio.h>
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
	int			color;
}				t_dot;

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
}				t_fdf;

char	*ft_parse_file(char	*file, t_fdf *f);
void	ft_free_fdf(t_fdf *f);
int		ft_win_fill(t_fdf *f);

#endif
