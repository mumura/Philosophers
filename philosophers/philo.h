/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinsekan <jinsekan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/27 17:02:48 by jinsekan          #+#    #+#             */
/*   Updated: 2026/11/05 21:35:21 by jinsekan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# ifndef MAX_LLONG
#  define MAX_LLONG 9223372036854775807
# endif
# ifndef MAX_SIZE
#  define MAX_SIZE 18446744073709551615ULL
# endif
# include <pthread.h>
# include <stdlib.h>
# include <stdint.h>
# include <sys/time.h>
# include <unistd.h>

typedef struct s_share
{
	long long		philo_cnt;
	long long		must_eat;
	long long		time_to_die;
	long long		time_to_eat;
	long long		time_to_sleep;
}	t_share;

typedef struct s_philo
{
	long long		id;
	pthread_t		thread;
	long long		last_meal;
	long long		meal_cnt;
	long long		released;
	long long		version;
	pthread_mutex_t	meal;
	const t_share	*share;
	t_state			*state;
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*right_fork;
}	t_philo;

typedef struct s_fork_state
{
	long long	owner;
	long long	eat_start;
}	t_fork_state;

typedef struct s_record
{
	t_philo			*philo;
	long long		time;
	long long		version;
	struct s_record	*next;
}	t_record;

typedef struct s_state
{
	long long		start_time;
	long long		stop;// 1 실행중, 0 멈춤
	long long		full_count;
	t_record		*head;
	t_record		*tail;
	t_fork_state	*fork_state;
	pthread_mutex_t	mx;
}	t_state;

struct s_data
{
	t_share			share;
	t_state			state;
	t_philo			*philo;
	pthread_mutex_t	*forks;
}	t_data;

typedef struct s_resource
{
	int		(*init)(t_data *);
	void	(*cleanup)(t_data *);
}	t_resource;

/* Recursive resource execution */

int			start_philo(t_data *d);
int			with_resource(const t_resource *res, t_data *d);

/* Simulation and threads */

int			run_simulation(t_data *d);
int			create_philo(t_data *d);
int			join_philo(t_data *d, long long cnt);
void		*philo_routine(void *arg);

/* Time management */

long long	now_ms(void);
long long	get_wait_time(long long remaining,
				long long next_deadline);
int			wait_ms(t_state *s, long long duration);

/* Simulation state */

int			is_stopped(t_state *s);
void		stop_simulation(t_state *s);
int			check_all_full(t_data *d);

/* Meal update queue */

int			push_meal(t_philo *p, long long time);
void		pop_stale(t_state *s);
long long	get_next_deadline(t_state *s, long long time_to_die);

/* Meal management */

int			record_meal_start(t_philo *p);
void		finish_meal(t_philo *p);

/* Fork management */

int			take_forks(t_philo *p);
void		release_forks(t_philo *p);

/* Action and scheduling */

long long	get_think_delay(t_philo *p);
int			eat_philo(t_philo *p);
int			sleep_philo(t_philo *p);
int			think_philo(t_philo *p);

/* Monitoring */

int			check_death(t_data *d);
int			monitor_philos(t_data *d);

/* Logging */

void		log_action(t_philo *p, const char *action);
void		log_locked(t_philo *p, const char *action, long long now);

#endif
