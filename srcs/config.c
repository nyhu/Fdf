#include "fdf.h"

int	ft_cf_reset(t_fdf *f)
{
	f->s_win.x = 1000;
	f->s_win.y = 800;
	f->cf.margin.x = f->s_win.x / 4;
	f->cf.margin.y = f->s_win.y / 4;
	f->cf.space.x = (f->s_win.x / f->max.x) / 2;
	f->cf.space.y = (f->s_win.y / f->max.y) / 2;
	f->cf.space.z = (f->s_win.y / ((f->max.z - f->min) * 12));
	return (1);
}
