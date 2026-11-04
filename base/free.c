/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinsekan <jinsekan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/30 21:45:06 by jinsekan          #+#    #+#             */
/*   Updated: 2026/11/04 14:05:38 by jinsekan         ###   ########.fr       */
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

void	free_meal(pthread_mutex_t *ph, long long len)
{
	if (*ph == NULL)
		return ;
	while (--len >= 0)
		pthread_mutex_destroy(&ph[len].meal_mx);
}

void	free_philo(t_data *d)
{
	free(d->philo);
	d->philo = NULL;
}
