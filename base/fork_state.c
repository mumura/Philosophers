/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork_state.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinsekan <jinsekan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/05 21:25:25 by jinsekan          #+#    #+#             */
/*   Updated: 2026/11/05 21:26:46 by jinsekan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	init_fork_state(t_data *d)
{
	long long		i;
	long long		cnt;
	t_fork_state	*fs;

	cnt = d->share.philo_cnt;
	if (cnt <= 0 || (unsigned long long)cnt
		> MAX_SIZE / sizeof(t_fork_state))
		return (1);
	fs = malloc(sizeof(*fs) * cnt);
	if (!fs)
		return (1);
	i = -1;
	while (++i < cnt)
	{
		fs[i].owner = 0;
		fs[i].eat_start = -1;
	}
	d->state.fork_state = fs;
	return (0);
}

void	free_fork_state(t_data *d)
{
	free(d->state.fork_state);
	d->state.fork_state = NULL;
}
