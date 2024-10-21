/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jooh <jooh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 21:19:58 by jooh              #+#    #+#             */
/*   Updated: 2023/11/28 15:59:29 by jooh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

void	init_header_info(t_info *info)
{
	info->dis = 1;
	info->xspin = 0;
	info->yspin = 0;
	info->move_x = 0;
	info->move_y = 0;
}

void	init_header(t_info *info, int k)
{
	int	i;
	int	j;

	i = 0;
	while (i < info->max_y)
	{
		j = 0;
		while (j < info->max_x)
		{
			((info->pi)[i][j])->mx = ((info->pi)[i][j])->x;
			((info->pi)[i][j])->my = ((info->pi)[i][j])->y;
			((info->pi)[i][j])->mz = ((info->pi)[i][j])->z;
			((info->pi)[i][j])->py = ((info->pi)[i][j])->y;
			((info->pi)[i][j])->px = ((info->pi)[i][j])->x;
			if (k == 1)
			{
				((info->pi)[i][j])->px = ((info->pi)[i][j])->x;
				((info->pi)[i][j])->py = -((info->pi)[i][j])->z;
			}
			j++;
		}
		i++;
	}
	init_header_info(info);
}

void	init_spin(t_info *info)
{
	init_header(info, 0);
	mlx_destroy_image(info->mlx, info->img);
	info->img = mlx_new_image(info->mlx, 1080, 720);
	info->ptr = mlx_get_data_addr(info->img, &(info->pixel),
			&(info->size), &(info->endian));
	isometric(info);
	to_cen(info, (info->pi)[(info->max_y - 1) / 2][(info->max_x - 1) / 2]);
	drawline(info);
	mlx_put_image_to_window(info->mlx, info->win, info->img, 0, 0);
}

void	ppt(t_info *info)
{
	init_header(info, 0);
	mlx_destroy_image(info->mlx, info->img);
	to_cen(info, (info->pi)[(info->max_y - 1) / 2][(info->max_x - 1) / 2]);
	info->img = mlx_new_image(info->mlx, 1080, 720);
	info->ptr = mlx_get_data_addr(info->img, &(info->pixel),
			&(info->size), &(info->endian));
	drawline(info);
	mlx_put_image_to_window(info->mlx, info->win, info->img, 0, 0);
}

void	front(t_info *info)
{
	init_header(info, 1);
	mlx_destroy_image(info->mlx, info->img);
	to_cen(info, (info->pi)[(info->max_y - 1) / 2][(info->max_x - 1) / 2]);
	info->img = mlx_new_image(info->mlx, 1080, 720);
	info->ptr = mlx_get_data_addr(info->img, &(info->pixel),
			&(info->size), &(info->endian));
	drawline(info);
	mlx_put_image_to_window(info->mlx, info->win, info->img, 0, 0);
}
