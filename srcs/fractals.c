/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractals.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpatel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/15 02:23:33 by bpatel            #+#    #+#             */
/*   Updated: 2017/03/20 20:46:02 by bpatel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

void				draw_mandel(void *arg)
{
	int				iter;
	int				old_x0;
	t_thread_data	*t;

	t = (t_thread_data*)arg;
	old_x0 = t->x0;
	while (t->y0 < t->y1)
	{
		t->x0 = old_x0;
		while (t->x0 < t->x1)
		{
			t->pi = (t->y0 - W_HIT / 2) /
				(.5 * t->env->zoom * W_HIT) + t->env->movey;
			t->pr = 1.5 * (t->x0 - W_LEN / 2) /
				(.5 * t->env->zoom * W_LEN) + t->env->movex;
			t->newre = 0;
			t->oldre = 0;
			t->newimg = 0;
			t->oldimg = 0;
			iter = bd_iter_1(t->pi, t->pr);
			t->env->pixel_data[t->x0++ + (t->y0 * W_LEN)] = color_type(iter);
		}
		t->y0++;
	}
}

void				draw_julia(void *arg)
{
	int				iter;
	int				old_x0;
	t_thread_data	*t;

	t = (t_thread_data*)arg;
	old_x0 = t->x0;
	while (t->y0 < t->y1)
	{
		t->x0 = old_x0;
		while (t->x0 < t->x1)
		{
			t->newimg = (t->y0 - W_HIT / 2) /
				(.5 * t->env->zoom * W_HIT) + t->env->movey;
			t->newre = 1.5 * (t->x0 - W_LEN / 2) /
				(.5 * t->env->zoom * W_LEN) + t->env->movex;
			iter = bd_iter_2(*(t), t->pi, t->pr);
			t->env->pixel_data[t->x0++ + (t->y0 * W_LEN)] = color_type(iter);
		}
		t->y0++;
	}
}

void				draw_random(void *arg)
{
	int				iter;
	int				old_x0;
	t_thread_data	*t;

	t = (t_thread_data*)arg;
	old_x0 = t->x0;
	while (t->y0 < t->y1)
	{
		t->x0 = old_x0;
		while (t->x0 < t->x1)
		{
			t->newimg = (t->y0 - W_HIT / 2) /
				(.5 * t->env->zoom * W_HIT) + t->env->movey;
			t->newre = 1.5 * (t->x0 - W_LEN / 2) /
				(.5 * t->env->zoom * W_LEN) + t->env->movex;
			iter = bd_iter_2(*(t), t->pr, t->pi);
			t->env->pixel_data[t->x0++ + (t->y0 * W_LEN)] = color_type(iter);
		}
		t->y0++;
	}
}
