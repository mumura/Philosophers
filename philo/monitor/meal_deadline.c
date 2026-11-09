/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   meal_deadline.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinsekan <jinsekan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/06 00:00:00 by jinsekan          #+#    #+#             */
/*   Updated: 2026/11/06 00:00:00 by jinsekan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/* Caller holds state.mx; p belongs to the contiguous philosopher array. */
void	update_meal_locked(t_philo *p, long long time)
{
	t_philo		*all;
	t_philo		*oldest;
	long long	i;

	p->last_meal = time;
	if (p->state->oldest != p)
		return ;
	all = p - (p->id - 1);
	oldest = &all[0];
	i = 0;
	while (++i < p->share->philo_cnt)
	{
		if (all[i].last_meal < oldest->last_meal)
			oldest = &all[i];
	}
	p->state->oldest = oldest;
}

long long	get_next_deadline(t_state *s, long long time_to_die)
{
	long long	deadline;

	pthread_mutex_lock(&s->mx);
	deadline = -1;
	if (s->oldest)
		deadline = s->oldest->last_meal + time_to_die;
	pthread_mutex_unlock(&s->mx);
	return (deadline);
}
