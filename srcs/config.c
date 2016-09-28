#include "fdf.h"

int	ft_cf_reset(t_fdf *f)
{
	f->cf.margin.x = 75;
	f->cf.margin.y = 75;
	f->s_win.x = 50 * (f->max.x + f->max.y);
	f->s_win.y = 40 * (f->max.x + f->max.y);
	f->cf.space.x = (f->s_win.x - f->margin.y)
	f->cf.space.x /= (2 * (f->max.x + f->max.y));
	f->cf.space.y = (f->s_win.y - f->margin.y)
	f->cf.space.y /= (2 * (f->max.x + f->max.y));
	f->cf.space.z = f->cf.space.y;
	f->cent.x = f->s_win.x / 2;
	f->cent.y = (f->s_win.y / 2) - ((f->max.z - f->min) * f->cf.space.z);
	f->moy.x = f->max.x / 2;
	f->moy.y = f->max.y / 2;
	f->moy.z = (f->max.z + f->min) / 2;
	return (1);
}
