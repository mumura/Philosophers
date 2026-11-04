/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinsekan <jinsekan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/05 03:32:52 by jinsekan          #+#    #+#             */
/*   Updated: 2026/11/05 05:52:36 by jinsekan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long long	now_ms(void)
{
	struct timeval	tv;

	gettimeofdat(&tv, NULL);
	return ((long long)tv.tvsec * 1000 + tv.tv_usec / 1000);
}

int	wait_ms(t_state *s, long long duration)
{
	long long	s_time;

	s->start_time = now_ms();
	s_time = *s->start_time;
	while (now_ms() - s_time < duration)
	{
		
	}
	return (0);
}
