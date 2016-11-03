/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_next_height.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kboddez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/13 11:25:42 by kboddez           #+#    #+#             */
/*   Updated: 2016/10/23 13:36:51 by kboddez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/libfdf.h"

int	ft_next_height(t_graph *st)
{
	int	i;
	int	rtr;

	i = I + L_LEN + 1;
	rtr = 0;
	while (BUF[i] == ' ')
		++i;
	while (I - 1 >= 0 && BUF[i - 1] >= '0' && BUF[i - 1] <= '9')
		--i;
	while (BUF[i] >= '0' && BUF[i] <= '9')
	{
		rtr = rtr * 10 + (BUF[i] - '0');
		++i;
	}
	return (rtr * 3);
}
