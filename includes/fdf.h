#ifndef FDF_H
# define FDF_H

# include <mlx.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <stdio.h>
# include <math.h>
# include "libft.h"
# define XK_BackSpace                     0xff08
# define XK_Tab                           0xff09
# define XK_Linefeed                      0xff0a
# define XK_Clear                         0xff0b
# define XK_Return                        0xff0d
# define XK_Pause                         0xff13
# define XK_Scroll_Lock                   0xff14
# define XK_Sys_Req                       0xff15
# define XK_Escape                        0xff1b
# define XK_Delete                        0xffff
# define XK_KP_Space                      0xff80
# define XK_KP_Tab                        0xff89
# define XK_KP_Enter                      0xff8d
# define XK_Home                          0xff50
# define XK_Left                          0xff51
# define XK_Up                            0xff52
# define XK_Right                         0xff53
# define XK_Down                          0xff54
# define XK_Prior                         0xff55
# define XK_Page_Up                       0xff55
# define XK_Next                          0xff56
# define XK_Page_Down                     0xff56
# define XK_End                           0xff57
# define XK_Begin                         0xff58

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
	short		exist;
	t_c			c;
	t_cd		p;
	t_cd		f;
	int			color;
}				t_dot;

typedef struct	s_conf
{
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
	int			bpp;
	int			ls;
	int			endian;
	char		*title;
	t_dot		**map;
	t_c			max;
	int			min;
	t_conf		cf;
}				t_fdf;

void	ft_zoom(t_fdf *f, char c);
void	ft_img_reset(t_fdf *f);
char	*ft_parse_file(char	*file, t_fdf *f);
int		ft_free_fdf(t_fdf *f);
int		ft_win_fill(t_fdf *f);
void	ft_run_dot(t_fdf *f, void (*ft)(t_fdf *f, t_dot *dot));
void	ft_put_pixel(t_fdf *f, int x, int y, int rgb);
int		ft_cf_reset(t_fdf *f);

#endif
