#include "fdf.h"

static void	ft_dot_place(t_fdf *f, t_dot *d)
{
	d->p.x = f->cent.x + (d->c.x - f->moy.x) * f->cf.space.x;
	d->p.x -= (d->c.y - f->moy.y) * f->cf.space.y;
	d->p.y = f->cent.y + (d->c.y - f->moy.y) * f->cf.space.y;
	d->p.y -= (d->c.x - f->moy.x) * f->cf.space.x;
	d->p.y -= d->c.z * f->cf.space.z;
}

static void	ft_print_line(t_fdf *f, t_dot *d)
{
	ft_put_pixel(f, d->p.x, d->p.y, 0x00FFFFFF);
}

int			ft_win_fill(t_fdf *f)
{
	if (!(f->addr = mlx_get_data_addr(f->img, &(f->bpp), &(f->ls), &(f->endian))))
		return 0;
	ft_run_dot(f, &ft_dot_place());
	ft_run_dot(f, &ft_print_line());
	mlx_put_image_to_window(f->mlx, f->win, f->img, 0, 0);
	return 1;
}
