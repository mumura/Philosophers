/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinsekan <jinsekan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/27 17:02:48 by jinsekan          #+#    #+#             */
/*   Updated: 2026/11/05 14:18:13 by jinsekan         ###   ########.fr       */
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

typedef struct s_share	t_share;
typedef struct s_state	t_state;
typedef struct s_philo	t_philo;
typedef struct s_data	t_data;
typedef struct s_record	t_record;

struct	s_share
{
	long long		philo_cnt;
	long long		must_eat;
	long long		time_to_die;
	long long		time_to_eat;
	long long		time_to_sleep;
}; //	t_share;

struct	s_state
{
	long long		start_time;
	long long		stop;// 1 실행중, 0 멈춤
	long long		full_count;
	t_record		*head;
	t_record		*tail;
	pthread_mutex_t	mx;
}; // t_state

struct s_philo
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
}; //t_philo

struct s_data
{
	t_share			share;
	t_state			state;
	t_philo			*philo;
	pthread_mutex_t	*forks;
}; //	t_data;

typedef struct s_record
{
	t_philo			*philo;
	long long		time;
	long long		version;
	struct s_record	*next;
}; //	t_record;

typedef struct s_resource
{
	int		(*init)(t_data *);
	void	(*cleanup)(t_data *);
}	t_resource;

int	parse_arguments(int ac, char **av, t_data *data);

#endif
