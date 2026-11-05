/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_actions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinsekan <jinsekan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/05 21:09:13 by jinsekan          #+#    #+#             */
/*   Updated: 2026/11/05 21:13:46 by jinsekan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	eat_philo(t_philo *p)
{
	int	status;

	if (take_forks(p))
		return (1);
	status = record_meal_start(p);
	if (status == 0)
	{
		log_action(p, "is eating");
		status = wait_ms(p->state, p->share->time_to_eat);
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
	log_action(p, "is sleeping");
	return (wait_ms(p->state, p->share->time_to_sleep));
}

int	think_philo(t_philo *p)
{
	long long	delay;

	log_action(p, "is thinking");
	while (!is_stopped(p->state))
	{
		delay = get_think_delay(p);
		if (delay < 0)
			return (1);
		if (delay == 0)
			return (0);
		if (wait_ms(p->state, delay))
			return (1);
	}
	return (1);
}
