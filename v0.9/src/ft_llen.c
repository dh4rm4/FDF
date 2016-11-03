/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_llen.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kboddez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/09 11:59:43 by kboddez           #+#    #+#             */
/*   Updated: 2016/10/23 13:36:20 by kboddez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/libfdf.h"

/*
**	CALCULATES LENGTH OF ONE LINE OF BUF
*/

size_t	ft_llen(t_graph *st)
{
	int	len;

	len = 0;
	while (BUF[len] != '\n' && BUF[len])
		++len;
	return (len);
}
