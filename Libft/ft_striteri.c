/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinsekan <jinsekan@student.42gyeongsa      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 23:17:09 by jinsekan          #+#    #+#             */
/*   Updated: 2025/10/21 14:18:36 by jinsekan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	char		*current_out;
	const char	*base;

	if (!s || !f)
		return ;
	current_out = s;
	base = s;
	while (*current_out)
	{
		f(current_out - base, current_out);
		current_out++;
	}
}
