/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinsekan <jinsekan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/27 17:09:31 by jinsekan          #+#    #+#             */
/*   Updated: 2026/07/28 20:19:16 by jinsekan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	init_info(t_info *info)
{
	info->philos = -1;
	info->fork = -1;
	info->to_die = -1;
	info->to_eat = -1;
	info->to_sleep = -1;
	info->has_must_eat = 'n';
	info->must_eat = -1;
}

void	input_info(t_info *info, int *arr)
{
	info->philos = arr[0];
	info->fork = arr[0];
	info->to_die = arr[1];
	info->to_eat = arr[2];
	info->to_sleep = arr[3];
	if (info->has_must_eat == 'y')
		info->must_eat = arr[4];
}
