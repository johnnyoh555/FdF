/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isometric.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jooh <jooh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 13:47:27 by jooh              #+#    #+#             */
/*   Updated: 2023/12/10 17:26:10 by jooh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include  "fdf.h"

void	to_cen(t_info *info, t_point *p)
{
	info->to_cen_x = 540 - p->px * info->dis;
	info->to_cen_y = 360 - p->py * info->dis;
}

void	calc_isometric(t_info *info, t_point *p)
{
	p->px = (p->mx - p->my) * info->cos30;
	p->py = (p->mx + p->my) * info->sin30 - p->mz / 2;
}

void	isometric(t_info *info)
{
	int	i;
	int	j;

	i = 0;
	while (i < info->max_y)
	{
		j = 0;
		while (j < info->max_x)
		{
			calc_isometric(info, (info->pi)[i][j]);
			j++;
		}
		i++;
	}
}

void	zoom_io(t_info *info, t_point *p)
{
	p->px = round(p->px * info->dis);
	p->py = round(p->py * info->dis);
}
