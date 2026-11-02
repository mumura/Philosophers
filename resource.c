/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resource.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinsekan <jinsekan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/01 01:08:19 by jinsekan          #+#    #+#             */
/*   Updated: 2026/11/02 11:04:22 by jinsekan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	start_philo(t_data *d)
{
	static const t_resource	resources[] = {
	{init_forks, free_forks},
	{init_print_mutex, destroy_print_mutex},
	{init_state_mutex, destroy_state_mutex},
	{init_philos, free_philos},
	{NULL, NULL}
	};

	return (with_resource(resources, d));
}

int	with_resource(const t_resource *res, t_data *d)
{
	int	status;

	if (res->init == NULL)
		return (run_simulation(d));
	if (res->init(d) != 0)
		return (1);
	status = with_resource(res + 1, d);
	res->cleanup(d);
	return (status);
}
