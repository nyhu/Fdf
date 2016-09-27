#include "fdf.h"

void	ft_free_fdf(t_fdf *f)
{
	int	i;

	i = -1;
	if (f->map)
	{
		while (f->map[++i])
			free(f->map[i]);
		free(f->map);
	}
	if (f->win)
		mlx_destroy_window(f->mlx, f->win);
	if (f->img)
		mlx_destroy_image(f->mlx, f->img);
}
