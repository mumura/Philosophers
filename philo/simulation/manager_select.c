/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manager_select.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinsekan <jinsekan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/06 18:41:35 by jinsekan          #+#    #+#             */
/*   Updated: 2026/11/07 01:43:47 by jinsekan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	available(long long t, long long eat, t_plan *plan)
{
	int	i;

	if (t > MAX_LLONG - eat)
		return (0);
	i = 0;
	while (i < plan->count)
	{
		if (t < plan->blocked[i][1] && t + eat > plan->blocked[i][0])
			return (0);
		i++;
	}
	return (1);
}

static void	build_candidates(t_philo *p, t_plan *plan)
{
	int	i;

	plan->candidates[0] = plan->target;
	plan->candidates[2] = plan->latest;
	plan->len = 3;
	i = 0;
	while (i < plan->count)
	{
		plan->candidates[plan->len++] = plan->blocked[i][0]
			- p->share->time_to_eat;
		plan->candidates[plan->len++] = plan->blocked[i][1];
		i++;
	}
}

static long long	closest_start(t_philo *p, t_plan *plan, long long now)
{
	long long	selected;
	long long	distance;
	long long	d;
	long long	t;
	int			i;

	selected = plan->target;
	distance = MAX_LLONG;
	i = -1;
	while (++i < plan->len)
	{
		t = plan->candidates[i];
		if (t < now || t > plan->latest
			|| !available(t, p->share->time_to_eat, plan))
			continue ;
		d = t - plan->target;
		if (d < 0)
			d = -d;
		if (d < distance || (d == distance && t < selected))
		{
			selected = t;
			distance = d;
		}
	}
	return (selected);
}

long long	manager_select_start(t_philo *p, long long period, long long now)
{
	t_plan	plan;

	if (p->last_meal > MAX_LLONG - p->share->time_to_die
		|| p->last_meal > MAX_LLONG - period)
		return (-1);
	plan.latest = p->last_meal + p->share->time_to_die - 2;
	if (plan.latest < now)
		plan.latest = now;
	plan.target = p->last_meal + period;
	if (plan.target < now)
		plan.target = now;
	if (plan.target > plan.latest)
		plan.target = plan.latest;
	plan.count = manager_intervals(p, period, now, plan.blocked);
	plan.candidates[1] = now;
	build_candidates(p, &plan);
	return (closest_start(p, &plan, now));
}
