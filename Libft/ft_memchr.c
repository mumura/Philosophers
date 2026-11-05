/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinsekan <jinsekan@student.42gyeongsa      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/11 03:49:31 by jinsekan          #+#    #+#             */
/*   Updated: 2025/10/14 23:22:53 by jinsekan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*chek;

	chek = (unsigned char *)s;
	while (n--)
	{
		if (*chek == (unsigned char)c)
		{
			return (chek);
		}
		chek++;
	}
	return (NULL);
}
