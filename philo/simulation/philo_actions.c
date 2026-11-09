/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_actions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinsekan <jinsekan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/05 21:09:13 by jinsekan          #+#    #+#             */
/*   Updated: 2026/11/05 22:31:34 by jinsekan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	eat_philo(t_philo *p)
{
	int			status;
	long long	end;

	set_action(p, ACTION_WAITING);
	if (take_forks(p))
		return (1);
	status = record_meal_start(p, &end);
	if (status == 0)
	{
		log_action(p, "is eating");
		status = wait_until(p->state, end);
		if (status == 0)
			finish_meal(p);
	}
	if (status == 2)
		stop_simulation(p->state);
	release_forks(p);
	return (status != 0);
}

int	sleep_philo(t_philo *p)
{
	long long	end;

	set_action(p, ACTION_SLEEPING);
	end = get_action_end(p->state, p->share->time_to_sleep);
	if (end < 0)
		return (1);
	log_action(p, "is sleeping");
	return (wait_until(p->state, end));
}

int	think_philo(t_philo *p)
{
	set_action(p, ACTION_THINKING);
	log_action(p, "is thinking");
	return (manager_thinking(p, 0));
}
