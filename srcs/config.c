#include "fdf.h"

void		ft_rotate(t_fdf *f, char c)
{
	if (c == '+')
		f->angle += 0.05;
	if (c == '-')
		f->angle -= 0.05;
}

static void	ft_config_next(t_fdf *f, int c)
{
	if (c == 'a')
		f->cf.margin.x *= 1.1;
	else if (c == 'q')
		f->cf.margin.x /= 1.1;
	else if (c == 'i')
		f->cf.mode = f->cf.mode - (f->cf.mode & PROJ_M) + PROJ_I;
	else if (c == 'p')
	{
		f->cf.mode = f->cf.mode - (f->cf.mode & PROJ_M) + PROJ_P;
		f->angle = 0;
	}
	else if (c == 'o')
	{
		f->cf.mode = f->cf.mode - (f->cf.mode & PROJ_M) + PROJ_O;
		f->angle = atan(0.5);
	}
}

void		ft_config(t_fdf *f, int c)
{
	if (c == XK_Up)
	{
		f->cf.space.x *= 1.1;
		f->cf.space.y *= 1.1;
		f->cf.space.z *= 1.1;
	}
	else if (c == XK_Down)
	{
		f->cf.space.x /= 1.1;
		f->cf.space.y /= 1.1;
		f->cf.space.z /= 1.1;
	}
	else if (c == 'z')
		f->cf.space.z *= 1.1;
	else if (c == 's')
		f->cf.space.z /= 1.1;
	else if (c == 'e')
		f->cf.margin.y /= 1.1;
	else if (c == 'd')
		f->cf.margin.y *= 1.1;
	else
		ft_config_next(f, c);
}

int			ft_cf_reset(t_fdf *f)
{
	int		test;

	test = f->max.z - f->min;
	f->cf.mode = COLOR_B | PROJ_O | FACE_H;
	f->s_win.x = WIN_L;
	f->s_win.y = WIN_H;
	f->angle = atan(0.5);
	f->cf.margin.x = f->s_win.x / 2;
	f->cf.margin.y = f->s_win.y / 2;
	f->cf.space.x = pow(f->s_win.x / f->max.x, 2);
	f->cf.space.x += pow(f->s_win.y / f->max.y, 1.25);
	f->cf.space.x += pow(f->s_win.y / test, 1.25);
	f->cf.space.x = sqrt(f->cf.space.x) / 3.5;
	f->cf.space.y = f->cf.space.x;
	f->cf.space.z = f->cf.space.y / 2;
	return (1);
}
