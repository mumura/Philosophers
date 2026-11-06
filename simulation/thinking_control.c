/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thinking_control.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinsekan <jinsekan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/05 21:07:05 by jinsekan          #+#    #+#             */
/*   Updated: 2026/11/05 23:00:53 by jinsekan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	set_action(t_philo *p, int action)
{
	pthread_mutex_lock(&p->state->mx);
	p->action = action;
	if (action == ACTION_THINKING)
		p->think_end = MAX_LLONG;
	pthread_mutex_unlock(&p->state->mx);
}

int	wait_think(t_philo *p, long long delay)
{
	long long	end;

	end = get_action_end(p->state, delay);
	if (end < 0)
		return (1);
	pthread_mutex_lock(&p->state->mx);
	p->think_end = end;
	pthread_mutex_unlock(&p->state->mx);
	if (delay > 0)
		return (wait_until(p->state, end));
	return (0);
}

static int	urgent_neighbor(t_philo *p, long long now)
{
	t_philo		*all;
	t_philo		*q;
	long long	n;
	long long	i;

	all = p - (p->id - 1);
	n = p->share->philo_cnt;
	i = -1;
	while (++i < 2)
	{
		q = &all[(p->id + n - 2 + 2 * i) % n];
		if (q != p && q->last_meal < p->last_meal
			&& now - q->last_meal < q->share->time_to_die
			&& (q->action == ACTION_WAITING
				|| (q->action == ACTION_THINKING && q->think_end <= now + 1)))
			return (1);
	}
	return (0);
}

static int	next_yield(t_philo *p, long long limit, long long *wake)
{
	long long	now;
	long long	own;
	int			result;

	pthread_mutex_lock(&p->state->mx);
	now = now_ms();
	own = p->share->time_to_die - (now - p->last_meal);
	result = 0;
	if (p->state->stop == 0 || now < 0)
		result = -1;
	else if (now < limit && own > p->share->time_to_eat
		&& own - p->share->time_to_eat > 2)
	{
		result = urgent_neighbor(p, now);
		*wake = now + 1;
		if (*wake > limit)
			*wake = limit;
	}
	pthread_mutex_unlock(&p->state->mx);
	return (result);
}

int	yield_think(t_philo *p)
{
	long long	start;
	long long	budget;
	long long	wake;
	int			next;

	pthread_mutex_lock(&p->state->mx);
	start = now_ms();
	budget = p->share->time_to_die - (start - p->last_meal);
	budget -= p->share->time_to_eat;
	budget -= 2;
	if (budget > 10)
		budget = 10;
	pthread_mutex_unlock(&p->state->mx);
	if (start < 0)
		return (1);
	if (budget <= 0)
		return (0);
	next = next_yield(p, start + budget, &wake);
	while (next > 0)
	{
		if (wait_until(p->state, wake))
			return (1);
		next = next_yield(p, start + budget, &wake);
	}
	return (next < 0);
}
