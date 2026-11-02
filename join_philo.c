/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   join_philo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinsekan <jinsekan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/02 16:07:25 by jinsekan          #+#    #+#             */
/*   Updated: 2026/11/02 16:12:17 by jinsekan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	wait_released(t_data *d, long long cnt)
{
	long long	i;
	long long	done;

	i = 0;
	while (i < cnt)
	{
		pthread_mutex_lock(&d->state_mutex);
		done = d->philo[i].released;
		ptread_mutex_unlock(&d->state_mutex);
		if (done)
			i++;
		else
			usleep(100);
	}
}

int	join_philo(t_data *d, long long cnt)
{
	int			sta;
	long long	i;

	i = -1;
	sta = 0;
	while (++i < cnt)
	{
		if (pthread_join(p[i].thread, NULL) != 0)
			sta = 1;
	}
	if (sta != 0)
		wait_released(d, cnt);
	return (sta);
}
