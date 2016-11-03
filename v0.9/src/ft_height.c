/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_heigth.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kboddez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/09 12:01:26 by kboddez           #+#    #+#             */
/*   Updated: 2016/10/23 13:36:09 by kboddez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/libfdf.h"

/*
**	CALCULATE THE HEIGHT
*/

int	ft_height(t_graph *st)
{
	int	height;

	height = 0;
	while (BUF[I] >= '0' && BUF[I] <= '9' && BUF[I])
	{
		height = height * 10 + (BUF[I] - '0');
		++I;
	}
	if (I - 2 >= 0)
		--I;
	return (height * 3);
}
