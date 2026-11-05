/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   forks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinsekan <jinsekan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/05 18:30:22 by jinsekan          #+#    #+#             */
/*   Updated: 2026/11/05 20:11:34 by jinsekan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	single_philo(t_philo *p)
{
	pthread_mutex_lock(p->left_fork);
	log_action(p, "has taken a fork");
	while (!is_stopped(p->state))
		usleep(1000);
	pthread_mutex_unlock(p->left_fork);
	return (1);
}

void	release_forks(t_philo *p)
{
	pthread_mutex_unlock(p->right_fork);
	pthread_mutex_unlock(p->left_fork);
}

int	take_forks(t_philo *p)
{
	pthread_mutex_t	*first;
	pthread_mutex_t	*second;

	if (p->left_fork == p->right_fork)
		return (single_philo(p));
	first = p-> left_fork;
	second = p->right_fork;
	if (p->id % 2 == 0)
}


