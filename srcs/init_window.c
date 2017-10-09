/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_window.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpatel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/15 02:23:33 by bpatel            #+#    #+#             */
/*   Updated: 2017/03/20 20:46:02 by bpatel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

void			set_pointer_function(t_window *window, int selection)
{
	if (selection == 1)
		window->func = draw_mandel;
	else if (selection == 2)
		window->func = draw_julia;
	else if (selection == 3)
		window->func = draw_random;
}

t_window		*init_window(int selection)
{
	t_window	*window;

	window = (t_window*)malloc(sizeof(t_window));
	window->w_height = W_HIT;
	window->w_width = W_LEN;
	window->mlx = mlx_init();
	window->win = mlx_new_window(window->mlx, window->w_width,
			window->w_height, "mlx 42");
	window->img = mlx_new_image(window->mlx, window->w_width, window->w_height);
	window->color = 0xf0fff0;
	window->scale = 20;
	window->zoom = 1;
	window->movex = 0;
	window->movey = 0;
	set_pointer_function(window, selection);
	return (window);
}

t_thread_data	*init_thread(t_window *window)
{
	t_thread_data *t;

	t = (t_thread_data*)ft_memalloc(sizeof(t_thread_data) * NUM_THREADS);
	t->pr = -.7;
	t->pi = .27015;
	t->newre = 0;
	t->oldre = 0;
	t->newimg = 0;
	t->oldimg = 0;
	t->env = window;
	return(t);
}