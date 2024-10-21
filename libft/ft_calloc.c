/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jooh <jooh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 16:59:27 by jooh              #+#    #+#             */
/*   Updated: 2023/10/11 11:16:46 by jooh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*arr;
	size_t	i;

	if (!count || !size)
		return (malloc(0));
	if (size > -1 / count)
		return (0);
	i = count * size;
	arr = malloc(sizeof(char) * i);
	if (arr == 0)
		return (0);
	ft_bzero(arr, i);
	return (arr);
}
