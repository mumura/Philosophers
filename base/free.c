/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinsekan <jinsekan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/30 21:45:06 by jinsekan          #+#    #+#             */
/*   Updated: 2026/11/05 20:27:37 by jinsekan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	free_forks(pthread_mutex_t **ph, long long len)
{
	if (*ph == NULL)
		return ;
	while (--len >= 0)
		pthread_mutex_destroy(&(*ph)[len]);
	free(*ph);
	*ph = NULL;
}

void	free_meal(t_philo *ph, long long len)
{
	if (ph == NULL)
		return ;
	while (--len >= 0)
		pthread_mutex_destroy(&ph[len].meal);
}

void	free_philo(t_data *d)
{
	free(d->philo);
	d->philo = NULL;
}

void	free_queue(t_data *d)
{
	t_record	*node;
	t_record	*next;

	node = d->state.head;
	while (node)
	{
		next = node->next;
		free(node);
		node = next;
	}
	d->state.head = NULL;
	d->state.tail = NULL;
}
