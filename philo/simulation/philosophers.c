/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinsekan <jinsekan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/27 16:13:32 by jinsekan          #+#    #+#             */
/*   Updated: 2026/11/05 17:49:02 by jinsekan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	start_philos(t_data *d)
{
	long long	i;
	long long	start;

	pthread_mutex_lock(&d->state.mx);
	start = now_ms();
	i = -1;
	while (++i < d->share.philo_cnt)
		d->philo[i].last_meal = start;
	d->state.oldest = &d->philo[0];
	d->state.start_time = start;
	pthread_mutex_unlock(&d->state.mx);
}

int	run_simulation(t_data *d)
{
	int	sta;
	int	join_sta;

	sta = create_philo(d);
	if (sta != 0)
		return (sta);
	start_philos(d);
	sta = monitor_philos(d);
	join_sta = join_philo(d, d->share.philo_cnt);
	if (join_sta != 0)
		return (join_sta);
	return (sta);
}
