/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinsekan <jinsekan@student.42gyeongsa      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 03:33:18 by jinsekan          #+#    #+#             */
/*   Updated: 2025/10/18 13:01:26 by jinsekan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdlib.h>
//#include <stdio.h>

#include "libft.h"

int	chk_len(int tem)
{
	int			len;
	long long	n;

	n = tem;
	len = 0;
	if (n <= 0)
	{
		len = 1;
	}
	if (n < 0)
	{
		n = -n;
	}
	while (n > 0)
	{
		n /= 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	long long	num;	
	int			len;
	int			sign;
	char		*itoa;

	num = n;
	sign = (n < 0);
	len = chk_len(n);
	itoa = (char *)malloc(sizeof(char) * (len + 1));
	if (!itoa)
		return (NULL);
	itoa[len] = '\0';
	if (num == 0)
		itoa[0] = '0';
	else if (num < 0)
		num = -num;
	while (--len >= sign)
	{
		itoa[len] = (num % 10) + '0';
		num /= 10;
	}
	if (sign)
		itoa[0] = '-';
	return (itoa);
}
//int main()
//{
//	printf("%s\n", ft_itoa(0));
//	printf("%s\n", ft_itoa(12345));
//    printf("%s\n", ft_itoa(-12345));
//    printf("%s\n", ft_itoa(-2147483648));
//}
