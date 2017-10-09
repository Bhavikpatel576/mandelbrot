/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyhooks.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpatel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/15 16:05:18 by bpatel            #+#    #+#             */
/*   Updated: 2017/03/20 20:47:11 by bpatel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

#define ESC			53
#define UP			126
#define DOWN		125
#define RIGHT		124
#define LEFT		123
#define SHIFTRIGHT	2
#define SHIFTLEFT	0
#define SHIFTUP		13
#define SHIFTDOWN	1
#define ZOOMOUT		6
#define ZOOMIN		7

int		key_hooks(int keycode, t_thread_data *t)
{
	if (keycode == ESC)
		exit(0);
	else if (keycode == ZOOMIN)
		t->env->zoom += .2;
	else if (keycode == ZOOMOUT)
		t->env->zoom -= .2;
	else if (keycode == SHIFTUP)
		t->env->movey += .001;
	else if (keycode == SHIFTDOWN)
		t->env->movey -= .002;
	else if (keycode == SHIFTLEFT)
		t->env->movex += .002;
	else if (keycode == SHIFTRIGHT)
		t->env->movex -= .002;
	redraw(t);
	return (0);
}

int		motion_hook(int x, int y, t_thread_data *t)
{
	if (t->env->func == draw_julia || t->env->func == draw_random)
	{
		t->env->x = x;
		t->env->y = y;
		t->pr += -.001;
		t->pi += .001;
		redraw(t);
	}
	return (0);
}

int		mouse_scroll(int button, int x, int y, t_thread_data *t)
{
	if (button == 4)
		t->env->zoom -= 1;
	if (button == 5)
		t->env->zoom += 1;
	t->env->x = x;
	t->env->y = y;
	redraw(t);
	return (0);
}

void	run_fdf(t_thread_data *t)
{
	redraw(t);
	mlx_key_hook(t->env->win, key_hooks, t);
	mlx_mouse_hook(t->env->win, mouse_scroll, t);
	mlx_hook(t->env->win, 6, 0, motion_hook, t);
	mlx_loop(t->env->mlx);
}
