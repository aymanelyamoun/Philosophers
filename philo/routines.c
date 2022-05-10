/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routines.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-yamo <ael-yamo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 15:12:26 by ael-yamo          #+#    #+#             */
/*   Updated: 2022/05/10 16:56:32 by ael-yamo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
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
