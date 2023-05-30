/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjungk <minjungk@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 22:05:50 by minjungk          #+#    #+#             */
/*   Updated: 2022/08/11 07:41:35 by iijung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	numlen(unsigned long n, int base_len)
{
	int	len;

	if (n == 0)
		return (1);
	len = 0;
	while (n)
	{
		++len;
		n /= base_len;
	}
	return (len);
}

static int	baselen(const char *base)
{
	int	len;

	len = -1;
	while (base && base[++len])
	{
		if (ft_strchr("+- \t\n\v\f\r", base[len]) != 0)
			return (0);
		if (ft_strchr(base + len + 1, base[len]) != 0)
			return (0);
	}
	return (len);
}

char	*ft_utoa(unsigned long n, const char *base)
{
	int		i;
	int		base_len;
	char	*rtn;

	base_len = baselen(base);
	if (base_len <= 0)
		return (0);
	i = numlen(n, base_len);
	rtn = (char *)ft_calloc(i + 1, sizeof(char));
	if (rtn == 0)
		return (0);
	rtn[0] = base[0];
	while (n)
	{
		rtn[--i] = base[n % base_len];
		n /= base_len;
	}
	return (rtn);
}
