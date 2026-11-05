/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinsekan <jinsekan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/05 07:25:59 by jinsekan          #+#    #+#             */
/*   Updated: 2026/11/05 13:59:07 by jinsekan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	push_meal(t_philo *p, long long time)
{
	t_record	*node;
	t_state		*s;

	s = p->state;
	node = malloc(sizeof(t_record));
	if (!node)
		return (1);
	node->philo = p;
	node->time = time;
	node->version = p->version + 1;
	node->next = NULL;
	p->last_meal = time;
	p->version = node->version;
	if (s->tail)
		s->tail->next = node;
	else
		s->head = node;
	s->tail = node;
	return (0);
}

void	pop_stale(t_state *s)
{
	t_record	*old;

	while (s->head)
	{
		if (s->head->version == s->head->philo->version)
			break ;
		old = s->head;
		s->head = old->next;
		free(old);
	}
	if (!s->head)
		s->tail = NULL;
}

long long	get_next_deadline(t_state *s, long long time_to_die)
{
	long long	deadline;

	pthread_mutex_lock(&s->mx);
	pop_stale(s);
	deadline = -1;
	if (s->head)
		deadline = s->head->time + time_to_die;
	pthread_mutex_unlock(&s->mx);
	return (deadline);
}
