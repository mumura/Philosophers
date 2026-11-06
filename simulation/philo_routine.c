/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_routine.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinsekan <jinsekan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/02 16:07:13 by jinsekan          #+#    #+#             */
/*   Updated: 2026/11/05 21:23:23 by jinsekan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	*finish_philo(t_philo *p)
{
	t_state	*s;

	s = p->state;
	pthread_mutex_lock(&s->mx);
	p->released = 1;
	p->action = 0;
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
		if (running == 0)
			return (1);
		if (start != -1)
			return (0);
		usleep(100);
	}
}

static int	start_stagger(t_philo *p)
{
	if (p->id % 2 == 0 && p->share->time_to_die > 2)
		return (wait_ms(p->state, 1));
	return (0);
}

void	*philo_routine(void *arg)
{
	t_philo	*p;

	p = (t_philo *)arg;
	if (wait_start(p->state))
		return (finish_philo(p));
	if (start_stagger(p))
		return (finish_philo(p));
	if (manager_thinking(p, 1))
		return (finish_philo(p));
	while (!is_stopped(p->state))
	{
		if (eat_philo(p))
			break ;
		if (sleep_philo(p))
			break ;
		if (think_philo(p))
			break ;
	}
	return (finish_philo(p));
}
