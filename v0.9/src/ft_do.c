/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_do.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kboddez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/12 14:18:33 by kboddez           #+#    #+#             */
/*   Updated: 2016/10/23 13:35:34 by kboddez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/libfdf.h"

/*
**	CALCUL AND TRACE THE SQUELET OF FDF
*/

static void	ft_rise(t_graph *st, t_co *co)
{
	XF = X_ZRO + LX;
	if (HEIGHT != 0 && HEIGHT != P_HEIGHT)
		YF = Y_ZRO - (LY * HEIGHT);
	else if (HEIGHT == P_HEIGHT)
		YF = YI - LY;
	else if (P_HEIGHT > HEIGHT && CHECK == 0)
		YF = Y_ZRO + (LY * (P_HEIGHT - 1));
	else
		YF = Y_ZRO - LY;
	if (BUF[I - 1] != '\n' && I - 1 >= 0)
		ft_trace(co, COLOR, st);
}

/*
**	CALCUL AND TRACE THE DESCEND LINE
*/

static void	ft_descend(t_graph *st, t_co *co)
{
	XF = XI + LX;
	if (HEIGHT != N_HEIGHT)
	{
		if (N_HEIGHT != 0)
		{
			if (HEIGHT != 0)
				YF = (Y_ZRO + LY) - (LY * N_HEIGHT);
			else
				YF = (Y_ZRO + LX) - (LY * ++N_HEIGHT);
		}
		else
			YF = (Y_ZRO + LX) - LX;
	}
	else if (HEIGHT == N_HEIGHT)
		YF = YI + LY;
	else if (N_HEIGHT == 0)
		YF = (Y_ZRO + LY);
	ft_trace(co, COLOR, st);
}

void		ft_do(t_graph *st, t_co *co)
{
	HEIGHT = ft_height(st);
	N_HEIGHT = ft_next_height(st);
	if (I + L_LEN < L_BUF)
	{
		ft_rise(st, co);
		XI = XF;
		YI = YF;
	}
	if (I + L_LEN < L_BUF && I - 1 >= 0
		&& BUF[I - 1] != '\n')
		ft_descend(st, co);
	X_ZRO += LX;
	Y_ZRO -= LY;
	P_HEIGHT = HEIGHT;
}
