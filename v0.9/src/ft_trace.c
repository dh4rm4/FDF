/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_trace.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kboddez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/12 13:40:53 by kboddez           #+#    #+#             */
/*   Updated: 2016/10/28 09:34:14 by kboddez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/libfdf.h"

static void	ft_pixel(int x, int y, int color, t_graph *st)
{
	int i;

	i = (SLINE * y) + (x * (BPP / 8));
	if (ENDIAN == 0)
	{
		ADDR[i] = mlx_get_color_value(MLX, color);
		ADDR[i + 1] = mlx_get_color_value(MLX, color >> 8);
		ADDR[i + 2] = mlx_get_color_value(MLX, color >> 16);
	}
	else
	{
		ADDR[i] = mlx_get_color_value(MLX, color >> 16);
		ADDR[i + 1] = mlx_get_color_value(MLX, color >> 8);
		ADDR[i + 2] = mlx_get_color_value(MLX, color);
	}
}

static void	ft_case_one(int color, t_graph *st, t_pixel *p)
{
	p->cumul = p->dx / 2;
	p->i = 0;
	while (++p->i <= p->dx)
	{
		p->x += p->xinc;
		p->cumul += p->dy;
		if (p->cumul >= p->dx)
		{
			p->cumul -= p->dx;
			p->y += p->yinc;
		}
		ft_pixel(p->x, p->y, color, st);
	}
}

static void	ft_case_two(int color, t_graph *st, t_pixel *p)
{
	p->cumul = p->dy / 2;
	p->i = 0;
	while (++p->i <= p->dy)
	{
		p->y += p->yinc;
		p->cumul += p->dx;
		if (p->cumul >= p->dy)
		{
			p->cumul -= p->dy;
			p->x += p->xinc;
		}
		ft_pixel(p->x, p->y, color, st);
	}
}

void		ft_trace(t_co *co, int color, t_graph *st)
{
	t_pixel	p;

	p.x = co->xi;
	p.y = co->yi;
	p.dx = co->xf - co->xi;
	p.dy = co->yf - co->yi;
	p.xinc = (p.dx > 0) ? 1 : -1;
	p.yinc = (p.dy > 0) ? 1 : -1;
	p.dx = abs(p.dx);
	p.dy = abs(p.dy);
	ft_pixel(co->xi, co->yi, color, st);
	if (p.dx > p.dy)
		ft_case_one(color, st, &p);
	else
		ft_case_two(color, st, &p);
}
