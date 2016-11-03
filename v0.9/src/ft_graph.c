/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_graph.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kboddez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/05 10:27:24 by kboddez           #+#    #+#             */
/*   Updated: 2016/10/31 12:25:45 by kboddez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/libfdf.h"

static int	ft_heightb(t_graph *st)
{
	int height;
	int i;

	height = 0;
	i = I;
	while (BUF[i] >= '0' && BUF[i] <= '9' && BUF[i])
	{
		height = height * 10 + (BUF[i] - '0');
		++i;
	}
	--i;
	return (height * 3);
}

static void	ft_dimension_ii(t_graph *st, int i, int y, int h_max)
{
	i += 2;
	y += 2;
	y = (y == 0) ? 1 : y;
	if (y == 0)
		++y;
	SIZE_COL = ((i * LX) + (y * LY) + (h_max * 5)) * 2;
	SIZE_LINE = (i * LX + y * LY + h_max) * 2;
	if (SIZE_COL > 1440)
		SIZE_COL = 1440;
	if (SIZE_LINE > 2560)
		SIZE_LINE = 2560;
	X_STRT_MEM = SIZE_LINE / 30;
	Y_STRT_MEM = SIZE_COL - (SIZE_COL / 10);
	ft_start_coord(i, y, st);
	ft_check_space(i, y, --h_max, st);
}

/*
**	FIND THE DIMENSION OF THE IMAGE/WINDOW
*/

static void	ft_dimension(t_graph *st)
{
	int	i;
	int	y;
	int	h_max;

	i = -1;
	y = 0;
	h_max = 0;
	I = 0;
	while (BUF[I] != '\n' && BUF[I])
	{
		if (ft_isdigit(BUF[I]) == 1 &&
			(BUF[I + 1] == ' ' || BUF[I + 1] == '\n' || BUF[I + 1] == '\0'))
			++i;
		++I;
	}
	I = -1;
	while (BUF[++I])
	{
		if (BUF[I] == '\n')
			++y;
		if (ft_isdigit(BUF[I]) == 1 && ft_heightb(st) > h_max)
			h_max = ft_heightb(st);
	}
	ft_dimension_ii(st, i, y, h_max);
}

/*
**	MANAGE KEY EVENT
*/

static int	ft_key(int keycode, t_graph *st)
{
	if (keycode == 53)
		exit(0);
	else if (keycode == 18)
		COLOR = 0x216A12;
	else if (keycode == 19)
		COLOR = 0xD4D16A;
	else if (keycode == 20)
		COLOR = 0x7E1518;
	if (keycode == 18 || keycode == 19 || keycode == 20)
	{
		IMG = mlx_new_image(MLX, SIZE_LINE, SIZE_COL);
		ADDR = mlx_get_data_addr(IMG, &BPP, &SLINE, &ENDIAN);
		ft_map(st);
		mlx_put_image_to_window(MLX, WIN, IMG, 0, 0);
		mlx_destroy_image(MLX, ADDR);
	}
	return (0);
}

/*
**	BEGIN THE GRAPH ENVIRONMENT
**	+ Xserver
**	+ Xclient
*/

int			ft_graph(t_graph *st)
{
	ft_check(BUF);
	BPP = 24;
	LX = 15;
	LY = 7;
	SLINE = 0;
	COLOR = 0xFFFFFF;
	ft_dimension(st);
	ENDIAN = 0;
	MLX = mlx_init();
	WIN = mlx_new_window(MLX, SIZE_LINE, SIZE_COL, "fdf");
	IMG = mlx_new_image(MLX, SIZE_LINE, SIZE_COL);
	ADDR = mlx_get_data_addr(IMG, &BPP, &SLINE, &ENDIAN);
	ft_map(st);
	mlx_put_image_to_window(MLX, WIN, IMG, 0, 0);
	mlx_destroy_image(MLX, WIN);
	mlx_key_hook(WIN, ft_key, st);
	mlx_hook(WIN, 17, 1L << 17, ft_exit, 0);
	mlx_loop(MLX);
	return (0);
}
