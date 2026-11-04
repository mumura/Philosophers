/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinsekan <jinsekan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/27 17:09:31 by jinsekan          #+#    #+#             */
/*   Updated: 2026/11/04 13:59:44 by jinsekan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	init_data(t_data *d)
{
	ft_bzero(d, sizeof(*d));
	d->share.must_eat = -1;
	d->state.start_time = -1;
	d->state.stop = 1;
}

int	init_forks(t_data *d)
{
	pthread_mutex_t	**ph;
	size_t			max;
	long long		i;
	long long		size;

	size = d->share.philo_cnt;
	max = MAX_SIZE / sizeof(pthread_mutex_t);
	if ((size <= 0) || ((unsigned long long)size > max))
		return (1);
	ph = &d->forks;
	*ph = malloc(sizeof(**ph) * size);
	if (!*ph)
		return (1);
	i = -1;
	while (++i < size)
	{
		if (pthread_mutex_init(&(*ph)[i], NULL) != 0)
		{
			free_forks(ph, i);
			return (1);
		}
	}
	return (0);
}

int	init_meal(t_data *d)
{
	long long	i;

	i = -1;
	while (++i < d->share.philo_cht)
	{
		if (pthread_mutex_init(&d->philo[i].meal, NULL) != 0)
		{
			free_meal(d->philo, i);
			return (1);
		}
	}
	return (0);
}

int	init_state(t_data *d)
{
	if (pthread_mutex_init(&d->state.mx, NULL) != 0)
		return (1);
	return (0);
}

int	init_philos(t_data *d)
{
	long long	i;
	long long	size;
	size_t		max;
	t_philo		**ph;

	size = d->share.philo_cnt;
	max = MAX_SIZE / sizeof(**ph);
	if (size <= 0 || (unsigned long long)size > max)
		return (1);
	ph = &d->philo;
	*ph = malloc(sizeof(**ph) * size);
	if (!*ph)
		return (1);
	i = -1;
	while (++i < size)
	{
		ft_bzero(&(*ph)[i], sizeof(**ph));
		(*ph)[i].id = i + 1;
		(*ph)[i].share = &d->share;
		(*ph)[i].state = &d->state;
		(*ph)[i].left_fork = &d->forks[i];
		(*ph)[i].right_fork = &d->forks[(i + 1) % size];
	}
	return (0);
}
