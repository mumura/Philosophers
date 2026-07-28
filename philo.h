/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinsekan <jinsekan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/27 17:02:48 by jinsekan          #+#    #+#             */
/*   Updated: 2026/07/28 21:01:33 by jinsekan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

typedef struct s_info
{
	int		philos;
	int		fork;
	int		to_die;
	int		to_eat;
	int		to_sleep;
	//int	chk_must_eat;
	int		must_eat;
	char	has_must_eat;
}t_info;

#endif