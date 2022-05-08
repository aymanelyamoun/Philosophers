#include "philosopher.h"
#include <unistd.h>
#include <pthread.h>
#include <stdio.h>
#include <sys/time.h>
#include <stdlib.h>

long int get_time(void)
{
	struct timeval	time;

	if (gettimeofday(&time, NULL) == -1)
		exit_with_err("problem with gettimeofday\n", 2);
	return (time.tv_sec * 1000) + (time.tv_usec / 1000);
}

void	argv_data(int argc, char **argv, t_data *data)
{
	if (argc == 5 || argc == 6)
	{
		data->philos_n = atoi(argv[1]);
		data->sem = sem_open("/sem_forks", O_CREAT, 0600, data->philos_n);
		data->time_to_die = atoi(argv[2]);
		data->time_to_sleep = atoi(argv[3]);
		data->times_to_eat = atoi(argv[4]);
		data->many_times_to_eat = -1;
		data->count_times_to_eat = 0;
		if (argc == 6)
		{
			data->count_times_to_eat = 1;
			data->many_times_to_eat = atoi(argv[5]);
		}
	}

	else
		exit_with_err("somthing worong with the arguments", 3);
}

void    ft_usleep(long duration)
{
    long            start;

    start = get_time();
    while (get_time() - start < duration)
        usleep(100);
}
