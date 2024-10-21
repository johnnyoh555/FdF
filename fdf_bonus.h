/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_bonus.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jooh <jooh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 12:15:30 by jooh              #+#    #+#             */
/*   Updated: 2023/11/28 16:00:13 by jooh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_BONUS_H
# define FDF_BONUS_H

# include <mlx.h>
# include <math.h>
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <errno.h>

# include "./libft/libft.h"
# include "./libft/get_next_line.h"

typedef struct s_point
{
	float	x;
	float	y;
	float	z;
	float	mx;
	float	my;
	float	mz;
	float	px;
	float	py;
	int		color;
}	t_point;

typedef struct s_info
{
	double	mpi18;
	double	mpi6;
	int		max_y;
	int		max_x;
	int		dis;
	void	*mlx;
	void	*win;
	void	*img;
	char	*ptr;
	int		to_cen_x;
	int		to_cen_y;
	int		move_x;
	int		move_y;
	int		pixel;
	int		size;
	int		endian;
	int		xspin;
	int		yspin;
	int		aftimg;
	t_point	***pi;
}	t_info;

// main.c
void	error_seq(char *str);
void	free_vector(t_info *info);
int		on_destroy(int i, t_info *info);

// drawline.c
void	drawline(t_info *info);
void	bresenham(t_info *info, t_point pi1, t_point pi2);
void	underline(t_info *info, t_point *pi1, t_point *pi2, int minus);
void	upperline(t_info *info, t_point *pi1, t_point *pi2, int minus);

// convert.c
int		convert_base(char *str);
int		checkstr(char str, char *base);

// parsing.c
void	init_info(t_info *info, char *mapname);
void	check_y(t_info *info, char *mapname);
t_point	**check_x(t_info *info, int fd, int y);
t_point	*point_info(char *arr, int x, int y);
void	ft_free(char **arr);

// isometric.c
void	isometric(t_info *info);
void	calc_isometric(t_info *info, t_point *p);
void	to_cen(t_info *info, t_point *p);
void	zoom_io(t_info *info, t_point *p);

// colors.c
int		cha_color(int color1, int color2, float x);
int		create_trgb(int t, int r, int g, int b);
int		get_t(int trgb);
int		get_r(int trgb);
int		get_g(int trgb);
int		get_b(int trgb);

// hooks.c
int		key_press(int keycode, t_info *info);
void	del_screen(t_info *info);

// spinning.c
void	spinning_byx(t_info *info);
void	calc_spinning_byx(t_info *info, t_point *p);
void	spinning_byy(t_info *info);
void	calc_spinning_byy(t_info *info, t_point *p);

// spinhooks.c
void	spin_byx(t_info *info);
void	spin_byy(t_info *info);
void	from_back(t_info *info);
void	from_front(t_info *info);

// init.c
void	init_spin(t_info *info);
void	init_header(t_info *info, int k);
void	ppt(t_info *info);
void	front(t_info *info);
void	init_header_info(t_info *info);

#endif