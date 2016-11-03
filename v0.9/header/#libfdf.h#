/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libfdf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kboddez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/05 10:21:17 by kboddez           #+#    #+#             */
/*   Updated: 2016/10/28 09:48:02 by kboddez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFDF_H
# define LIBFDF_H
# define MLX st->mlx
# define WIN st->win
# define IMG st->img
# define ADDR st->addr
# define SIZE_LINE st->size_line
# define SIZE_COL st->size_column
# define BPP st->bits_per_pixel
# define ENDIAN st->endian
# define BUF st->buf
# define I st->i
# define L_LEN st->l_len
# define L_BUF st->l_buf
# define X_BEF co->x_bef
# define Y_BEF co->y_bef
# define XI co->xi
# define YI co->yi
# define XF co->xf
# define YF co->yf
# define SLINE st->sline
# define X_NXT co->x_next
# define Y_NXT co->y_nxt
# define X_ZRO co->x_zro
# define Y_ZRO co->y_zro
# define HEIGHT co->height
# define N_HEIGHT co->n_height
# define P_HEIGHT co->p_height
# define LX st->lx
# define LY st->ly
# define X_STRT st->x_start
# define Y_STRT st->y_start
# define X_STRT_MEM st->x_strt_mem
# define Y_STRT_MEM st->y_strt_mem
# define COLOR st->color
# define CHECK st->check
# define H_CUR co->h_cur
# include "../libft/libft.h"
# include "mlx.h"
# include <fcntl.h>

typedef struct	s_graph
{
	void		*mlx;
	void		*win;
	void		*img;
	char		*addr;
	int			size_line;
	int			size_column;
	int			bits_per_pixel;
	int			endian;
	int			color;
	int			lx;
	int			ly;
	int			x_start;
	int			y_start;
	int			x_strt_mem;
	int			y_strt_mem;
	int			i;
	int			l_len;
	int			l_buf;
	char		*buf;
	int			sline;
	int			check;
}				t_graph;

typedef struct	s_co
{
	int			x_bef;
	int			y_bef;
	int			xi;
	int			yi;
	int			xf;
	int			yf;
	int			x_nxt;
	int			y_nxt;
	int			x_zro;
	int			y_zro;
	int			height;
	int			n_height;
	int			p_height;
	int			h_cur;
}				t_co;

typedef struct	s_coord
{
	int			x;
	int			y;
}				t_coord;

typedef struct	s_pixel
{
	int			dx;
	int			dy;
	int			i;
	int			xinc;
	int			yinc;
	int			cumul;
	int			x;
	int			y;
}				t_pixel;

int				ft_start(char *file, int fd1, int fd2, int error);
int				ft_graph(t_graph *st);
void			ft_map(t_graph *st);
void			ft_trace(t_co *co, int color, t_graph *st);
int				ft_height(t_graph *st);
void			ft_do(t_graph *st, t_co *co);
size_t			ft_llen(t_graph *st);
int				ft_next_height(t_graph *st);
int				ft_check_space(int n_line, int n_col, int h_max, t_graph *st);
int				ft_start_coord(int n_line, int n_col, t_graph *st);
int				ft_exit(int i);
void			ft_check(char *str);

#endif
