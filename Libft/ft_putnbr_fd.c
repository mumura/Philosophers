/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinsekan <jinsekan@student.42gyeongsa      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 16:39:28 by jinsekan          #+#    #+#             */
/*   Updated: 2025/10/21 17:46:52 by jinsekan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	long long	nb;
	char		ch[11];
	char		*ptr;

	nb = (long long) n;
	if (nb < 0)
	{
		write(fd, "-", 1);
		nb = -nb;
	}
	if (nb == 0)
	{
		write(fd, "0", 1);
		return ;
	}
	ptr = ch + 11;
	while (nb)
	{
		*--ptr = (nb % 10) + '0';
		nb /= 10;
	}
	write(fd, ptr, ch + 11 - ptr);
}
