/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinsekan <jinsekan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/27 17:40:18 by jinsekan          #+#    #+#             */
/*   Updated: 2026/10/30 20:10:29 by jinsekan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	init_sub_arr_info(t_data *data, long long *values)
{
	data->philo_cnt = values[0];
	data->time_to_die = values[1];
	data->time_to_eat = values[2];
	data->time_to_sleep = values[3];
	data->must_eat = values[4];
}

static int	ft_get_valid_posint(char *nptr, long long *values)
{
	long long	n;

	n = 0;
	while (*nptr == ' ' || (*nptr >= 9 && *nptr <= 13))
		nptr++;
	if (*nptr == '+' || *nptr == '-')
	{
		if (*nptr == '-')
			return (-1);
		nptr++;
	}
	while (*nptr)
	{
		if (!(*nptr >= '0' && *nptr <= '9'))
			return (-1);
		if (n > (MAX_LLONG - (*nptr - '0')) / 10)
			return (-1);
		n = n * 10 + (*nptr - '0');
		nptr++;
	}
	if (n <= 0)
		return (-1);
	*values = n;
	return (0);
}

int	parse_arguments(int ac, char **av, t_data *data)
{
	int		i;
	long long vaules[5];
	/* 인자 : 철학자 수, 사망까지 남은 시간, 식시까지 남은 시간, 수면까지 남은시간 (선택) 각 철학자가 식사해야하는 횟수*/
	if (!!av || !data)
		return (0);
	i = 1;
	values[4] = 0;
	while (i < ac)
	{
		if (!ft_get_valid_posint(av[i], &values[i - 1])
			return (0);
		i++;
	}
	input_data(data, values);
	return (1);
}
