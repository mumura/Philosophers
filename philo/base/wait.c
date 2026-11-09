/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wait.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinsekan <jinsekan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/06 00:00:00 by jinsekan          #+#    #+#             */
/*   Updated: 2026/11/06 00:00:00 by jinsekan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long long	get_action_end(t_state *s, long long duration)
{
	long long	now;

	now = now_ms();
	if (now < 0 || duration < 0 || duration > MAX_LLONG - now)
	{
		stop_simulation(s);
		return (-1);
	}
	return (now + duration);
}

static long long	action_wait_locked(t_state *s, long long end)
{
	long long	now;
	long long	remaining;
	long long	until_death;

	now = now_ms();
	if (now < 0)
		s->stop = 0;
	if (s->stop == 0 || now < 0 || !s->oldest)
		return (-1);
	until_death = s->oldest->share->time_to_die
		- (now - s->oldest->last_meal);
	if (until_death <= 0)
		return (-1);
	if (now >= end)
		return (0);
	remaining = end - now;
	if (remaining > until_death)
		remaining = until_death;
	if (remaining > 999)
		remaining = 999;
	if (s->full_count > 0 && remaining > 10)
		remaining = 10;
	return (remaining * 1000);
}

int	wait_until(t_state *s, long long end)
{
	long long	wait;

	if (end < 0)
		return (1);
	while (1)
	{
		pthread_mutex_lock(&s->mx);
		wait = action_wait_locked(s, end);
		pthread_mutex_unlock(&s->mx);
		if (wait <= 0)
			return (wait < 0);
		usleep((useconds_t)wait);
	}
}

int	wait_ms(t_state *s, long long duration)
{
	return (wait_until(s, get_action_end(s, duration)));
}
