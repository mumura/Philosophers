/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   meal.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinsekan <jinsekan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/05 13:59:59 by jinsekan          #+#    #+#             */
/*   Updated: 2026/11/05 22:04:51 by jinsekan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	mark_eating_locked(t_philo *p, long long now)
{
	long long	left;
	long long	right;

	left = p->id - 1;
	right = p->id % p->share->philo_cnt;
	p->state->fork_state[left].eat_start = now;
	p->state->fork_state[right].eat_start = now;
}

int	record_meal_start(t_philo *p)
{
	int			sta;
	t_state		*s;
	long long	now;

	s = p->state;
	pthread_mutex_lock(&s->mx);
	now = now_ms();
	if (now < 0)
		sta = 2;
	else if ((s->stop == 0) || (now - p->last_meal) >= (p->share->time_to_die))
		sta = 1;
	else
	{
		sta = push_meal(p, now);
		if (sta == 0)
			mark_eating_locked(p, now);
		else
			sta = 2;
	}
	pthread_mutex_unlock(&s->mx);
	return (sta);
}

void	finish_meal(t_philo *p)
{
	t_state		*s;
	long long	*meal_cnt;
	long long	must_eat;

	meal_cnt = &p->meal_cnt;
	must_eat = p->share->must_eat;
	s = p->state;
	pthread_mutex_lock(&s->mx);
	if (s->stop == 1)
	{
		(*meal_cnt)++;
		if ((must_eat > 0) && *meal_cnt == must_eat)
			s->full_count++;
	}
	pthread_mutex_unlock(&s->mx);
}
