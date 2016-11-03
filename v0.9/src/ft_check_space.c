/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_space.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kboddez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/20 15:46:29 by kboddez           #+#    #+#             */
/*   Updated: 2016/10/24 11:31:42 by kboddez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/libfdf.h"

/*
**	CHECK IF THE DISTANCE LX AND LY ARE VALIDS
*/

int				ft_check_space(int n_line, int n_col, int h_max, t_graph *st)
{
	if ((n_col + n_line) * LX > SIZE_LINE ||
		(n_col + n_line + h_max) * LY > SIZE_COL)
	{
		LX -= 2;
		--LY;
		ft_start_coord(n_line, n_col, st);
		if (LX != 2 && LY != 1)
			return (ft_check_space(n_line, n_col, h_max, st));
	}
	ft_start_coord(n_line, n_col, st);
	return (0);
}
