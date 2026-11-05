/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_wait.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinsekan <jinsekan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/05 18:23:27 by jinsekan          #+#    #+#             */
/*   Updated: 2026/11/05 18:29:57 by jinsekan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	wait_action(t_philo *p, long long duration)
{
	long long	end;
	long long	now;
	long long	deadline;
	long long	wait;

	now = now_ms();
	if (now < 0)
		return (1);
	end = now + duration;
	while (!is_stopped(p->state))
	{
		now = now_ms();
		if (now < 0)
			return (1);
		if (now >= end)
			return (is_stopped(p->state));
		deadline = get_next_deadline(p->state, p->share->time_to_die);
		wait = get_wait_time(end - now, deadline);
		if (wait <= 0)
			return (1);
		usleep((useconds_t)wait);
	}
	return (1);
}
