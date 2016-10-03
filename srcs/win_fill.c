#include "fdf.h"

static double ft_fill_work_dot(t_dot *d1, t_dot *d2, t_dot *w1)
{
	double	tmp;

	w1->f.x = d1->f.x;
	w1->f.y = d1->f.y;
	w1->f.z = d1->f.z;
	w1->p.x = d2->f.x - w1->f.x;
	w1->p.y = d2->f.y - w1->f.y;
	tmp = sqrt(pow(w1->p.x, 2) + pow(w1->p.y, 2));
	w1->p.x /= tmp;
	w1->p.y /= tmp;
	w1->p.z = (d2->f.z - w1->f.z) / tmp;
	return (tmp);
}

static void	ft_cover_face(t_fdf *f, t_dot *w1, t_dot *w2, double *tmp)
{
	while (tmp[0] >= 0 || (w2->c.x && tmp[1] > 0))
	{
		if (!(f->cf.mode & FACE_H) && w2->c.x)
			ft_print_line(f, w1, w2, f->cf.mode & FACE_F ? -1 : 0);
		if (tmp[0] >= 0)
			ft_put_pixel(f, w1->f.x, w1->f.y, ft_color(f, w1->f.z));
		if (tmp[0] > 0)
		{
			w1->f.x += w1->p.x;
			w1->f.y += w1->p.y;
			w1->f.z += w1->p.z;
		}
		if (w2->c.x && tmp[1] > 0)
		{
			w2->f.x += w2->p.x;
			w2->f.y += w2->p.y;
			w2->f.z += w2->p.z;
		}
		(tmp[0])--;
		(tmp[1])--;
	}
}

static void	ft_node_face(t_fdf *f, t_dot *d)
{
	t_dot	w1;
	t_dot	w2;
	t_dot	*d4;
	double	tmp[2];

	tmp[0] = 0;
	w2.c.x = 0;
	if (sin(f->angle) >= 0 && d->c.y )
		tmp[0] = ft_fill_work_dot(&(f->map[d->c.y - 1][d->c.x]), d, &w1);
	else if (sin(f->angle) < 0 && d->c.y < f->max.y - 1)
		tmp[0] = ft_fill_work_dot(&(f->map[d->c.y + 1][d->c.x]), d, &w1);
	if (sin(f->angle) >= 0 && d->c.y && d->c.x && (w2.c.x = 1)
		&& (d4 = &(f->map[d->c.y - 1][d->c.x - 1])))
		tmp[1] = ft_fill_work_dot(d4, &(f->map[d->c.y][d->c.x - 1]), &w2);
	else if (sin(f->angle) < 0 && d->c.y < f->max.y - 1 && d->c.x < f->max.x - 1
			&& (w2.c.x = 1) && (d4 = &(f->map[d->c.y + 1][d->c.x + 1])))
		tmp[1] = ft_fill_work_dot(d4, &(f->map[d->c.y][d->c.x + 1]), &w2);
	if (tmp[0])
		ft_cover_face(f, &w1, &w2, tmp);
}

static void	ft_node_line(t_fdf *f, t_dot *d)
{
	if (cos(f->angle) >= 0 && d->c.x)
		ft_print_line(f, &(f->map[d->c.y][d->c.x - 1]), d, -1);
	if (sin(f->angle) >= 0 && d->c.y)
		ft_print_line(f, &(f->map[d->c.y - 1][d->c.x]), d, -1);
	if (cos(f->angle) < 0 && d->c.x < f->max.x - 1)
		ft_print_line(f, &(f->map[d->c.y][d->c.x + 1]), d, -1);
	if (sin(f->angle) < 0 && d->c.y < f->max.y - 1)
		ft_print_line(f, &(f->map[d->c.y + 1][d->c.x]), d, -1);
}

int			ft_win_fill(t_fdf *f)
{
	if (f->cf.mode & PROJ_I)
		ft_run_dot(f, &ft_dot_place_isometric);
	else if (f->cf.mode & PROJ_O)
		ft_run_dot(f, &ft_dot_place_dimetric);
	else
		ft_run_dot(f, &ft_dot_place_pers);
	if (f->cf.mode & FACE_H)
		ft_run_dot(f, &ft_node_line);
	else
		ft_run_dot(f, &ft_node_face);
	mlx_clear_window(f->mlx, f->win);
	mlx_put_image_to_window(f->mlx, f->win, f->img, 0, 0);
	ft_img_reset(f);
	if (f->cf.mode & LOOP)
		f->angle += 0.05;
	return (1);
}
