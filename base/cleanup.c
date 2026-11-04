/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinsekan <jinsekan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/04 14:05:18 by jinsekan          #+#    #+#             */
/*   Updated: 2026/11/04 14:05:41 by jinsekan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	clean_forks(t_data *d)
{
	free_forks(&d->forks, d->share.philo_cnt);
}

void	clean_meal(t_data *d)
{
	free_meal(d->philo.meal, d->share.philo_cnt);
}

void	clean_state(t_data *d)
{
	pthread_mutex_destroy(&d->state.mutex);
}
