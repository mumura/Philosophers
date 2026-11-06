/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinsekan <jinsekan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/05 14:43:19 by jinsekan          #+#    #+#             */
/*   Updated: 2026/11/05 21:22:16 by jinsekan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	check_end_locked(t_data *d, long long now)
{
	t_state	*s;
	int		result;

	s = &d->state;
	if (s->stop == 0)
		return (1);
	result = 0;
	if (now < 0)
		result = 2;
	else if (s->oldest && now - s->oldest->last_meal
		>= d->share.time_to_die)
		result = 3;
	else if (d->share.must_eat > 0 && s->full_count == d->share.philo_cnt)
		result = 1;
	if (result != 0)
		s->stop = 0;
	return (result);
}

int	check_death(t_data *d)
{
	int			result;
	long long	now;
	t_philo		*dead;

	dead = NULL;
	pthread_mutex_lock(&d->state.print);
	pthread_mutex_lock(&d->state.mx);
	now = now_ms();
	result = check_end_locked(d, now);
	if (result == 3)
		dead = d->state.oldest;
	pthread_mutex_unlock(&d->state.mx);
	if (dead)
		log_locked(dead, "died", now);
	pthread_mutex_unlock(&d->state.print);
	if (result == 3)
		return (1);
	return (result);
}

int	monitor_philos(t_data *d)
{
	long long	deadline;
	long long	now;
	long long	wait;
	int			result;

	while (!is_stopped(&d->state))
	{
		result = check_death(d);
		if (result != 0)
			return (result == 2);
		deadline = get_next_deadline(&d->state,
				d->share.time_to_die);
		now = now_ms();
		if (deadline < 0 || now < 0)
		{
			stop_simulation(&d->state);
			return (1);
		}
		wait = get_wait_time(deadline - now, deadline);
		if (wait > 0)
			usleep((useconds_t)wait);
	}
	return (0);
}
