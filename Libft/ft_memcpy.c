/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinsekan <jinsekan@student.42gyeongsa      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 15:10:47 by jinsekan          #+#    #+#             */
/*   Updated: 2025/10/15 00:56:29 by jinsekan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*des;

	des = (unsigned char *) dest;
	if (des == src)
	{
		return (dest);
	}
	while (n--)
	{
		*des++ = *(unsigned char *) src++;
	}
	return (dest);
}
//int main()
//{   
//    char arr[] = "helloworld";
//     //char *src = arr+1;
//     ft_memcpy(arr+2, arr+1, 5*sizeof(char));
//     printf("%s",arr);
// 
//}
