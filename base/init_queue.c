/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_queue.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinsekan <jinsekan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/05 21:23:54 by jinsekan          #+#    #+#             */
/*   Updated: 2026/11/05 21:24:34 by jinsekan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	init_queue(t_data *d)
{
	t_record	*node;
	long long	i;

	i = -1;
	while (++i < d->share.philo_cnt)
	{
		node = malloc(sizeof(t_record));
		if (!node)
		{
			free_queue(d);
			return (1);
		}
		node->philo = &d->philo[i];
		node->time = d->state.start_time;
		node->version = 0;
		node->next = NULL;
		if (d->state.tail)
			d->state.tail->next = node;
		else
			d->state.head = node;
		d->state.tail = node;
	}
	return (0);
}
