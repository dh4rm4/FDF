/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_start.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kboddez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/23 14:01:51 by kboddez           #+#    #+#             */
/*   Updated: 2016/10/28 09:39:36 by kboddez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/libfdf.h"

static char	*ft_strcatb(char *s1, const char *s2)
{
	int	s1_i;
	int	s2_i;

	s1_i = 0;
	s2_i = 0;
	while (s1[s1_i] != '\0')
		s1_i++;
	while (s2[s2_i] != '\0')
	{
		s1[s1_i + s2_i] = s2[s2_i];
		s2_i++;
	}
	s1[s1_i + s2_i] = '\n';
	return (s1);
}

/*
**	STORE THE THE MAP in buf
*/

int			ft_start(char *file, int fd1, int fd2, int error)
{
	char	*str;
	t_graph	*st;
	int		size;

	size = 0;
	str = (char*)malloc(sizeof(*str));
	fd1 = open(file, O_RDONLY);
	if (fd1 == error)
		return (error);
	while (read(fd1, str, 1) > 0)
		++size;
	fd2 = open(file, O_RDONLY);
	if (close(fd1) == error || fd2 == error)
		return (error);
	st = (t_graph*)malloc(sizeof(*st));
	BUF = ft_strnew(++size);
	while (get_next_line(fd2, &str) == 1)
	{
		ft_strcatb(BUF, str);
		free(str);
	}
	if (BUF[0] == '\0' || close(fd2) == error)
		return (error);
	ft_graph(st);
	return (0);
}
