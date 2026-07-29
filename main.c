/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinsekan <jinsekan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/27 16:10:43 by jinsekan          #+#    #+#             */
/*   Updated: 2026/07/29 17:07:28 by jinsekan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int ac, char *av)
{
	t_info	*info;

	if (ac < 5 || ac > 6)
		reutnr (0);
	init_info(info);
	parse_arguments(ac, av, info);
}
