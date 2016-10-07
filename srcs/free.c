/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tboos <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/04 16:20:16 by tboos             #+#    #+#             */
/*   Updated: 2016/10/04 16:20:19 by tboos            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		ft_free_fdf(t_fdf *f)
{
	int	i;

	i = -1;
	if (f->map)
	{
		while (++i < f->max.y && f->map[i])
			free(f->map[i]);
		free(f->map);
	}
	if (f->win)
		mlx_destroy_window(f->mlx, f->win);
	if (f->img)
		mlx_destroy_image(f->mlx, f->img);
	exit(0);
}
