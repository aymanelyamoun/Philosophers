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

#include <stdio.h>
t_philo	*creat_philos(t_data data)
{
	t_philo	*philos;
	int		ph;

	ph = 0;
	philos = malloc(sizeof(t_philo) * data.philos_n);
	if (philos == NULL)
		exit_with_err("somthing wrong with malloc philos", 1);
	while (ph < data.philos_n)
	{
		philos[ph].eaten = 0;
		philos[ph].data = data;
		philos[ph].ph_n = ph + 1;
		philos[ph].many_times_to_eat = data.many_times_to_eat - 1;
		// if (fork() == 0)
		// 	philo_eat(&philos[ph]);
		ph++;
	}
	return (philos);
}
