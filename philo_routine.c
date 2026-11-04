/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_routine.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinsekan <jinsekan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/02 16:07:13 by jinsekan          #+#    #+#             */
/*   Updated: 2026/11/04 17:52:17 by jinsekan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	*finish_philo(t_philo *p)
{
	t_state	*s;

	s = p->state;
	pthread_mutex_lock(&s->mx);
	p->released = 1;
	pthread_mutex_unlock(&s->mx);
	return (NULL);
}

static int	wait_start(t_state *s)
{
	long long	start;
	long long	running;

	while (1)
	{
		pthread_mutex_lock(&s->mx);
		start = s->start_time;
		running = s->stop;
		pthread_mutex_unlock(&s->mx);
		if (runnig == 0)
			return (1);
		if (start != -1)
			return (0);
		usleep(100);
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
	if (wait_start(p->state) != 0)
		return (finish_philo(p));
	/*식사 -> 수면 -> 생각 반복*/
	eat_philo();
	sleep_philo();
	think_philo();
	return (finish_philo(p));
}
