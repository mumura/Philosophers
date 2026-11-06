/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manager_plan.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinsekan <jinsekan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/06 18:41:35 by jinsekan          #+#    #+#             */
/*   Updated: 2026/11/07 01:43:47 by jinsekan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	forks_busy(t_philo *p)
{
	t_fork_state	*forks;
	long long		left;
	long long		right;
	int				busy;

	forks = p->state->fork_state;
	left = p->id - 1;
	right = p->id % p->share->philo_cnt;
	pthread_mutex_lock(&p->state->mx);
	busy = forks[left].owner != 0 || forks[right].owner != 0;
	pthread_mutex_unlock(&p->state->mx);
	return (busy);
}

static int	check_forks_again(t_philo *p)
{
	long long	delay;

	while (1)
	{
		if (!forks_busy(p))
			return (0);
		delay = get_think_delay(p);
		if (delay < 0)
		{
			stop_simulation(p->state);
			return (1);
		}
		if (delay == 0)
			delay = 1;
		if (wait_think(p, delay))
			return (1);
	}
}

static int	fallback_thinking(t_philo *p, int initial)
{
	long long	target;

	if (initial)
		return (0);
	target = get_think_delay(p);
	if (target < 0)
	{
		stop_simulation(p->state);
		return (1);
	}
	if (wait_think(p, target))
		return (1);
	return (yield_think(p));
}

static long long	plan_thinking(t_philo *p, long long period,
		long long now, int initial)
{
	long long	target;

	if (initial)
		target = manager_seed(p, period);
	else
		target = manager_select_start(p, period, now);
	if (p->state->stop == 0 || target < 0 || now < 0)
		return (-1);
	p->action = ACTION_THINKING;
	p->think_end = target;
	return (target);
}

int	manager_thinking(t_philo *p, int initial)
{
	long long	period;
	long long	target;
	long long	now;

	period = manager_period(p);
	if (period == 0)
		return (fallback_thinking(p, initial));
	pthread_mutex_lock(&p->state->mx);
	now = now_ms();
	target = plan_thinking(p, period, now, initial);
	pthread_mutex_unlock(&p->state->mx);
	if (target < 0)
	{
		stop_simulation(p->state);
		return (1);
	}
	if (initial && target > now)
		log_action(p, "is thinking");
	if (wait_until(p->state, target))
		return (1);
	return (check_forks_again(p));
}
