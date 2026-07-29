/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinsekan <jinsekan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/27 17:40:18 by jinsekan          #+#    #+#             */
/*   Updated: 2026/07/29 18:39:58 by jinsekan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	init_sub_arr_info(int **values, t_info *info)
{
	values[0] = &info->philos;
	values[1] = &info->to_die;
	values[2] = &info->to_eat;
	values[3] = &info->to_sleep;
	values[4] = &info->must_eat;
}

int	ft_get_valid_posint(char *nptr, int *value)
{
	long long	n;
	// 에러 처리하고 void로 바꾸기
	n = 0;
	while (*nptr == ' ')
		nptr++;
	if (*nptr == '+' || *nptr == '-')
	{
		if (*nptr == '-')
			return (-1);
		nptr++;
	}
	while (*nptr)
	{
		if (!(*nptr >= '1' && *nptr <= '9'))
			return (-1);
		n = n * 10 + (*nptr - '0');
		nptr++;
	}
	if (n > 2147483647 || n < 0)
		return (-1);
	*value = n;
	return ((int)n);
}

int	parse_arguments(int ac, char **av, t_info *info)
{
	int		i;
	int		*values[5];

	/* 인자 : 철학자 수, 사망까지 남은 시간, 식시까지 남은 시간, 수면까지 남은시간 (선택) 각 철학자가 식사해야하는 횟수*/
	if (ac == 6)
		info->has_must_eat = 'y';
	init_sub_arr_info(values, info);
	i = 1;
	while (i <= ac - 1)
	{
		if (ft_get_valid_posint(av[i], values[i - 1]) == -1)
			return (0);
		i++;
	}
	return (1);
}
