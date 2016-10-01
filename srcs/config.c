#include "fdf.h"

int	ft_cf_reset(t_fdf *f)
{
	int		test;

	f->s_win.x = WIN_L;
	f->s_win.y = WIN_H;
	f->cf.margin.x = f->s_win.x / 2;
	f->cf.margin.y = f->s_win.y / 2;
	f->cf.space.x = (f->s_win.x / f->max.x) / 2;
	f->cf.space.y = (f->s_win.y / f->max.y) / 2;
	test = f->max.z - f->min;
	if (test < f->max.y)
		f->cf.space.z = (test < 10 ? 2 : 1) * f->cf.space.y;
	else
		f->cf.space.z = f->cf.space.y / (test ? test : 1);
	return (1);
}
