/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   think.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinsekan <jinsekan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/05 21:07:05 by jinsekan          #+#    #+#             */
/*   Updated: 2026/11/05 21:07:56 by jinsekan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static long long	fork_delay(t_fork_state *f,
	long long now, long long eat_time)
{
	long long	remaining;

	if (f->owner == 0)
		return (0);
	if (f->eat_start == -1)
		return (-1);
	remaining = f->eat_start + eat_time - now;
	if (remaining <= 0)
		return (0);
	return (remaining);
}

static long long	max_delay(long long left, long long right)
{
	if (left < 0 || right < 0)
		return (1);
	if (left > right)
		return (left);
	return (right);
}

long long	get_think_delay(t_philo *p)
{
	t_fork_state	*fs;
	long long		now;
	long long		left;
	long long		right;

	now = now_ms();
	if (now < 0)
		return (-1);
	pthread_mutex_lock(&p->state->mx);
	fs = p->state->fork_state;
	left = fork_delay(&fs[p->id - 1], now,
			p->share->time_to_eat);
	right = fork_delay(&fs[p->id % p->share->philo_cnt],
			now, p->share->time_to_eat);
	pthread_mutex_unlock(&p->state->mx);
	return (max_delay(left, right));
}
