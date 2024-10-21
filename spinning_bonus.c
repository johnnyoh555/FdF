/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spinning_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jooh <jooh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 20:03:38 by jooh              #+#    #+#             */
/*   Updated: 2023/11/28 15:59:14 by jooh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

void	calc_spinning_byy(t_info *info, t_point *p)
{
	float	x;
	float	z;

	x = p->mx;
	z = p->mz;
	p->mx = x * cos(info->mpi18) - z * sin(info->mpi18);
	p->mz = x * sin(info->mpi18) + z * cos(info->mpi18);
}

void	spinning_byy(t_info *info)
{
	int	i;
	int	j;

	i = 0;
	while (i < info->max_y)
	{
		j = 0;
		while (j < info->max_x)
		{
			calc_spinning_byy(info, (info->pi)[i][j]);
			j++;
		}
		i++;
	}
}

void	calc_spinning_byx(t_info *info, t_point *p)
{
	float	z;
	float	y;

	y = p->my;
	z = p->mz;
	p->my = y * cos(info->mpi18) + z * sin(info->mpi18);
	p->mz = -y * sin(info->mpi18) + z * cos(info->mpi18);
}

void	spinning_byx(t_info *info)
{
	int	i;
	int	j;

	i = 0;
	while (i < info->max_y)
	{
		j = 0;
		while (j < info->max_x)
		{
			calc_spinning_byx(info, (info->pi)[i][j]);
			j++;
		}
		i++;
	}
}
