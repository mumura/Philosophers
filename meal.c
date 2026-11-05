/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   meal.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinsekan <jinsekan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/05 13:59:59 by jinsekan          #+#    #+#             */
/*   Updated: 2026/11/05 14:03:49 by jinsekan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	record_meal_start(t_philo *p)
{
	int			sta;
	t_state		*s;
	long long	now;

	s = p->state;
	pthread_mutex_lock(&s->mx);
	now = now_ms();
	if (now < 0 || s->stop == 0)
		sta = 1;
	else if (now - p->last_meal >= p->start->time_to_die)
		sta = 1;
	else
		sta = push_meal(p, now);
	pthread_mutex_unlock(&s->mx);
	return (status);
}
