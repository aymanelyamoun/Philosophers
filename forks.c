#include "philosopher.h"
#include <unistd.h>
#include <stdlib.h>
#include <pthread.h>
#include <stdio.h>

void	take_his_fork(t_philo philo)
{
	long int time;

	time = get_time();
	printf("%ld\t%d\ttake a fork\n", time - philo.time_of_birth, philo.ph_n);
}

void	take_next_fork(t_philo philo)
{
	long int time;

	time = get_time();
	printf("%ld\t%d\ttake next fork\n", time - philo.time_of_birth, philo.ph_n);
}

void	take_left_fork(t_philo *philo)
{
	pthread_mutex_lock(philo[philo->n_ph_n].ph_fork);
	take_next_fork(*philo);
}

void	take_right_fork(t_philo *philo)
{
	pthread_mutex_lock(philo[0].ph_fork);
	take_his_fork(*philo);
}
