#include "fdf.h"

static void	ft_print_dot(t_fdf *f)
{
	int	i;
	int	j;

	i = -1;
	while (++i < f->max.y)
	{
		j= -1;
		while (++j < f->max.x)
		{
			ft_putnbr(f->map[i][j].c.z);
			ft_putchar(' ');
		}
		ft_putchar('\n');
	}
}

int	ft_win_fill(t_fdf *f)
{
	if (!(f->addr = mlx_get_data_addr(f->img, &(f->bpp), &(f->ls), &(f->endian))))
		return 0;
//	ft_dot_place(f);
//	ft_line_trace(f);
	ft_print_dot(f);
	mlx_put_image_to_window(f->mlx, f->win, f->img, 0, 0);
	return 1;
}
