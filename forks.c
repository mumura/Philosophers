/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   forks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinsekan <jinsekan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/05 18:30:22 by jinsekan          #+#    #+#             */
/*   Updated: 2026/11/05 21:01:43 by jinsekan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	lock_one(t_philo *p, pthread_mutex_t *fork)
{
	long long	index;

	if (pthread_mutex_lock(fork) != 0)
		return (1);
	index = p->id % p->share->philo_cnt;
	if (fork == p->left_fork)
		index = p->id - 1;
	pthread_mutex_lock(&p->state->mx);
	p->state->fork_state[index].owner = p->id;
	p->state->fork_state[index].eat_start = -1;
	pthread_mutex_unlock(&p->state->mx);
	log_action(p, "has taken a fork");
	return (0);
}

static void	unlock_one(t_philo *p, pthread_mutex_t *fork)
{
	long long	index;

	index = p->id % p->share->philo_cnt;
	if (fork == p->left_fork)
		index = p->id - 1;
	pthread_mutex_lock(&p->state->mx);
	p->state->fork_state[index].owner = 0;
	p->state->fork_state[index].eat_start = -1;
	pthread_mutex_unlock(fork);
	pthread_mutex_unlock(&p->state->mx);
}

static int	single_philo(t_philo *p)
{
	if (lock_one(p, p->left_fork))
		return (1);
	while (!is_stopped(p->state))
		usleep(1000);
	unlock_one(p, p->left_fork);
	return (1);
}

void	release_forks(t_philo *p)
{
	unlock_one(p, p->right_fork);
	unlock_one(p, p->left_fork);
}

int	take_forks(t_philo *p)
{
	pthread_mutex_t	*first;
	pthread_mutex_t	*second;

	if (p->left_fork == p->right_fork)
		return (single_philo(p));
	first = p->left_fork;
	second = p->right_fork;
	if (p->id == p->share->philo_cnt)
	{
		first = p->right_fork;
		second = p->left_fork;
	}
	if (lock_one(p, first))
		return (1);
	if (is_stopped(p->state) || lock_one(p, second))
	{
		unlock_one(p, first);
		return (1);
	}
	if (is_stopped(p->state))
	{
		release_forks(p);
		return (1);
	}
	return (0);
}
