/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_start_coord.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kboddez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/21 09:40:22 by kboddez           #+#    #+#             */
/*   Updated: 2016/10/23 13:37:35 by kboddez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/libfdf.h"

int	ft_start_coord(int n_line, int n_col, t_graph *st)
{
	int	y;

	y = Y_STRT_MEM + (n_line * LY);
	if (y > SIZE_COL)
	{
		if (y - SIZE_COL > 750)
		{
			LX -= 2;
			--LY;
		}
		Y_STRT_MEM -= 25;
		return (ft_start_coord(n_line, n_col, st));
	}
	else if (y < (SIZE_COL / 20))
	{
		Y_STRT_MEM += 25;
		return (ft_start_coord(n_line, n_col, st));
	}
	return (0);
}
