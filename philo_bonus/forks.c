#include "philosopher.h"
#include <unistd.h>
#include <stdlib.h>
#include <pthread.h>
#include <stdio.h>

void	taken_a_fork(t_philo philo)
{
	long int time;

	time = get_time();
	printf("%ld\t%d\ttake a fork\n", time - philo.time_of_birth, philo.ph_n);
}
