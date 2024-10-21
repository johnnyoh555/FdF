/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jooh <jooh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 20:40:51 by jooh              #+#    #+#             */
/*   Updated: 2023/11/28 15:59:31 by jooh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

void	change_dis(t_info *info, int i)
{
	if (i == 27 && info->dis != 1)
		info->dis -= 1;
	else if (i == 24 && info->dis < 12)
		info->dis += 1;
	else
		return ;
	if (info->aftimg == 0)
	{
		mlx_destroy_image(info->mlx, info->img);
		info->img = mlx_new_image(info->mlx, 1080, 720);
		info->ptr = mlx_get_data_addr(info->img, &(info->pixel),
				&(info->size), &(info->endian));
	}
	to_cen(info, (info->pi)[(info->max_y - 1) / 2][(info->max_x - 1) / 2]);
	drawline(info);
	mlx_put_image_to_window(info->mlx, info->win, info->img, 0, 0);
}

void	move_point(t_info *info, int i)
{
	if (i == 13)
		info->move_y -= 10;
	if (i == 1)
		info->move_y += 10;
	if (i == 0)
		info->move_x -= 10;
	if (i == 2)
		info->move_x += 10;
	if (i == 8)
	{
		info->move_x = 0;
		info->move_y = 0;
	}
	if (info->aftimg == 0)
	{
		mlx_destroy_image(info->mlx, info->img);
		info->img = mlx_new_image(info->mlx, 1080, 720);
		info->ptr = mlx_get_data_addr(info->img, &(info->pixel),
				&(info->size), &(info->endian));
	}
	to_cen(info, (info->pi)[(info->max_y - 1) / 2][(info->max_x - 1) / 2]);
	drawline(info);
	mlx_put_image_to_window(info->mlx, info->win, info->img, 0, 0);
}

void	del_screen(t_info *info)
{
	free_vector(info);
	mlx_destroy_image(info->mlx, info->img);
	mlx_destroy_window(info->mlx, info->win);
	write(1, "\e[32mGood by FdF\n\e[0m", 21);
	exit(0);
}

void	afterimage(t_info *info)
{
	if (info->aftimg == 0)
		info->aftimg = 1;
	else
		info->aftimg = 0;
}

int	key_press(int keycode, t_info *info)
{
	if (keycode == 53)
		del_screen(info);
	if (keycode == 13 || keycode == 1 || keycode == 0 || keycode == 2
		|| keycode == 8)
		move_point(info, keycode);
	if (keycode == 27 || keycode == 24)
		change_dis(info, keycode);
	if (keycode == 18)
		spin_byx(info);
	if (keycode == 19)
		spin_byy(info);
	if (keycode == 4)
		init_spin(info);
	if (keycode == 46)
		ppt(info);
	if (keycode == 3)
		front(info);
	if (keycode == 12)
		afterimage(info);
	return (0);
}
