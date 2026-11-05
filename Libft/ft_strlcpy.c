/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinsekan <jinsekan@student.42gyeongsa      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/10 22:22:27 by jinsekan          #+#    #+#             */
/*   Updated: 2025/10/15 00:43:55 by jinsekan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	int	len;

	len = ft_strlen(src);
	if (size == 0)
		return (len);
	size--;
	while (size-- && *src)
	{
		*dst++ = *src++;
	}
	*dst = '\0';
	return (len);
}
//int main()
//{
//	char des[] ="abc";
//	char src[] = "cccc";;
//	printf( "%zu\n",ft_strlcpy(des, src, 2)) ;
//	printf("%s\n", des);
//}
