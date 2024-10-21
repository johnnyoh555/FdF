/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawline_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jooh <jooh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 13:48:57 by jooh              #+#    #+#             */
/*   Updated: 2023/11/28 15:59:53 by jooh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

void	draw_img(t_info *info, int x, int y, int color)
{
	char	*ptr;

	x += info->move_x + info->to_cen_x;
	y += info->move_y + info->to_cen_y;
	if (y >= 720 || x >= 1080 || y < 0 || x < 0)
		return ;
	ptr = (info->ptr) + (y * info->size + x * info->pixel / 8);
	*(int *)ptr = color;
}

void	upperline(t_info *info, t_point *pi1, t_point *pi2, int minus)
{
	int	dx;
	int	dy;
	int	x1;
	int	y1;
	int	p;

	x1 = pi1->px;
	y1 = pi1->py;
	dx = (pi2->px - x1) * minus;
	dy = pi2->py - y1;
	p = (2 * dx) - dy;
	while (y1 <= pi2->py)
	{
		draw_img(info, x1, y1, cha_color(pi1->color, pi2->color,
				(float)(y1 - pi1->py) / (float)(pi2->py - pi1->py)));
		y1++;
		if (p < 0)
			p = p + 2 * dx;
		else
		{
			p = p + 2 * (dx - dy);
			x1 += minus;
		}
	}
}

void	underline(t_info *info, t_point *pi1, t_point *pi2, int minus)
{
	int	dx;
	int	dy;
	int	x1;
	int	y1;
	int	p;

	x1 = pi1->px;
	y1 = pi1->py;
	dx = (pi2->px - x1);
	dy = (pi2->py - y1) * minus;
	p = (2 * dy) - dx;
	while (x1 <= pi2->px)
	{
		draw_img(info, x1, y1, cha_color(pi1->color, pi2->color,
				(float)(x1 - pi1->px) / (float)(pi2->px - pi1->px)));
		x1++;
		if (p < 0)
			p = p + 2 * dy;
		else
		{
			p = p + 2 * (dy - dx);
			y1 += minus;
		}
	}
}

void	bresenham(t_info *info, t_point pi1, t_point pi2)
{
	zoom_io(info, &pi1);
	zoom_io(info, &pi2);
	if (fabs(pi2.px - pi1.px) > fabs(pi2.py - pi1.py))
	{
		if ((pi1.px < pi2.px) && (pi1.py < pi2.py))
			underline(info, &pi1, &pi2, 1);
		else if ((pi1.px < pi2.px) && (pi1.py >= pi2.py))
			underline(info, &pi1, &pi2, -1);
		else if ((pi1.px >= pi2.px) && (pi1.py > pi2.py))
			underline(info, &pi2, &pi1, 1);
		else if ((pi1.px >= pi2.px) && (pi1.py <= pi2.py))
			underline(info, &pi2, &pi1, -1);
	}
	else
	{
		if ((pi1.py < pi2.py) && (pi1.px < pi2.px))
			upperline(info, &pi1, &pi2, 1);
		else if ((pi1.py < pi2.py) && (pi1.px >= pi2.px))
			upperline(info, &pi1, &pi2, -1);
		else if ((pi1.py >= pi2.py) && (pi1.px > pi2.px))
			upperline(info, &pi2, &pi1, 1);
		else if ((pi1.py >= pi2.py) && (pi1.px <= pi2.px))
			upperline(info, &pi2, &pi1, -1);
	}
}

void	drawline(t_info *info)
{
	if ((info->xspin >= 5 && info->xspin < 23))
		from_back(info);
	else
		from_front(info);
}
