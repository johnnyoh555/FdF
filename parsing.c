/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jooh <jooh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 12:15:04 by jooh              #+#    #+#             */
/*   Updated: 2023/12/10 17:32:13 by jooh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_free(char **arr)
{
	int	i;

	i = 0;
	if (arr == 0)
		return ;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

t_point	*point_info(char *arr, int x, int y)
{
	t_point	*ret;
	char	*p;

	ret = malloc(sizeof(t_point));
	if (ret == 0)
		error_seq("malloc");
	ret->x = x;
	ret->y = y;
	ret->z = ft_atoi(arr);
	ret->mx = x;
	ret->my = y;
	ret->mz = ret->z;
	p = ft_strchr(arr, ',');
	if (p)
		ret->color = convert_base(p + 3);
	else
		ret->color = 0x00ffffff;
	return (ret);
}

t_point	**check_x(t_info *info, int fd, int y)
{
	char	*str;
	char	**arr;
	int		i;
	t_point	**ret;

	str = get_next_line(fd);
	arr = ft_split(str, ' ');
	if (str == 0 || arr == 0)
		error_seq("malloc");
	i = 0;
	while (arr[i])
		i++;
	info->max_x = i;
	ret = malloc(sizeof(t_point *) * i);
	if (ret == 0)
		error_seq("malloc");
	i = -1;
	while (arr[++i])
		ret[i] = point_info(arr[i], i, y);
	free(str);
	ft_free(arr);
	return (ret);
}

void	check_y(t_info *info, char *mapname)
{
	int		fd;
	char	*str;
	int		i;

	i = 0;
	info->sin10 = sin(M_PI / 18);
	info->cos10 = cos(M_PI / 18);
	info->xspin = 0;
	info->yspin = 0;
	fd = open(mapname, O_RDONLY);
	if (fd == -1)
		error_seq(mapname);
	while (1)
	{
		str = get_next_line(fd);
		if (!str)
			break ;
		free(str);
		i++;
	}
	info->max_y = i;
	close(fd);
}

void	init_info(t_info *info, char *mapname)
{
	t_point	***pi;
	int		i;
	int		fd;

	info->dis = 1;
	info->sin30 = sin(M_PI / 6);
	info->cos30 = cos(M_PI / 6);
	info->move_x = 0;
	info->move_y = 0;
	check_y(info, mapname);
	pi = (t_point ***)malloc(sizeof(t_point **) * info->max_y);
	if (pi == 0)
		error_seq("malloc");
	fd = open(mapname, O_RDONLY);
	if (fd == -1)
		error_seq(mapname);
	i = -1;
	while (++i < info->max_y)
		pi[i] = check_x(info, fd, i);
	info->pi = pi;
	info->endian = 0;
	info->size = 1080;
	info->pixel = 32;
	info->mlx = mlx_init();
	info->win = mlx_new_window(info->mlx, 1080, 720, "FdF");
	info->img = mlx_new_image(info->mlx, 1080, 720);
}
