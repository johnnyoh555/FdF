/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jooh <jooh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 19:37:28 by jooh              #+#    #+#             */
/*   Updated: 2023/11/26 22:41:05 by jooh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	cha_color(int color1, int color2, float x)
{
	float	r;
	float	g;
	float	b;

	if (color1 == color2)
		return (color1);
	r = get_r(color1) + (get_r(color2) - get_r(color1)) * x;
	g = get_g(color1) + (get_g(color2) - get_g(color1)) * x;
	b = get_b(color1) + (get_b(color2) - get_b(color1)) * x;
	return (create_trgb(0, r, g, b));
}

int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

int	get_r(int trgb)
{
	return ((trgb >> 16) & 0xFF);
}

int	get_g(int trgb)
{
	return ((trgb >> 8) & 0xFF);
}

int	get_b(int trgb)
{
	return (trgb & 0xFF);
}
