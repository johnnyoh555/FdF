/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spinhooks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jooh <jooh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 20:17:38 by jooh              #+#    #+#             */
/*   Updated: 2023/11/28 14:59:22 by jooh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	spin_byx(t_info *info)
{
	info->xspin++;
	if (info->xspin == 36)
		info->xspin = 0;
	if (info->aftimg == 0)
	{
		mlx_destroy_image(info->mlx, info->img);
		info->img = mlx_new_image(info->mlx, 1080, 720);
		info->ptr = mlx_get_data_addr(info->img, &(info->pixel),
				&(info->size), &(info->endian));
	}
	spinning_byx(info);
	isometric(info);
	to_cen(info, (info->pi)[(info->max_y - 1) / 2][(info->max_x - 1) / 2]);
	drawline(info);
	mlx_put_image_to_window(info->mlx, info->win, info->img, 0, 0);
}

void	spin_byy(t_info *info)
{
	info->yspin++;
	if (info->yspin == 36)
		info->yspin = 0;
	if (info->aftimg == 0)
	{
		mlx_destroy_image(info->mlx, info->img);
		info->img = mlx_new_image(info->mlx, 1080, 720);
		info->ptr = mlx_get_data_addr(info->img, &(info->pixel),
				&(info->size), &(info->endian));
	}
	spinning_byy(info);
	isometric(info);
	to_cen(info, (info->pi)[(info->max_y - 1) / 2][(info->max_x - 1) / 2]);
	drawline(info);
	mlx_put_image_to_window(info->mlx, info->win, info->img, 0, 0);
}

void	from_front(t_info *info)
{
	int	i;
	int	j;

	i = 0;
	while (i < info->max_y)
	{
		j = 0;
		while (j < info->max_x)
		{
			if (i != info->max_y - 1)
				bresenham(info, *((info->pi)[i][j]), *(info->pi[i + 1][j]));
			if (j != info->max_x - 1)
				bresenham(info, *((info->pi)[i][j]), *(info->pi[i][j + 1]));
			j++;
		}
		i++;
	}
}

void	from_back(t_info *info)
{
	int	i;
	int	j;

	i = info->max_y - 1;
	while (i >= 0)
	{
		j = info->max_x - 1;
		while (j >= 0)
		{
			if (i != 0)
				bresenham(info, *((info->pi)[i][j]), *(info->pi[i - 1][j]));
			if (j != 0)
				bresenham(info, *((info->pi)[i][j]), *(info->pi[i][j - 1]));
			j--;
		}
		i--;
	}
}
