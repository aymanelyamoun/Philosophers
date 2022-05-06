#include "philosopher.h"
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
// err codes;
// 1 allocation problem
// 2 system request problem
// other

void	exit_with_err(char *msg, int err_code)
{
	write(2, msg, strlen(msg));
	exit(err_code);
}

// void	protect_mallocation(void *add)
// {
// 	if (add == NULL)
		
// }
pthread_mutex_t	*creat_fork_mutexes(int phelos_n)
{
	int	i;
	pthread_mutex_t	*mutexes;

	i = 0;
	mutexes = malloc(sizeof(pthread_mutex_t) * phelos_n);
	if (mutexes == NULL)
		exit_with_err("somthing wrong with malloc mutexes", 1);
	while (i < phelos_n)
	{
		pthread_mutex_init((mutexes + i), NULL);
		i++;
	}
	return (mutexes);
}
#include <stdio.h>
t_philo	*creat_philos(t_data data, pthread_mutex_t **mutex)
{
	t_philo	*philos;
	int				ph;
	int				*start;
	int				*finish;
	pthread_mutex_t	*finish_mutex;

	ph = 0;
	philos = malloc(sizeof(t_philo) * data.philos_n);
	start = malloc(sizeof(int));
	finish = malloc(sizeof(int));
	finish_mutex = malloc(sizeof(pthread_mutex_t));
	*start = 0;
	*finish = data.many_times_to_eat * data.philos_n;
	pthread_mutex_init(finish_mutex, NULL);
	if (philos == NULL)
		exit_with_err("somthing wrong with malloc philos", 1);
	while (ph < data.philos_n)
	{
		philos[ph].eaten = 0;
		philos[ph].ph_fork = (*mutex) + ph;
		philos[ph].ph_n = ph + 1;
		if (ph + 1 == data.philos_n)
			philos[ph].n_ph_n = -(data.philos_n - 1);
		else	
			philos[ph].n_ph_n = 1;
		philos[ph].data = data;
		philos[ph].start = start;
		philos[ph].finish = finish;
		philos[ph].finish_mutex = finish_mutex;
		philos[ph].many_times_to_eat = data.many_times_to_eat - 1;
		ph++;
	}
	return (philos);
}
