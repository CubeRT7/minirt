/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtod.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjungk <minjungk@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 02:35:44 by minjungk          #+#    #+#             */
/*   Updated: 2023/06/01 02:38:12 by minjungk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libcustom.h"

float	ft_strtof(const char *nptr, char **endptr)
{
	float	rtn;
	float	factor;
	int		is_negative;

	while ((9 <= *nptr && *nptr <= 13) || *nptr == ' ')
		++nptr;
	if (*nptr == '+' || *nptr == '-')
		is_negative = *nptr++ == '-';
	rtn = 0;
	while (ft_isdigit(*nptr))
		rtn = rtn * 10.0 + (*nptr++ - '0');
	if (*nptr == '.')
	{
		factor = 0.1;
		while (ft_isdigit(*++nptr))
		{
			rtn = rtn * 10.0 + (*nptr - '0');
			factor *= 0.1;
		}
	}
	if (endptr)
		*endptr = (char *)&nptr;
	if (is_negative)
		return (-rtn);
	return (rtn);
}
