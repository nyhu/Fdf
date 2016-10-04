/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tboos <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/04 16:20:32 by tboos             #+#    #+#             */
/*   Updated: 2016/10/04 16:30:47 by tboos            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static char	**ft_read_file(int fd, char *line)
{
	char	**tab;
	char	**res;

	tab = NULL;
	res = NULL;
	while ((tab = ft_strtabadd(res, line)))
	{
		if (tab != res)
			ft_freegiveone((void**)&res);
		res = tab;
		if (!get_next_line(fd, &line))
			return (res);
	}
	ft_freegiveone((void**)&line);
	ft_strtabfree(res);
	return (NULL);
}

static char	*ft_fill_dots(t_fdf *f, char **t, int i)
{
	int		j;

	j = -1;
	while (t[++j] && j <= (f->max.x + 3))
	{
		f->map[i][j].exist = 1;
		f->map[i][j].c.x = j;
		f->map[i][j].c.y = i;
		f->map[i][j].c.z = ft_atoi(t[j]);
		if (f->map[i][j].c.z > f->max.z)
			f->max.z = f->map[i][j].c.z;
		if (f->map[i][j].c.z < f->min)
			f->min = f->map[i][j].c.z;
	}
	if (t[j])
	{
		ft_strtabfree(t);
		return ("fdf: map error");
	}
	return (NULL);
}

static char	*ft_split_lines(t_fdf *f, char **tab)
{
	char	**t;
	char	*err;
	int		i;

	i = 0;
	if (0 >= (f->max.y = ft_strtablen(tab)))
		return ("fdf: map error");
	else if (!(f->map = (t_dot **)ft_memalloc(sizeof(t_dot *) * (f->max.y))))
		return ("fdf: malloc error");
	if (!(t = ft_strsplit(tab[i], ' ')))
		return ("fdf: malloc error");
	f->max.x = ft_strtablen(t);
	while ((f->map[i] = (t_dot *)ft_memalloc(sizeof(t_dot) * (f->max.x + 4))))
	{
		if ((err = ft_fill_dots(f, t, i)))
			return (err);
		ft_strtabfree(t);
		if (++i == f->max.y)
			break ;
		if (!(t = ft_strsplit(tab[i], ' ')))
			return ("fdf: malloc error");
	}
	return (NULL);
}

char		*ft_parse_file(char *file, t_fdf *f)
{
	int		fd;
	char	*line;
	char	**tab;
	char	*err;

	tab = NULL;
	f->title = file;
	if ((fd = open(file, O_RDONLY)) == -1)
		return ("fdf: cannot open input file");
	if (-1 == get_next_line(fd, &line))
		err = "fdf: connot read input file";
	else if (!(tab = ft_read_file(fd, line)))
		err = "fdf: malloc error";
	else if (!(err = ft_split_lines(f, tab)) && !(f->max.x))
		err = "fdf: map error";
	ft_strtabfree(tab);
	close(fd);
	return (err);
}
