/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation_state.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinsekan <jinsekan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/05 03:33:54 by jinsekan          #+#    #+#             */
/*   Updated: 2026/11/05 17:48:19 by jinsekan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	is_stopped(t_state *s)
{
	int	stopped;

	pthread_mutex_lock(&s->mx);
	stopped = (s->stop == 0);  // 참이면(실행중) 1, 거짓이면(멈춤) 0
	pthread_mutex_unlock(&s->mx);
	return (stopped);
}

void	stop_simulation(t_state *s)
{
	pthread_mutex_lock(&s->mx);
	s->stop = 0;
	pthread_mutex_unlock(&s->mx);
}

int	check_all_full(t_data *d)
{
	int	full;

	if (d->share.must_eat < 0)
		return (0);
	pthread_mutex_lock(&d->state.mx);
	full = (d->state.full_count == d->share.philo_cnt);
	pthread_mutex_unlock(&d->state.mx);
	return (full);
}
