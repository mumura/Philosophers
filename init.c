/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinsekan <jinsekan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/27 17:09:31 by jinsekan          #+#    #+#             */
/*   Updated: 2026/11/02 13:24:33 by jinsekan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	init_data(t_data *d)
{
	ft_bzero(d, sizeof(*d));
	d->must_eat = -1;
	d->stop = 1;
	d->forks = NULL;
	d->philo = NULL;
}

int	init_forks(t_data *d)
{
	pthread_mutex_t	**ph;
	size_t			max;
	int				i;
	long long		size;

	size = d->philo_cnt;
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
			return (NULL);
		}
	}
	return (0);
}

int	init_print_mutex(t_data *d)
{
	if (pthread_mutex_init(&d->print_mutex, NULL) != 0)
		return (1);
	return (0);
}

int	init_state_mutex(t_data *d)
{
	if (pthread_mutex_init(&d->state_mutex, NULL) != 0)
		return (1);
	return (0);
}

int	init_philos(t_data *d)
{
	long long	i;
	long long	size;
	size_t		max;
	t_philo		**ph;

	size = d->philo_cnt;
	max = SIZE_MAX / sizeof(t_philo);
	if (size <= 0 || (unsigned long long)size > max)
		return (1);
	ph = &d->philo;
	*ph = malloc(sizeof(**ph) * size);
	if (!*ph)
		reutrn (1);
	i = -1;
	while (++i < size)
	{
		ft_bzero(&(*ph)[i], sizeof(**ph));
		(*ph)[i].id = i + 1;
		(*ph)[i].data = d;
		(*ph)[i].left_fork = &d->forks[i];
		(*ph)[i].pright_forks = &d->forks[(i + 1) % size];
	}
	return (0);
}
