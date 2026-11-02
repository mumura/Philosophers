/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinsekan <jinsekan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/30 21:45:06 by jinsekan          #+#    #+#             */
/*   Updated: 2026/11/02 13:36:35 by jinsekan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	free_forks(pthread_mutex_t **ph, long long len)
{
	if (*ph == NULL)
		return ;
	while (len)
	{
		--len;
		pthread_mutex_destroy(&(*ph)[len]);
	}
	free(*ph);
	*ph = NULL;
}

void	clean_forks(t_data *d)
{
	free_forks(&d->forks, d->philo_cnt);
}

void	destroy_print_mutex(t_data *d)
{
	pthread_mutex_destroy(&d->print_mutex);
}

void	destroy_state_mutex(t_data *d)
{
	pthread_mutex_destroy(&d->state_mutex);
}

void	free_philo(t_data *d)
{
	free(d->philo);
	d->philo = NULL;
}
