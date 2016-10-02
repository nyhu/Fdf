#include "fdf.h"

void	ft_dot_place_pers(t_fdf *f, t_dot *d)
{
	int		test;

	test = f->max.z - f->min;
	d->p.x = (d->c.x - (f->max.x / 2)) * f->cf.space.x * 2;
	d->p.y = (-d->c.y - (f->max.y / 2)) * f->cf.space.y * 2;
	d->p.z = (d->c.z - (test / 2)) * f->cf.space.z;
	d->f.x = f->cf.margin.x + cos(f->angle) * d->p.x - sin(f->angle) * d->p.z;
	d->f.y = f->cf.margin.y / 2 + sin(f->angle) * d->p.x + cos(f->angle) * d->p.z;
	d->f.y -= sqrt((float)2 / 3) * d->p.y;
	d->f.z = 0x00FFFFFF * (test ? (float)((d->c.z - f->min)) / test : 1);
	d->f.z += (d->f.z > 0x00000044 ? 0 : 0x00000044);
}

void	ft_dot_place_isometric(t_fdf *f, t_dot *d)
{
	int		test;

	test = f->max.z - f->min;
	d->p.x = (d->c.x - (f->max.x / 2)) * f->cf.space.x;
	d->p.y = (d->c.y - (f->max.y / 2)) * f->cf.space.y;
	d->p.z = (d->c.z - (test / 2)) * f->cf.space.z;
	d->f.x = f->cf.margin.x + (sqrt(2) / 2) * (d->p.x - d->p.y);
	d->f.y = f->cf.margin.y + (1 / sqrt(6)) * (d->p.x + d->p.y);
	d->f.y -= sqrt((float)2 / 3) * d->p.z;
	d->f.z = 0x00FFFFFF * (test ? (float)((d->c.z - f->min)) / test : 1);
	d->f.z += (d->f.z > 0x00000044 ? 0 : 0x00000044);
}

void	ft_dot_place_dimetric(t_fdf *f, t_dot *d)
{
	int		test;

	test = f->max.z - f->min;
	d->p.x = (d->c.x - (f->max.x / 2)) * f->cf.space.x;
	d->p.y = (d->c.y - (f->max.y / 2)) * f->cf.space.y;
	d->p.z = (d->c.z - (test / 2)) * f->cf.space.z;
	d->f.x = f->cf.margin.x + cos(f->angle) * d->p.x - sin(f->angle) * d->p.y;
	d->f.y = f->cf.margin.y + sin(f->angle) * d->p.x + cos(f->angle) * d->p.y;
	d->f.y -= sqrt((float)2 / 3) * d->p.z;
	d->f.z = 0x00FFFFFF * (test ? (float)((d->c.z - f->min)) / test : 1);
	d->f.z += (d->f.z > 0x00000044 ? 0 : 0x00000044);
}

