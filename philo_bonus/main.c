#include "philosopher.h"
#include <unistd.h>
#include <stdlib.h>
#include <pthread.h>
#include <stdio.h>
#include <semaphore.h>

void	*philo_eat(void *philos)
{
	sem_t	*sem;
	t_philo	*philo;
	// int	sem_val;

	philo = (t_philo*)philos;
	// printf("got %d\n", philo->ph_n);
	sem = sem_open("/sem_forks", O_CREAT);
	philo->time_of_birth = get_time();
	philo->time_of_death = philo->time_of_birth + philo->data.time_to_die;
	if (philo->ph_n % 2 == 0)
		usleep(philo->data.times_to_eat * 1000);
	while (philo->many_times_to_eat >= 0 || philo->data.count_times_to_eat == 0)
	{
		thiniking(*philo);
		sem_wait(sem);
		// printf("hiiiiiii\n");
		taken_a_fork(*philo);
		sem_wait(sem);
		taken_a_fork(*philo);
		// printf("the sem: %d\n", sem_val);
		eating(philo);
		if (philo->data.count_times_to_eat == 1)
			philo->many_times_to_eat--;
		sem_post(sem);
		sem_post(sem);
		sleeping(*philo);
	}
	sem_close(sem);
	return (NULL);
}

int	main(int argc, char **argv)
{
	t_data	data;
	t_philo	*philos_data;
	sem_t	*sem;
	int		i;
	pthread_t philo_thread;

	i = 0;
	argv_data(argc, argv, &data);
	// printf("%d\n", data.philos_n);
	sem = sem_open("/sem_forks", O_CREAT, 0600, data.philos_n);
	// if (sem == )
	philos_data = creat_philos(data);
	while(i < philos_data->data.philos_n)
	{
		if (fork() == 0)
		{
			pthread_create(&philo_thread, NULL, &philo_eat, philos_data + i);
			pthread_join(philo_thread, NULL);
			exit(0);
			// philo_eat((void *) &philos_data[i], sem);
		}
		i++;
	}
	while (waitpid(-1, NULL, 0) > -1);
}
