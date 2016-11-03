/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kboddez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/22 10:36:40 by kboddez           #+#    #+#             */
/*   Updated: 2016/10/28 09:34:24 by kboddez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/libfdf.h"

static int	ft_height_bis(t_graph *st)
{
	int height;
	int i;

	i = I;
	height = 0;
	while (BUF[i] >= '0' && BUF[i] <= '9' && BUF[i])
	{
		height = height * 10 + (BUF[i] - '0');
		++i;
	}
	return (height * 3);
}

static void	ft_start_column(t_graph *st, t_co *co)
{
	if (ft_height_bis(st) == 0)
	{
		++CHECK;
		P_HEIGHT = 0;
		XI = X_STRT;
		YI = Y_STRT;
		X_ZRO = X_STRT;
		Y_ZRO = Y_STRT;
	}
	else if (ft_height_bis(st) != 0)
	{
		++CHECK;
		P_HEIGHT = ft_height_bis(st);
		XI = X_STRT;
		YI = Y_STRT - (ft_height_bis(st) * LY);
		X_ZRO = X_STRT;
		Y_ZRO = Y_STRT - (ft_height_bis(st) * LY);
	}
}

static void	ft_initialisation(t_co *co, t_graph *st)
{
	H_CUR = 0;
	X_STRT = X_STRT_MEM;
	Y_STRT = Y_STRT_MEM;
	I = -1;
	L_BUF = ft_strlen(BUF);
	L_LEN = 0;
	CHECK = -1;
	while (BUF[L_LEN] != '\n' && BUF[L_LEN])
		++L_LEN;
}

void		ft_map(t_graph *st)
{
	t_co	co;

	ft_initialisation(&co, st);
	while (BUF[++I])
	{
		if (I == 0 || BUF[I - 1] == '\n')
			ft_start_column(st, &co);
		if (BUF[I] >= '0' && BUF[I] <= '9' && BUF[I - 1] != '\n' && I != 0)
		{
			ft_do(st, &co);
			++CHECK;
		}
		else if (BUF[I] == '\n')
		{
			X_STRT += LX;
			Y_STRT += LY;
		}
		if ((BUF[I - 1] == '\n' || I - 1 == 0) && co.p_height != 0)
			co.y_zro += (ft_height_bis(st) * LY);
	}
}
