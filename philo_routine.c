/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_routine.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinsekan <jinsekan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/02 16:07:13 by jinsekan          #+#    #+#             */
/*   Updated: 2026/11/03 16:00:31 by jinsekan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	*finish_philo(t_philo *p)
{
	t_data	*d;

	d = p->data;
	pthread_mutex_lock(&d->state_mutex);
	p->released = 1;
	pthread_mutex_unlock(&d->state_mutex);
	return (NULL);
}

static int	wait_start(t_data *d)
{
	long long	start;
	long long	running;

	while (1)
	{
		pthread_mutex_lock(&d->state_mutex);
		start = d->start_time;
		runnig = d->stop;
		pthread_mutex_unlock(&d->state_mutex);
		if (runnig == 0)
			return (1);
		if (start != -1)
			return (0);

		unsleep(100);
	}
}
int	eat_philo(t_data *d)
{
	return (0);
}

void	*philo_routine(void *arg)
{
	t_philo	*p;

	p = (t_philo *)arg;
	if (wait_start(p->data) != 0)
		return (finish_philo(p));
	/*식사 -> 수면 -> 생각 반복*/
	eat_philo();
	sleep_philo();
	think_philo();
	return (finish_philo(p));
}
