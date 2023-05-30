/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjungk <minjungk@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 22:05:50 by minjungk          #+#    #+#             */
/*   Updated: 2022/12/05 22:44:36 by minjungk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	numlen(unsigned int n)
{
	int	len;

	if (n == 0)
		return (1);
	len = 0;
	while (n)
	{
		++len;
		n /= 10;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	int				i;
	unsigned int	num;
	char			*rtn;

	num = n * ((n > 0) - (n < 0));
	i = numlen(num) + (n < 0);
	rtn = ft_calloc(i + 1, sizeof(char));
	if (rtn == NULL)
		return (NULL);
	while (num)
	{
		rtn[--i] = num % 10 + '0';
		num /= 10;
	}
	if (n == 0)
		rtn[0] = '0';
	if (n < 0)
		rtn[0] = '-';
	return (rtn);
}
