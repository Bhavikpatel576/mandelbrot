/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpatel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/09 17:58:37 by bpatel            #+#    #+#             */
/*   Updated: 2017/03/22 16:42:19 by bpatel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include <libft.h>
# include <stdio.h>
# include <mlx.h>
# include <fcntl.h>
# include <math.h>
# include <pthread.h>

# define W_HIT 500
# define W_LEN 500
# define NUM_THREADS 10
# define MAX_ITERATIONS 350
# define WLEN window->w_width / 4
# define HLEN window->w_height / 4

typedef	struct			s_window
{
	int					w_height;
	int					w_width;
	void				*mlx;
	void				*win;
	void				*img;
	int					size_line;
	unsigned int		*pixel_data;
	int					color;
	float				scale;
	int					zoom;
	float				movey;
	float				movex;
	void				(*func)(void *arg);
	int					x;
	int					y;
}						t_window;

typedef	struct			s_thread_data
{
	int					tid;
	int					x0;
	int					x1;
	int					y0;
	int					y1;
	double				pr;
	double				pi;
	double				newre;
	double				oldre;
	double				newimg;
	double				oldimg;
	t_window			*env;
}						t_thread_data;

void					redraw(t_thread_data *t);
t_window				*init_window(int selection);
t_thread_data			*init_thread(t_window *window);
int						my_key_funct(int keycode, void *param);
void					run_fdf(t_thread_data *t);
void					draw_to_image(t_window *window);
int						run_threads(t_thread_data *t);
unsigned int			color_type(int iteration);
int						bd_iter_1(double pi, double pr);
int						bd_iter_2(t_thread_data temp, double pi, double pr);
void					draw_julia(void *arg);
void					draw_mandel(void *arg);
void					draw_random(void *arg);
void					usage(void);

#endif
