/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_routine.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinsekan <jinsekan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/02 16:07:13 by jinsekan          #+#    #+#             */
/*   Updated: 2026/11/02 17:34:57 by jinsekan         ###   ########.fr       */
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

void	*philo_routine(void *arg)
{
	return ;
}
