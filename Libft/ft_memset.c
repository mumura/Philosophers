/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinsekan <jinsekan@student.42gyeongsa      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 03:11:36 by jinsekan          #+#    #+#             */
/*   Updated: 2025/10/23 03:11:38 by jinsekan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*arr;

	arr = (unsigned char *) s;
	while (n--)
	{
		*arr++ = (unsigned char) c;
	}
	return (s);
}

//int main()
//{
//	char arr[] = "blockdmask";
//	ft_memset(arr, 'c', 5*sizeof(char));
//	printf("%s",arr);
//			
//}
