#include <pthread.h>

typedef struct s_data
{
	long int time_to_die;
	int	time_to_sleep;
	int	times_to_eat;
	int	philos_n;
	int	many_times_to_eat;
	int	count_times_to_eat;
}	t_data;

typedef struct s_philo
{
	pthread_mutex_t	*ph_fork;
	pthread_mutex_t *finish_mutex;
	long int time_of_birth;
	long int time_of_death;
	int	many_times_to_eat;
	t_data data;
	int	eaten;
	int	ph_n;
	int	n_ph_n;	
	int	*start;
	int	*finish;
} t_philo;

typedef struct s_free
{
	pthread_t *philos;
	t_philo *philos_data;
}	t_free;
/********     PARSING    ********/

pthread_mutex_t		*creat_fork_mutexes(int phelos_n);
t_philo				*creat_philos(t_data data, pthread_mutex_t **mutex);

/********     DEATH      *********/

void				free_data(t_free to_free);
void				*check_death(t_philo *philos_data, t_free to_free);

/*********     ROUTINES    *********/

void				eating(t_philo *philo);
void				thiniking(t_philo philo);
void				sleeping(t_philo philo);

/********     FORKS     **********/

void				take_his_fork(t_philo philo);
void				take_next_fork(t_philo philo);
void				take_left_fork(t_philo *philo);
void				take_right_fork(t_philo *philo);
/*********     MAIN      *********/
void				*philos_eat(void	*philo_ptr);
pthread_t			*creat_threads(int	philos_n);
void				philosophers(t_data data, t_philo *philos_data, t_free to_free);

/* ********     UTILS     ******** */
long int			get_time(void);
void				exit_with_err(char *msg, int err_code);
void				argv_data(int argc, char **argv, t_data *data);
void    			ft_usleep(long duration);
void				wait_all_philos(t_philo *philo);
