/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtod.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjungk <minjungk@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 02:35:44 by minjungk          #+#    #+#             */
/*   Updated: 2023/06/01 03:29:10 by minjungk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libcustom.h"

static float	_exponent(const char *nptr, char **endptr)
{
	float	rtn;

	rtn = 0;
	while (ft_isdigit(*nptr))
	{
		rtn = rtn * 10.0 + (*nptr - '0');
		++nptr;
	}
	if (endptr)
		*endptr = (char *)nptr;
	return (rtn);
}

static float	_mantissa(const char *nptr, char **endptr)
{
	float	rtn;
	float	factor;

	rtn = 0;
	factor = 0.1;
	while (ft_isdigit(*nptr))
	{
		rtn += factor * (*nptr - '0');
		factor *= 0.1;
		++nptr;
	}
	if (endptr)
		*endptr = (char *)nptr;
	return (rtn);
}

float	ft_strtof(const char *nptr, char **endptr)
{
	char	*curr;
	float	rtn;
	float	sign;

	curr = (char *)nptr;
	while ((9 <= *curr && *curr <= 13) || *curr == ' ')
		++curr;
	sign = 1.0;
	if (*curr == '+')
		++curr;
	else if (*curr == '-')
	{
		++curr;
		sign = -1.0;
	}
	rtn = _exponent(curr, &curr);
	if (*curr == '.')
		rtn += _mantissa(curr + 1, &curr);
	if (endptr)
		*endptr = (char *)curr;
	return (rtn * sign);
}
