#include <pthread.h>
#include <semaphore.h>

typedef struct s_data
{
	long int time_to_die;
	int	time_to_sleep;
	int	times_to_eat;
	int	philos_n;
	int	many_times_to_eat;
	int	count_times_to_eat;
	sem_t *sem;
}	t_data;

typedef struct s_philo
{
	long int time_of_birth;
	long int time_of_death;
	int	many_times_to_eat;
	t_data data;
	int	eaten;
	int	ph_n;
} t_philo;


t_philo	*creat_philos(t_data data);

/**********     UTILS     **********/

long int	get_time(void);
void		argv_data(int argc, char **argv, t_data *data);
void    	ft_usleep(long duration);

/**********     ROUTINES     **********/

void		eating(t_philo *philo);
void		thiniking(t_philo philo);
void		sleeping(t_philo philo);
void		taken_a_fork(t_philo philo);
// void		*philo_eat(void *philo);

/**********     PARSING     **********/

void	exit_with_err(char *msg, int err_code);
t_philo	*creat_philos(t_data data);
