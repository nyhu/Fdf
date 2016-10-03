#include "fdf.h"

void		ft_rotate(t_fdf *f, char c)
{
	if (c == '+')
		f->angle += 0.05;
	if (c == '-')
		f->angle -= 0.05;
}

static void	ft_config_next_next(t_fdf *f, int c)
{
	if (c == XK_H)
		f->cf.mode = f->cf.mode - (f->cf.mode & FACE_M) + FACE_H;
	else if (c == XK_G)
		f->cf.mode = f->cf.mode - (f->cf.mode & FACE_M) + FACE_G;
	else if (c == XK_F)
		f->cf.mode = f->cf.mode - (f->cf.mode & FACE_M) + FACE_F;
	else if (c == XK_L)
		f->cf.mode = f->cf.mode ^ LOOP;

}

static void	ft_config_next(t_fdf *f, int c)
{
	if (c == XK_A)
		f->cf.margin.x *= 1.1;
	else if (c == XK_Q)
		f->cf.margin.x /= 1.1;
	else if (c == XK_I)
		f->cf.mode = f->cf.mode - (f->cf.mode & PROJ_M) + PROJ_I;
	else if (c == XK_P)
	{
		f->cf.mode = f->cf.mode - (f->cf.mode & PROJ_M) + PROJ_P;
		f->angle = 0;
	}
	else if (c == XK_O)
	{
		f->cf.mode = f->cf.mode - (f->cf.mode & PROJ_M) + PROJ_O;
		f->angle = atan(0.5);
	}
	else if (c == XK_N)
		f->cf.mode = f->cf.mode - (f->cf.mode & COLOR_M) + COLOR_N;
	else if (c == XK_B)
		f->cf.mode = f->cf.mode - (f->cf.mode & COLOR_M) + COLOR_B;
	else if (c == XK_V)
		f->cf.mode = f->cf.mode - (f->cf.mode & COLOR_M) + COLOR_V;
	else
		ft_config_next_next(f, c);
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
	else if (c == XK_Z)
		f->cf.space.z *= 1.1;
	else if (c == XK_S)
		f->cf.space.z /= 1.1;
	else if (c == XK_E)
		f->cf.margin.y /= 1.1;
	else if (c == XK_D)
		f->cf.margin.y *= 1.1;
	else
		ft_config_next(f, c);
}

int			ft_cf_reset(t_fdf *f)
{
	int		test;

	test = f->max.z - f->min;
	f->cf.mode = COLOR_V | PROJ_O | FACE_H;
	f->s_win.x = WIN_L;
	f->s_win.y = WIN_H;
	f->angle = atan(0.5);
	f->cf.margin.x = f->s_win.x / 2;
	f->cf.margin.y = f->s_win.y / 2;
	f->cf.space.x = pow(f->s_win.x / (f->max.x ? f->max.x : 1), 2);
	f->cf.space.x += pow(f->s_win.y / (f->max.y ? f->max.y : 1), 1.25);
	f->cf.space.x += pow(f->s_win.y / (test ? test : 1), 1.25);
	f->cf.space.x = sqrt(f->cf.space.x) / 3.5;
	f->cf.space.y = f->cf.space.x;
	f->cf.space.z = f->cf.space.y / 2;
	return (1);
}
