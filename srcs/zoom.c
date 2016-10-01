#include "fdf.h"

void	ft_zoom(t_fdf *f, char c)
{
	if (c == '+')
	{
		f->cf.space.x *= 1.1;
		f->cf.space.y *= 1.1;
		f->cf.space.z *= 1.1;
	}
	else if (c == '-')
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
		f->cf.margin.y *= 1.1;
	else if (c == 'd')
		f->cf.margin.y /= 1.1;
	else if (c == 'a')
		f->cf.margin.x *= 1.1;
	else if (c == 'q')
		f->cf.margin.x /= 1.1;
}
