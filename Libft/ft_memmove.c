/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinsekan <jinsekan@student.42gyeongsa      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/09 15:41:57 by jinsekan          #+#    #+#             */
/*   Updated: 2025/10/15 00:55:06 by jinsekan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*dest_iter;
	unsigned char	*src_iter;

	if (!dest && !src)
		return (NULL);
	dest_iter = (unsigned char *) dest;
	src_iter = (unsigned char *) src;
	if (dest_iter == src_iter || n == 0)
		return (dest);
	if (dest_iter > src_iter)
	{
		dest_iter += (n - 1);
		src_iter += (n - 1);
		while (n--)
		{
			*dest_iter-- = *src_iter--;
		}
	}
	else
	{
		while (n--)
			*dest_iter++ = *src_iter++;
	}
	return (dest);
}
//int main()
//{
//	char arr[] = "helloworld";
//	//char *src = arr+1;
//	ft_memmove(arr , arr+1, 5*sizeof(char));
//	printf("%s",arr);
//
//}
