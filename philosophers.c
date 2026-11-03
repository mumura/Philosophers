/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinsekan <jinsekan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/27 16:13:32 by jinsekan          #+#    #+#             */
/*   Updated: 2026/11/03 13:27:49 by jinsekan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	start_philos(t_data *d)
{
	long long	i;

	pthread_mutex_lock(&d->state_mutex);
	d->start_time = now_ms();
	i = -1;
	while (++i < d->philo_cnt)
		d->philo[i].last_meal = d->start_time;
	pthread_mutex_unlock(&d->state_mutex);
	return (0);
}

int	run_simulation(t_data *d)
{
	int	status;

	status = create_philo(d);
	if (status != 0)
		return (status);
	start_philos(d);
}
