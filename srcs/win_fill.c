#include "fdf.h"

static int	ft_color(double z)
{
	int		color;

	if (z < 0x000000FF)
		color = (int)z;
	else if (z < 0x0000FFFF)
		color = ((int)z & 0x0000FF00);
	else if (z < 0x00FFFFFF)
		color = ((int)z & 0x00FF0000);
	else
		color = 0x00FFFFFF;
	return (color);
}

static void	ft_print_line(t_fdf *f, t_dot *d1, t_dot *d2)
{
	double dx;
	double dy;
	double dz;
	double x;
	double y;
	double z;
	double tmp;

	x = d1->f.x;
	y = d1->f.y;
	z = d1->f.z;
	dx = d2->f.x - x;
	dy = d2->f.y - y;
	tmp = sqrt((dx * dx) + (dy * dy));
	dx /= tmp;
	dy /= tmp;
	dz = (d2->f.z - z) / tmp;
	while (tmp-- >= 0)
	{
		ft_put_pixel(f, x, y, ft_color(z));
		x += dx;
		y += dy;
		z += dz;
	}
}

static void	ft_node_line(t_fdf *f, t_dot *d)
{
	if (d->c.x)
		ft_print_line(f, &(f->map[d->c.y][d->c.x - 1]), d);
	if (f->map[d->c.y][d->c.x + 1].exist)
		ft_print_line(f, &(f->map[d->c.y][d->c.x + 1]), d);
	if (d->c.y)
		ft_print_line(f, &(f->map[d->c.y - 1][d->c.x]), d);
	if (d->c.y < f->max.y - 1)
		ft_print_line(f, &(f->map[d->c.y + 1][d->c.x]), d);
}

int			ft_win_fill(t_fdf *f)
{
	if (f->cf.mode & PROJ_I)
		ft_run_dot(f, &ft_dot_place_isometric);
	else if (f->cf.mode & PROJ_O)
		ft_run_dot(f, &ft_dot_place_dimetric);
	else
		ft_run_dot(f, &ft_dot_place_pers);
	ft_run_dot(f, &ft_node_line);
	mlx_clear_window(f->mlx, f->win);
	mlx_put_image_to_window(f->mlx, f->win, f->img, 0, 0);
	return (1);
}
