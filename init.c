/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinsekan <jinsekan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/27 17:09:31 by jinsekan          #+#    #+#             */
/*   Updated: 2026/10/30 22:06:00 by jinsekan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	init_data(t_data *data)
{
	ft_bzero(data, sizeof(*data));
}

pthread_mutex_t	*init_forks(long long size)
{
	pthread_mutex_t	*ph;
	size_t			max;
	int				i;

	max = MAX_SIZE / sizeof(pthread_mutex_t);
	if ((size <= 0) || ((unsigned long long)size > max))
		return (NULL);
	ph = malloc(sizeof(*ph) * size);
	if (!ph)
		return (NULL);
	i = -1;
	while (++i < size)
	{
		if (!pthread_mutex_init(&ph[i], NULL))
		{
			free_forks(ph[i]);
			return (1);
		}
	}
	return (ph);
}
