/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjungk <minjungk@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 00:33:55 by minjungk          #+#    #+#             */
/*   Updated: 2022/09/16 14:04:58 by minjungk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	int				i;
	char			tmp[10];
	unsigned int	num;

	num = n;
	if (n == 0)
	{
		write(fd, "0", 1);
		return ;
	}
	if (n < 0)
	{
		num = -n;
		write(fd, "-", 1);
	}
	i = 0;
	while (num)
	{
		tmp[i++] = num % 10 + '0';
		num /= 10;
	}
	while (--i >= 0)
		write(fd, &tmp[i], 1);
}
