/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pers.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tboos <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/04 16:20:37 by tboos             #+#    #+#             */
/*   Updated: 2016/10/07 20:39:53 by tboos            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_dot_place_pers(t_fdf *f, t_dot *d)
{
	int		test;

	test = f->max.z - f->min;
	d->p.x = (d->c.x - (f->max.x / 2)) * f->cf.space.x * 2;
	d->p.y = (-d->c.y - (f->max.y / 2)) * f->cf.space.y * 2;
	d->p.z = (d->c.z - (test / 2)) * f->cf.space.z;
	d->f.x = f->cf.margin.x + cos(f->angle) * d->p.x - sin(f->angle) * d->p.z;
	d->f.y = f->cf.margin.y / 2;
	d->f.y += sin(f->angle) * d->p.x + cos(f->angle) * d->p.z;
	d->f.y -= sqrt((float)2 / 3) * d->p.y;
	d->f.z = d->c.z - f->min;
	d->f.z /= test ? test : 1;
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
	d->f.z = d->c.z - f->min;
	d->f.z /= test ? test : 1;
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
	d->f.z = d->c.z - f->min;
	d->f.z /= test ? test : 1;
}
