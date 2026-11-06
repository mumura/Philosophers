/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinsekan <jinsekan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/27 17:02:48 by jinsekan          #+#    #+#             */
/*   Updated: 2026/11/05 22:25:28 by jinsekan         ###   ########.fr       */
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
# include "libft.h"

# define ACTION_WAITING 1
# define ACTION_EATING 2
# define ACTION_SLEEPING 3
# define ACTION_THINKING 4

typedef struct s_philo		t_philo;
typedef struct s_fork_state	t_fork_state;

typedef struct s_share
{
	long long		philo_cnt;
	long long		must_eat;
	long long		time_to_die;
	long long		time_to_eat;
	long long		time_to_sleep;
}	t_share;

typedef struct s_state
{
	long long		start_time;
	long long		stop;// 1 실행중, 0 멈춤
	long long		full_count;
	t_philo			*oldest;
	t_fork_state	*fork_state;
	pthread_mutex_t	mx;
	pthread_mutex_t	print;
}	t_state;

struct s_philo
{
	long long		id;
	pthread_t		thread;
	long long		last_meal;
	long long		meal_cnt;
	long long		released;
	int				action;
	long long		think_end;
	pthread_mutex_t	meal;
	const t_share	*share;
	t_state			*state;
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*right_fork;
};

struct s_fork_state
{
	long long	owner;
	long long	eat_start;
};

typedef struct s_data
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

void		clean_forks(t_data *d);
void		clean_meal(t_data *d);
void		clean_state(t_data *d);
int			init_print(t_data *d);
void		clean_print(t_data *d);

int			init_fork_state(t_data *d);
void		free_fork_state(t_data *d);

void		free_forks(pthread_mutex_t **ph, long long len);
void		free_meal(t_philo *ph, long long len);
void		free_philo(t_data *d);

void		init_data(t_data *d);
int			init_forks(t_data *d);
int			init_meal(t_data *d);
int			init_state(t_data *d);
int			init_philos(t_data *d);

void		log_locked(t_philo *p, const char *action, long long now);
void		log_action(t_philo *p, const char *action);

int			start_philo(t_data *d);
int			with_resource(const t_resource *res, t_data *d);

long long	now_ms(void);
long long	get_wait_time(long long remaining, long long next_deadline);
long long	get_action_end(t_state *s, long long duration);
int			wait_until(t_state *s, long long end);
int			wait_ms(t_state *s, long long duration);

int			parse_arguments(int ac, char **av, t_data *data);

int			check_death(t_data *d);
int			monitor_philos(t_data *d);

void		update_meal_locked(t_philo *p, long long time);
long long	get_next_deadline(t_state *s, long long time_to_die);

int			create_philo(t_data *d);

void		release_forks(t_philo *p);
int			take_forks(t_philo *p);

int			join_philo(t_data *d, long long cnt);

int			record_meal_start(t_philo *p, long long *end);
void		finish_meal(t_philo *p);

int			eat_philo(t_philo *p);
int			sleep_philo(t_philo *p);
int			think_philo(t_philo *p);

void		*philo_routine(void *arg);

int			run_simulation(t_data *d);

int			is_stopped(t_state *s);
void		stop_simulation(t_state *s);
int			check_all_full(t_data *d);

long long	get_think_delay(t_philo *p);

void		set_action(t_philo *p, int action);
int		wait_think(t_philo *p, long long delay);
int		yield_think(t_philo *p);

long long manager_period(t_philo *p);
long long manager_seed(t_philo *p, long long period);
int manager_intervals(t_philo *p, long long period, long long now, long long blocked[4][2]);
int manager_thinking(t_philo *p, int initial);

#endif
