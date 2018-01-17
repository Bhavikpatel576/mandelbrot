# Mandelbrot
The Mandelbrot set is a set of complex numbers (denoted at c) for which the function {\displaystyle f_{c}(z)=z^{2}+c} does not diverge when enumerated on from z = 0 to z -> ∞.

## Program Preview
<img src="http://www.bhavik-patel.com/assets/Fractal2.gif" width=30% height=30%>

## Description
At the core of the program, each pixel is configured to be on a point within the complex plane and then run against the escape time algorithm to determine if the point converges or diverges. Each event is represented by a partiuclar color. The former being a value between 0-255 RBG decimal value dependent on the number of iterations to convergence, and the latter being color 0 (black). 

## Installation and Usage
If you're running a UNIX environment, clone the repo, run 'Make' in your command line, and then execute ./frac to get the usage options of the program

![Alt Text](https://github.com/Bhavikpatel576/mandelbrot/blob/master/assets/usage_sh.png)

## Details and Code
The program leverages the MinilibX library in order create graphics renderings. Upon user selection the program initializes a window leveraging teh MinilibX library and populates a struct with default values for the window (for example, the size of the window). Upon initialization a pointer function is set based off the users input to run the specific escape time algorithm for it's corresponding fractal. 

An infinite loop is run to monitor user's keyhooks and to re-render the image based of the response. 
```
void	run_fdf(t_thread_data *t)
{
	redraw(t);
	mlx_key_hook(t->env->win, key_hooks, t);
	mlx_mouse_hook(t->env->win, mouse_scroll, t);
	mlx_hook(t->env->win, 6, 0, motion_hook, t);
	mlx_loop(t->env->mlx);
}
```

Each pixel is mapped to the the complex coordinate via pi or pr and run through the escape time algorithm to deterime if the value converges or diverges. The max iterations is hard coded to 350. 
```
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
```

Threading: in order to optimize the program, p_threads were used to split up the computational workload of the program. Each thread works on a section of the window.
```

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
  ...

```

## Author
Bhavik Patel

## Acknowledgement 
This project was completed at School 42 in Fremont, California.
