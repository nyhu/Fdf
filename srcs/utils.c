/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tboos <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/04 16:20:43 by tboos             #+#    #+#             */
/*   Updated: 2016/10/04 16:20:45 by tboos            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_run_dot(t_fdf *f, void (*ft)(t_fdf *f, t_dot *dot))
{
	int	i;
	int	j;

	if (cos(f->angle) > 0)
	{
		i = -1;
		while (++i < f->max.y)
		{
			j = -1;
			while (++j < f->max.x)
				ft(f, &(f->map[i][j]));
		}
	}
	else
	{
		i = f->max.y;
		while (--i >= 0)
		{
			j = f->max.x;
			while (--j >= 0)
				ft(f, &(f->map[i][j]));
		}
	}
}
