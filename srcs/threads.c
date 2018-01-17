/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpatel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/20 21:37:11 by bpatel            #+#    #+#             */
/*   Updated: 2017/03/20 21:38:14 by bpatel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

void				usage(void)
{
	ft_putendl("Select from the following options");
	ft_putendl("Select '1.' to output the Mandelbrot");
	ft_putendl("Select '2.' to output the Julia Set");
	ft_putendl("Select '3.' to output my secret sauce");
}

/*
** Code to have windows broken up amoung 16 quadrants
** threads[i].tid = i;
** threads[i].xO = window->w_width / 4 * (threads[i].tid % 4);
** threads[i].yO = window->w_height / 4 * (threads[i].tid / 4);
** threads[i].x1 = window->w_width / 4 * (threads[i].tid % 4) + WLEN;
** threads[i].y1 = window->w_height / 4 * (threads[i].tid / 4) + HLEN;
*/

int					run_threads(t_thread_data *t)
{
	pthread_t			thr[NUM_THREADS];
	int					i;
	int					rc;
	t_thread_data		*threads;

	threads = (t_thread_data*)ft_memalloc(sizeof(t_thread_data) * NUM_THREADS);
	i = -1;
	while (++i < NUM_THREADS)
	{
		threads[i].tid = i;
		threads[i].x0 = 0;
		threads[i].y0 = (W_HIT / (NUM_THREADS)) * i;
		threads[i].x1 = W_LEN;
		threads[i].y1 = (W_HIT / (NUM_THREADS)) * (i + 1);
		threads[i].pi = t->pi;
		threads[i].pr = t->pr;
		threads[i].env = t->env;
		if ((rc = pthread_create(&thr[i], NULL,
			(void*)threads->env->func, &(threads[i]))))
			return (EXIT_FAILURE);
	}
	i = -1;
	while (++i < NUM_THREADS)
		pthread_join(thr[i], NULL);
	free(threads);
	return (EXIT_SUCCESS);
}
