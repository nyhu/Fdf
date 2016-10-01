#include "fdf.h"

void	ft_run_dot(t_fdf *f, void (*ft)(t_fdf *f, t_dot *dot))
{
	int	i;
	int	j;

	i = -1;
	while (++i < f->max.y)
	{
		j= -1;
		while (f->map[i][++j].exist)
			ft(f, &(f->map[i][j]));
	}
}
