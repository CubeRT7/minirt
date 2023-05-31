/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   common.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjungk <minjungk@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 04:09:51 by minjungk          #+#    #+#             */
/*   Updated: 2023/06/01 01:48:20 by minjungk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"

static char	*next_rgb(int *buf, char *curr)
{
	if (curr == NULL || ft_isdigit(curr[0]) == 0)
		return (NULL);
	*buf = ft_atoi(curr);
	if (!(0 <= *buf && *buf <= 255))
		return (NULL);
	while (ft_isdigit(curr[0]))
		++curr;
	if (curr[0] != '\0' && curr[0] != ',')
		return (NULL);
	return (curr);
}

int	parse_rgb(struct s_rgb *rgb, char *curr)
{
	curr = next_rgb(&rgb->r, curr);
	if (curr == NULL || curr[0] != ',')
		return (EXIT_FAILURE);
	curr = next_rgb(&rgb->g, curr + 1);
	if (curr == NULL || curr[0] != ',')
		return (EXIT_FAILURE);
	curr = next_rgb(&rgb->b, curr + 1);
	if (curr == NULL || curr[0] != '\0')
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

static float	ft_strtof(const char *nptr, char **endptr)
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

int	parse_vector3(struct s_vector4 *vector, char *curr, float w)
{
	errno = 0;
	vector->x = ft_strtof(curr, &curr);
	if (errno || curr[0] != ',')
		return (EXIT_FAILURE);
	vector->y = ft_strtof(curr + 1, &curr);
	if (errno || curr[0] != ',')
		return (EXIT_FAILURE);
	vector->z = ft_strtof(curr + 1, &curr);
	if (errno || curr[0] != '\0')
		return (EXIT_FAILURE);
	vector->w = w;
	return (EXIT_SUCCESS);
}
