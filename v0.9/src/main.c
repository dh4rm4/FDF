/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kboddez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/12 13:31:25 by kboddez           #+#    #+#             */
/*   Updated: 2016/10/23 17:35:28 by kboddez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/libfdf.h"

int	main(int argc, char *argv[])
{
	if (argc == 2)
		ft_start(argv[1], 0, 0, -1);
	return (0);
}
