/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tboos <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/04 16:19:28 by tboos             #+#    #+#             */
/*   Updated: 2016/10/07 20:39:52 by tboos            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	ft_color_v(double z)
{
	int		color;

	if (z == 0)
		color = 0x000000FF;
	else if (z < 0.05)
		color = 0x0000FF00;
	else if (z < 1)
		color = (int)(z * 0x000000FF) << 16;
	else
		color = 0x00FFFFFF;
	return (color);
}

static int	ft_color_b(double z)
{
	int		color;

	if (z < 0.05)
		color = 0x000000FF;
	else if (z < 0.6)
		color = 0x00FF0000 + 0x0000FF00;
	else if (z < 0.9)
		color = 0x0000FF00;
	else
		color = 0x00FFFFFF;
	return (color);
}

int			ft_color(t_fdf *f, double z)
{
	if (f->cf.mode & COLOR_N)
		return (0x00FFFFFF);
	else if (f->cf.mode & COLOR_V)
		return (ft_color_v(z));
	else
		return (ft_color_b(z));
}
