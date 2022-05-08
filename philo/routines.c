#include "philosopher.h"
#include <unistd.h>
#include <stdlib.h>
#include <pthread.h>
#include <stdio.h>

void	eating(t_philo *philo)
{
	long int	time;

	time = get_time();
	philo->time_of_death = time + philo->data.time_to_die;
	printf("%ld\t%d\teating\n", (time - philo->time_of_birth), philo->ph_n);
	ft_usleep(philo->data.times_to_eat);
}

void	thiniking(t_philo philo)
{
	long int	time;

	time = get_time();
	printf("%ld\t%d\tis thiniking\n", time - philo.time_of_birth, philo.ph_n);
}

void	sleeping(t_philo philo)
{
	long int	time;


	time = get_time();
	printf("%ld\t%d\tsleeping\n", time - philo.time_of_birth, philo.ph_n);
	ft_usleep(philo.data.time_to_sleep);
}
