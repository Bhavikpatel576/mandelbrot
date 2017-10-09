/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpatel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/20 21:37:11 by bpatel            #+#    #+#             */
/*   Updated: 2017/03/20 21:38:14 by bpatel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

int					main(int argc, char **argv)
{
	t_window		*window;
	t_thread_data 	*t;
	int				selection;

	if (argc < 2)
	{
		usage();
		exit(0);
	}
	selection = ft_atoi(argv[1]);
	window = init_window(selection);
	t = init_thread(window);
	run_fdf(t);
	free(t);
	return (0);
}
