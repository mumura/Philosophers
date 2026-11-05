/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinsekan <jinsekan@student.42gyeongsa      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 16:12:57 by jinsekan          #+#    #+#             */
/*   Updated: 2025/10/20 23:01:06 by jinsekan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char		*new_str;
	char		*current_out;
	const char	*base;

	if (!s || !f)
		return (NULL);
	new_str = (char *)malloc(ft_strlen(s) + 1);
	if (!new_str)
		return (NULL);
	base = s;
	current_out = new_str;
	while (*s)
	{
		*current_out = f(s - base, *s);
		s++;
		current_out++;
	}
	*current_out = '\0';
	return (new_str);
}
