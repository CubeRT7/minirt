/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ftoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjungk <minjungk@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 00:10:16 by minjungk          #+#    #+#             */
/*   Updated: 2023/07/13 00:39:06 by minjungk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libcustom.h"
#include <math.h>

static char	*_combine(char *integer, char *real)
{
	char	*dst;
	size_t	len[3];

	enum e_type {INT, REAL, DST};
	if (integer == NULL || real == NULL)
		return (NULL);
	len[INT] = ft_strlen(integer);
	len[REAL] = ft_strlen(real);
	len[DST] = len[INT] + 1 + len[REAL];
	dst = ft_calloc(len[DST] + 1, sizeof(char));
	if (dst == NULL)
		return (NULL);
	ft_strlcpy(dst, integer, len[DST] + 1);
	dst[len[INT]] = '.';
	ft_strlcpy(dst + len[INT] + 1, real, len[DST] + 1);
	return (dst);
}

char	*ft_ftoa(float f, int digit)
{
	double			integer;
	const double	real = modf(f, &integer);
	const double	precision = pow(10, (double)digit);
	char			*tmp[2];
	char			*rtn;

	tmp[0] = ft_itoa((int)integer);
	if (real < 0)
		tmp[1] = ft_itoa((int)(-real * precision));
	else
		tmp[1] = ft_itoa((int)(real * precision));
	rtn = _combine(tmp[0], tmp[1]);
	free(tmp[0]);
	free(tmp[1]);
	return (rtn);
}
