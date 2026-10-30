/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinsekan <jinsekan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/30 21:45:06 by jinsekan          #+#    #+#             */
/*   Updated: 2026/10/30 21:51:31 by jinsekan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	free_forks(pthread_mutex_t *ph, long long len)
{
	while (len)
	{
		--len;
		pthread_mutex_destroy(&ph[len]);
	}
	free(ph);
}
