/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jooh <jooh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 14:29:41 by jooh              #+#    #+#             */
/*   Updated: 2023/11/28 15:59:23 by jooh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include  "fdf_bonus.h"

void	free_vector(t_info *info)
{
	int	i;
	int	j;

	i = 0;
	while (i < info->max_y)
	{
		j = 0;
		while (j < info->max_x)
		{
			free((info->pi)[i][j]);
			j++;
		}
		free((info->pi)[i]);
		i++;
	}
	free(info->pi);
}

int	on_destroy(int i, t_info *info)
{
	i++;
	info++;
	info--;
	write(1, "\e[32mGood by FdF\n\e[0m", 21);
	exit(0);
}

void	error_seq(char *str)
{
	char	*err;

	write(2, "fdf: ", 5);
	write(2, str, ft_strlen(str));
	err = strerror(errno);
	write(2, ": ", 2);
	write(2, err, ft_strlen(err));
	exit(1);
}

int	main(int ac, char *av[])
{
	t_info	info;

	if (ac != 2)
		return (1);
	init_info(&info, av[1]);
	info.ptr = mlx_get_data_addr(info.img, &(info.pixel),
			&(info.size), &(info.endian));
	isometric(&info);
	to_cen(&info, (info.pi)[(info.max_y - 1) / 2][(info.max_x - 1) / 2]);
	drawline(&info);
	mlx_hook(info.win, 02, 0, key_press, &info);
	mlx_hook(info.win, 17, 0, on_destroy, &info);
	mlx_put_image_to_window(info.mlx, info.win, info.img, 0, 0);
	mlx_loop(info.mlx);
	return (0);
}
