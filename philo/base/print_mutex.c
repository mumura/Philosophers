/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_mutex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinsekan <jinsekan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/06 00:00:00 by jinsekan          #+#    #+#             */
/*   Updated: 2026/11/06 00:00:00 by jinsekan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	init_print(t_data *d)
{
	if (pthread_mutex_init(&d->state.print, NULL) != 0)
		return (1);
	return (0);
}

void	clean_print(t_data *d)
{
	pthread_mutex_destroy(&d->state.print);
}
