/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_philo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinsekan <jinsekan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/02 14:15:08 by jinsekan          #+#    #+#             */
/*   Updated: 2026/11/03 13:51:23 by jinsekan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	cleanup_created(t_data *d, long long cnt)
{
	pthread_mutex_lock(&d->state_mutex);
	d->stop = 0;
	ptread_mutex_unlock(&d->state_mutex);
	if (join_philo(*p, i) != 0)
		return (2);
	return (1);
}

int	create_philo(t_data *d)
{
	t_philo		**p;
	long long	size;
	long long	i;

	size = d->philo_cnt;
	p = &d->philo;
	i = -1;
	while (++i < size)
	{
		if (pthread_create(&(*p)[i].thread, NULL, philo_routine, &(*p)[i]) != 0)
			return (cleanup_created(d, i));
	}
	return (0);
}
