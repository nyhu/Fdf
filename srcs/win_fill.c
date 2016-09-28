#include "fdf.h"

static void	ft_dot_place(t_fdf *f, t_dot *d)
{
	d->p.x = f->cf.margin.x + ((d->c.x - d->c.y) * f->cf.space.x / 2);
	d->p.y = f->cf.margin.y + ((d->c.x + d->c.y) * f->cf.space.y / 2);
	d->p.y -= d->c.z * f->cf.space.z;
	dprintf(1,"cx = %d, cy = %d, ", d->c.x, d->c.y);
	dprintf(1,"px = %d, py = %d\n", d->p.x, d->p.y);
}

static void	ft_print_line(t_fdf *f, t_dot *d1, t_dot *d2)
{
	double dx;
	double dy;
	double x;
	double y;
	double temp;

	x = d1->p.x;
	y = d1->p.y;
	dx = d2->p.x - x;
	dy = d2->p.y - y;
	temp = sqrt((dx * dx) + (dy * dy));
	dx /= temp;
	dy /= temp;
	while (temp >= 0)
	{
		ft_put_pixel(f, x, y, 0x00FF0000);
		x += dx;
		y += dy;
		temp--;
	}
}

static void	ft_node_line(t_fdf *f, t_dot *d)
{
	if (d->c.x)
		ft_print_line(f, &(f->map[d->c.y][d->c.x - 1]), d);
	if (d->c.x < f->max.x - 1)
		ft_print_line(f, &(f->map[d->c.y][d->c.x + 1]), d);
	if (d->c.y)
		ft_print_line(f, &(f->map[d->c.y - 1][d->c.x]), d);
	if (d->c.y < f->max.y - 1)
		ft_print_line(f, &(f->map[d->c.y + 1][d->c.x]), d);
}

int			ft_win_fill(t_fdf *f)
{
	if (!(f->addr = mlx_get_data_addr(f->img, &(f->bpp), &(f->ls), &(f->endian))))
		return 0;
	ft_run_dot(f, &ft_dot_place);
	ft_run_dot(f, &ft_node_line);
	//	ft_put_pixel(f, 10, 10, 0x00FF0000);
	mlx_put_image_to_window(f->mlx, f->win, f->img, 0, 0);
	return 1;
}
