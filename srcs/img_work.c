#include "fdf.h"

void	ft_put_pixel(t_fdf *f, int x, int y, int rgb)
{
	char	*pxl;

	if (x >= 0 && y >= 0 && x < f->s_win.x && y < f->s_win.y)
	{
		pxl = f->addr + f->ls * y + f->bpp / 8 * x;
		rgb = mlx_get_color_value(f->mlx, rgb);
		*((int*)pxl) = rgb;
	}
}
