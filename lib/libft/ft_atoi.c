/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjungk <minjungk@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 20:10:10 by minjungk          #+#    #+#             */
/*   Updated: 2022/12/18 22:53:45 by minjungk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static long	isflow(unsigned long num, char c, int minus)
{
	if (num > INT_MAX / 10 || (num == INT_MAX / 10 && (c > '7' + minus)))
		errno = ERANGE;
	if (num > LONG_MAX / 10 || (num == LONG_MAX / 10 && (c > '7' + minus)))
	{
		if (minus)
			return (LONG_MIN);
		else
			return (LONG_MAX);
	}
	return (0);
}

int	ft_atoi(const char *str)
{
	unsigned long	rtn;
	int				minus;
	long			flow;

	rtn = 0;
	minus = 0;
	while ((9 <= *str && *str <= 13) || *str == ' ')
		++str;
	if (*str == '+' || *str == '-')
		minus = *str++ == '-';
	while ('0' <= *str && *str <= '9')
	{
		flow = isflow(rtn, *str, minus);
		if (flow)
			return ((int)flow);
		rtn = rtn * 10 + *str++ - '0';
	}
	if (minus)
		return (-rtn);
	return (rtn);
}
