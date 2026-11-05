/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinsekan <jinsekan@student.42gyeongsa      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/12 21:10:23 by jinsekan          #+#    #+#             */
/*   Updated: 2025/10/15 04:02:27 by jinsekan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*s;
	size_t	s_len;

	s_len = ft_strlen(s1) + ft_strlen(s2) + 1 ;
	s = (char *)malloc(s_len);
	if (!s)
	{
		return (NULL);
	}
	s[0] = '\0';
	ft_strlcpy(s, s1, s_len);
	ft_strlcat(s, s2, s_len);
	return (s);
}
