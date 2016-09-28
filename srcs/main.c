#include "fdf.h"

int	main(int ac, char **av)
{
	t_fdf	f;
	char	*err;

	ft_bzero((void *)&f, sizeof(t_fdf));
	if (ac == 1)
		ft_putendl("fdf: missing input file");
	else if ((err = ft_parse_file(av[1], &f)))
		ft_putendl(err);
	else if (!(f.mlx = mlx_init()) || !ft_cf_reset(&f)
		|| !(f.win = mlx_new_window(f.mlx, f.s_win.x, f.s_win.y, f.title))
		|| !(f.img = mlx_new_image(f.mlx, f.s_win.x, f.s_win.y)))
		ft_putendl("fdf: error while initializing windows with mlx");
	else if (!ft_win_fill(&f))
		ft_putendl("fdf: error while cooking first window");
	else
		mlx_loop(f.mlx);
	ft_free_fdf(&f);
	return (0);
}
