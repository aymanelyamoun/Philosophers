/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   death.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-yamo <ael-yamo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 14:53:42 by ael-yamo          #+#    #+#             */
/*   Updated: 2022/05/10 16:59:35 by ael-yamo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <unistd.h>
#include <stdlib.h>
#include <pthread.h>
#include <stdio.h>

void	free_data(t_free to_free)
{
	int	i;

	i = 0;
	while (i < to_free.philos_data->data.philos_n)
	{
		pthread_mutex_destroy(to_free.philos_data[i].ph_fork);
		i++;
	}
	free(to_free.philos_data->ph_fork);
	free(to_free.philos_data->finish);
	free(to_free.philos_data->start);
	pthread_mutex_destroy(to_free.philos_data->finish_mutex);
	free(to_free.philos_data->finish_mutex);
	free(to_free.philos);
	free(to_free.philos_data);
	exit(0);
}

void	*check_death(t_philo *philos_data, t_free to_free)
{
	int			j;
	long int	time;

	while (*(philos_data->start) != 1)
		;
	usleep(philos_data->data.time_to_die * 990);
	while (1337)
	{
		if (*(philos_data->finish) == 0)
			free_data(to_free);
		j = 0;
		time = get_time();
		while (j < philos_data->data.philos_n)
		{
			if (time > philos_data[j].time_of_death)
			{
				printf("%ld\t%d\thas died\n", \
				time - philos_data[j].time_of_birth, philos_data[j].ph_n);
				free_data(to_free);
			}
			j++;
		}
	}
}
