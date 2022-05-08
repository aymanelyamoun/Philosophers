#include "philosopher.h"
#include <unistd.h>
#include <stdlib.h>
#include <pthread.h>
#include <stdio.h>

void	*philos_eat(void	*philo_ptr)
{
	t_philo	*philo;

	philo = (t_philo *)philo_ptr;
	wait_all_philos(philo);
	philo->time_of_birth = get_time();
	philo->time_of_death = philo->time_of_birth + philo->data.time_to_die;
	if (philo->ph_n % 2 == 0)
		usleep(200);
	while ((philo->many_times_to_eat >= 0 && *(philo->finish) != 0)|| philo->data.count_times_to_eat == 0)
	{
			thiniking(*philo);
			take_left_fork(philo);
			take_right_fork(philo);
			eating(philo);
			if (philo->data.count_times_to_eat == 1)
			{
				philo->many_times_to_eat--;
				pthread_mutex_lock(philo->finish_mutex);
				*(philo->finish) -= 1;
				pthread_mutex_unlock(philo->finish_mutex);
			}
			pthread_mutex_unlock(philo[philo->n_ph_n].ph_fork);
			pthread_mutex_unlock(philo[0].ph_fork);
			sleeping(*philo);
	}
	return NULL;
}

pthread_t	*creat_threads(int	philos_n)
{
	pthread_t *philos;

	philos = malloc(sizeof(pthread_t) * philos_n);
	if (philos == NULL)
		exit_with_err("somthing wrong with malloc threads", 1);
	return (philos);
}

void	philosophers(t_data data, t_philo *philos_data, t_free to_free)
{
	pthread_t		*philos;
	int				i;

	i = 0;
	philos = creat_threads(data.philos_n);
	to_free.philos = philos;
	while (i < data.philos_n)
	{
		if (pthread_create(philos + i, NULL, &philos_eat, (philos_data) + i) != 0)
			exit_with_err("somthing went wrong with creating philo", 2);
		pthread_detach(philos[i]);
		i++;
	}
	check_death(philos_data, to_free);
}

int	main(int argc, char **argv)
{
	t_data			data;
	pthread_mutex_t	*mutexes;
	t_philo			*philos_data;
	t_free	to_free;

	argv_data(argc, argv, &data);
	mutexes = creat_fork_mutexes(data.philos_n);
	philos_data = creat_philos(data, &mutexes);
	to_free.philos_data = philos_data;
	philosophers(data, philos_data, to_free);
	return (0);
}
