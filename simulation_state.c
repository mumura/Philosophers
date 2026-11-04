/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation_state.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinsekan <jinsekan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/05 03:33:54 by jinsekan          #+#    #+#             */
/*   Updated: 2026/11/05 03:48:32 by jinsekan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	is_stopped(t_state *s)
{
	int	stopped;

	pthread_mutex_lock(&s->mx);
	stopped = (state->stop == 0); // 참이면(실행중) 1, 거짓이면(멈춤) 0
	pthread_mutex_unlock(&s->mx);
	return (stopped);
}
