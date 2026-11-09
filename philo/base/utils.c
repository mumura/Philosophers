/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinsekan <jinsekan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/27 17:40:18 by jinsekan          #+#    #+#             */
/*   Updated: 2026/11/06 18:26:35 by jinsekan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	input_data(t_data *d, long long *values)
{
	d->share.philo_cnt = values[0];
	d->share.time_to_die = values[1];
	d->share.time_to_eat = values[2];
	d->share.time_to_sleep = values[3];
	d->share.must_eat = values[4];
	return (0);
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
	int			i;
	long long	values[5];

	if (!av || !data)
		return (1);
	i = 1;
	values[4] = -1;
	while (i < ac)
	{
		if (ft_get_valid_posint(av[i], &values[i - 1]) == -1)
			return (1);
		i++;
	}
	return (input_data(data, values));
}

void	ft_bzero(void *s, size_t n)
{
	while (n--)
	{
		*(unsigned char *)s++ = 0;
	}
}
