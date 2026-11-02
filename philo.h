/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinsekan <jinsekan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/27 17:02:48 by jinsekan          #+#    #+#             */
/*   Updated: 2026/11/02 13:40:47 by jinsekan         ###   ########.fr       */
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

typedef struct s_data	t_data;
typedef struct s_philo	t_philo;

struct s_philo
{
	long long		id;
	pthread_t		thread;
	long long		last_meal;
	long long		meal_cnt;
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*right_fork;
	t_data			*data;
}; //t_philo

struct s_data
{
	long long		philo_cnt;
	long long		must_eat;
	long long		time_to_die;
	long long		time_to_eat;
	long long		time_to_sleep;
	long long		start_time;
	long long		stop;// 1 실행중, 0 멈춤
	t_philo			*philo;
	pthread_mutex_t	*forks;
	pthread_mutex_t	print_mutex;
	pthread_mutex_t	state_mutex;
}; //	t_data;

typedef struct s_resource
{
	int		(*init)(t_data *);
	void	(*cleanup)(t_data *);
}	t_resource;

int	parse_arguments(int ac, char **av, t_info *info);

#endif
