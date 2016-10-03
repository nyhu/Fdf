#include "fdf.h"

static void	ft_cover_line(t_fdf *f, t_dot *d1, t_dot *d2)
{
	t_dot	w;
	double	tmp;

	w.f.x = d1->f.x;
	w.f.y = d1->f.y;
	w.f.z = d1->f.z;
	w.p.x = d2->f.x - w.f.x;
	w.p.y = d2->f.y - w.f.y;
	tmp = sqrt(pow(w.p.x, 2) + pow(w.p.y, 2));
	w.p.x /= tmp;
	w.p.y /= tmp;
	w.p.z = (d2->f.z - w.f.z) / tmp;
	while (tmp-- > 0)
	{
		ft_put_pixel(f, w.f.x, w.f.y, 0x00000000);
		w.f.x += w.p.x;
		w.f.y += w.p.y;
		w.f.z += w.p.z;
	}
}

static void	ft_cover_face(t_fdf *f, t_dot *w, t_dot *d)
{
	if (cos(f->angle) > 0 && d->c.x && d->c.y)
		ft_cover_line(f, &(f->map[d->c.y - 1][d->c.x - 1]), w);
	if (sin(f->angle) > 0 && d->c.x && d->c.y < f->max.y - 1)
		ft_cover_line(f, &(f->map[d->c.y + 1][d->c.x - 1]), w);
	if (sin(f->angle) < 0 && d->c.y && d->c.x < f->max.x)
		ft_cover_line(f, &(f->map[d->c.y - 1][d->c.x + 1]), w);
	if (cos(f->angle) < 0 && d->c.y < f->max.y - 1 && d->c.x < f->max.x - 1)
		ft_cover_line(f, &(f->map[d->c.y + 1][d->c.x + 1]), w);
}

static void	ft_print_line(t_fdf *f, t_dot *d1, t_dot *d2)
{
	t_dot	w;
	double	tmp;

	w.f.x = d1->f.x;
	w.f.y = d1->f.y;
	w.f.z = d1->f.z;
	w.p.x = d2->f.x - w.f.x;
	w.p.y = d2->f.y - w.f.y;
	tmp = sqrt(pow(w.p.x, 2) + pow(w.p.y, 2));
	w.p.x /= tmp;
	w.p.y /= tmp;
	w.p.z = (d2->f.z - w.f.z) / tmp;
	while (tmp-- >= 0)
	{
		if (!(f->cf.mode & FACE_H))
			ft_cover_face(f, &w, d2);
		ft_put_pixel(f, w.f.x, w.f.y, ft_color(f, w.f.z));
		w.f.x += w.p.x;
		w.f.y += w.p.y;
		w.f.z += w.p.z;
	}
}

static void	ft_node_line(t_fdf *f, t_dot *d)
{
	if (cos(f->angle) >= 0 && d->c.x)
		ft_print_line(f, &(f->map[d->c.y][d->c.x - 1]), d);
	if (sin(f->angle) >= 0 && d->c.y)
		ft_print_line(f, &(f->map[d->c.y - 1][d->c.x]), d);
	if (cos(f->angle) < 0 && d->c.x + 1 < f->max.x)
		ft_print_line(f, &(f->map[d->c.y][d->c.x + 1]), d);
	if (sin(f->angle) < 0 && d->c.y < f->max.y - 1)
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
	ft_img_reset(f);
	if (f->cf.mode & LOOP)
		f->angle += 0.05;
	return (1);
}
