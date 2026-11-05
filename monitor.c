/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinsekan <jinsekan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/05 14:43:19 by jinsekan          #+#    #+#             */
/*   Updated: 2026/11/05 17:47:54 by jinsekan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_death(t_data *d)
{
	t_state		*s;
	t_record	*nd;
	long long	now;
	int			dead;

	s = &d->state;
	pthread_mutex_lock(&s->mx);
	pop_stale(s);
	nd = s->head;
	now = now_ms();
	dead = (now < 0);
	if (!dead && s->stop == 1 && nd)
		dead = ((now - nd-> time) >= d->share.time_to_die);
	if (dead)
	{
		s->stop = 0;
		if (now >= 0)
			log_locked(nd->philo, "died", now);
	}
	pthread_mutex_unlock(&s->mx);
	return (dead);
}

int	monitor_philos(t_data *d)
{
	long long	deadline;
	long long	now;
	long long	wait;

	while (!is_stopped(&d->state))
	{
		if (check_all_full(d))
		{
			stop_simulation(&d->state);
			return (0);
		}
		if (check_death(d))
			return (0);
		deadline = get_next_deadline(&d->state, d->share.time_to_die);
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
