/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tboos <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/04 16:20:43 by tboos             #+#    #+#             */
/*   Updated: 2016/10/07 19:19:03 by tboos            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_run_dot(t_fdf *f, void (*ft)(t_fdf *f, t_dot *dot))
{
	int	i;
	int	j;

	i = cos(f->angle) >= 0 ? -1 : f->max.y;
	while ((cos(f->angle) >= 0 && ++i < f->max.y)
		|| (cos(f->angle) < 0 && --i >= 0))
	{
		j = sin(f->angle) >= 0 ? -1 : f->max.x;
		while ((sin(f->angle) >= 0 && ++j < f->max.x)
				|| (sin(f->angle) < 0 && --j >= 0))
			ft(f, &(f->map[i][j]));
	}
}
