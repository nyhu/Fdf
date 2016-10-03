#include "fdf.h"

static int	ft_color_v(double z)
{
	int		color;

	if (z < 0x000000FF)
		color = (int)z;
	else if (z < 0x0011FFFF)
		color = ((int)z & 0x0000FF00);
	else if (z < 0x00FFFFFF)
		color = ((int)z & 0x00FF0000);
	else
		color = 0x00FFFFFF;
	return (color);
}

static int	ft_color_b(double z)
{
	int		color;

	if (z < 0x000000FF)
		color = 0x000000FF;
	else if (z < 0x0011FFFF)
		color = ((int)z & 0x0000FF00) >> 8;
	else if (z < 0x00FFFFFF)
		color = (((int)z & 0x00FF0000) >> 16) + ((int)z & 0x00FF0000);
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
