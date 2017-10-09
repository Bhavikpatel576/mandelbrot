/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpatel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/15 01:42:14 by bpatel            #+#    #+#             */
/*   Updated: 2017/03/15 01:42:16 by bpatel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>
#include <math.h>

unsigned	int				color_type(int iteration)
{
	//4 bytes
	unsigned int			color;
	//1 byte
	unsigned char			r;
	unsigned char			g;
	unsigned char			b;

	r = 255;
	g = 255;
	b = 255;
	if (iteration == MAX_ITERATIONS)
	{
		r = 0;
		g = 0;
		b = 0;
	}
	else
	{
		while (iteration--)
		{
			r -= 15;
			g -= 0;
			b -= 5;
		}
	}
	color = (r << 16) + (g << 8) + (b << 0);
	return (color);
}

void						draw_to_image(t_window *window)
{
	int						bpp;
	int						endian;
	int						size_line;

	bpp = 0;
	endian = 0;
	size_line = window->w_height;
	window->pixel_data = (unsigned int*)mlx_get_data_addr(window->img,
		&bpp, &size_line, &endian);
}

int							bd_iter_2(t_thread_data temp, double pi, double pr)
{
	int						iter;

	iter = -1;
	while (++iter < MAX_ITERATIONS)
	{
		temp.oldre = temp.newre;
		temp.oldimg = temp.newimg;
		temp.newre = temp.oldre * temp.oldre - temp.oldimg * temp.oldimg + pr;
		temp.newimg = 2 * temp.oldre * temp.oldimg + pi;
		if ((temp.newre * temp.newre) + (temp.newimg * temp.newimg) > 4)
			break ;
	}
	return (iter);
}

int							bd_iter_1(double pi, double pr)
{
	t_thread_data			temp;
	int						iter;

	iter = -1;
	temp.newre = 0;
	temp.newimg = 0;
	while (++iter < MAX_ITERATIONS)
	{
		temp.oldre = temp.newre;
		temp.oldimg = temp.newimg;
		temp.newre = temp.oldre * temp.oldre - temp.oldimg * temp.oldimg + pr;
		temp.newimg = 2 * temp.oldre * temp.oldimg + pi;
		if ((temp.newre * temp.newre) + (temp.newimg * temp.newimg) > 4)
			break ;
	}
	return (iter);
}

void						redraw(t_thread_data *t)
{
	draw_to_image(t->env);
	mlx_clear_window(t->env->mlx, t->env->win);
	run_threads(t);
	mlx_put_image_to_window(t->env->mlx, t->env->win,
		t->env->img, t->env->zoom, 0);
}
