/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jooh <jooh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 20:20:51 by jooh              #+#    #+#             */
/*   Updated: 2023/11/28 15:59:55 by jooh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

int	checkstr(char str, char *base)
{
	int	i;

	i = 0;
	while (base[i])
	{
		if (base[i] == str)
			return (i);
		i++;
	}
	return (-1);
}

int	convert_base(char *str)
{
	int long	value;
	int			a;

	if (*str == 0)
		return (0);
	value = 0;
	while (*str)
	{
		a = checkstr(*str, "0123456789abcdef");
		if (a == -1)
		{
			a = checkstr(*str, "0123456789ABCDEF");
			if (a == -1)
				break ;
		}
		value *= 16;
		value += a;
		str++;
	}
	return ((int)value);
}
