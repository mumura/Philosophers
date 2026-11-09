/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinsekan <jinsekan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/05 03:32:52 by jinsekan          #+#    #+#             */
/*   Updated: 2026/11/05 13:54:14 by jinsekan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long long	now_ms(void)
{
	struct timeval	tv;

	if (gettimeofday(&tv, NULL) != 0)
		return (-1);
	return ((long long)tv.tv_sec * 1000 + tv.tv_usec / 1000);
}

long long	get_wait_time(long long remaining, long long next_deadline)
{
	long long	now;
	long long	wait;

	now = now_ms();
	if (now < 0 || remaining <= 0)
		return (0);
	wait = remaining;
	if ((next_deadline > 0) && ((next_deadline - now) < wait))
		wait = next_deadline - now;
	if (wait > 10)
		return (10 * 1000);
	if (wait <= 0)
		return (1 * 1000);
	return (wait * 1000);
}
