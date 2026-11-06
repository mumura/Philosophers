/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resource.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinsekan <jinsekan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/01 01:08:19 by jinsekan          #+#    #+#             */
/*   Updated: 2026/11/05 20:58:57 by jinsekan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	start_philo(t_data *d)
{
	static const t_resource	resources[] = {
	{init_forks, clean_forks},
	{init_state, clean_state},
	{init_print, clean_print},
	{init_philos, free_philo},
	{init_meal, clean_meal},
	{init_fork_state, free_fork_state},
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
