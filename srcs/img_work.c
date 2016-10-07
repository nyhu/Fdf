/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img_work.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tboos <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/04 16:20:22 by tboos             #+#    #+#             */
/*   Updated: 2016/10/07 18:49:59 by tboos            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		ft_put_img_to_win(t_fdf *f)
{
	if (f->img)
	{
		mlx_put_image_to_window(f->mlx, f->win, f->img, 0, 0);
		return (1);
	}
	return (0);
}

void	ft_img_reset(t_fdf *f)
{
	ft_bzero(f->addr, f->ls * f->s_win.y);
}

void	ft_put_pixel(t_fdf *f, int x, int y, int rgb)
{
	char	*pxl;

	if (x >= 0 && y >= 0 && x < f->s_win.x && y < f->s_win.y)
	{
		pxl = f->addr + f->ls * y + f->bpp / 8 * x;
		rgb = mlx_get_color_value(f->mlx, rgb);
		*((int*)pxl) = rgb;
	}
}

void	ft_print_line(t_fdf *f, t_dot *d1, t_dot *d2, int c)
{
	t_dot	w;
	double	tmp;

	w.f.x = d1->f.x;
	w.f.y = d1->f.y;
	w.f.z = d1->f.z;
	w.p.x = d2->f.x - w.f.x;
	w.p.y = d2->f.y - w.f.y;
	if ((tmp = sqrt(pow(w.p.x, 2) + pow(w.p.y, 2))))
	{
		w.p.x /= tmp;
		w.p.y /= tmp;
		w.p.z = (d2->f.z - w.f.z) / tmp;
		ft_put_pixel(f, w.f.x, w.f.y, ft_color(f, w.f.z));
		while (--tmp > 0)
		{
			ft_put_pixel(f, w.f.x, w.f.y, c < 0 ? ft_color(f, w.f.z) : c);
			w.f.x += w.p.x;
			w.f.y += w.p.y;
			w.f.z += w.p.z;
		}
		ft_put_pixel(f, w.f.x, w.f.y, ft_color(f, w.f.z));
	}
}
