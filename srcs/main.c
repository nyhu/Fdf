/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tboos <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/04 16:20:27 by tboos             #+#    #+#             */
/*   Updated: 2016/10/07 16:19:53 by tboos            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	ft_handle_hook(int keycode, t_fdf *f)
{
	if (keycode == XK_ESPACE)
		ft_free_fdf(f);
	else if (keycode == XK_BACKSPACE)
		ft_cf_reset(f);
	else if (keycode == XK_LEFT || keycode == XK_RIGHT)
		ft_rotate(f, keycode == XK_LEFT ? '-' : '+');
	else
		ft_config(f, keycode);
	return (1);
}

int			main(int ac, char **av)
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
		|| !(f.img = mlx_new_image(f.mlx, f.s_win.x, f.s_win.y))
		|| !(f.addr = mlx_get_data_addr(f.img, &(f.bpp), &(f.ls), &(f.endian))))
		ft_putendl("fdf: error while initializing windows with mlx");
	else
	{
//		mlx_expose_hook(f.win, ft_put_img_to_win, &f);
		mlx_loop_hook(f.mlx, ft_win_fill, &f);
		mlx_hook(f.win, 2, 1L << 0, ft_handle_hook, &f);
		mlx_loop(f.mlx);
	}
	ft_free_fdf(&f);
	return (0);
}
