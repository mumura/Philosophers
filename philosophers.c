/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinsekan <jinsekan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/27 16:13:32 by jinsekan          #+#    #+#             */
/*   Updated: 2026/11/04 17:53:12 by jinsekan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	start_philos(t_data *d)
{
	long long	i;

	pthread_mutex_lock(&d->state.mx);
	d->state.start_time = now_ms();
	i = -1;
	while (++i < d->share.philo_cnt)
		d->philo[i].last_meal = d->state.start_time;
	pthread_mutex_unlock(&d->state.mx);
}

int	run_simulation(t_data *d)
{
	int	sta;

	sta = create_philo(d);
	if (sta != 0)
		return (sta);
	start_philos(d);
	return (join_philo(d, d->share.philo_cnt));
}
