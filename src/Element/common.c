/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   common.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjungk <minjungk@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 04:09:51 by minjungk          #+#    #+#             */
/*   Updated: 2023/06/02 20:21:32 by minjungk         ###   ########.fr       */
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
	if (curr[0] != '\0' && curr[0] != '\r' && curr[0] != ',')
		return (NULL);
	return (curr);
}

int	parse_rgb(struct s_rgb *rgb, char *curr)
{
	errno = EINVAL;
	curr = next_rgb(&rgb->r, curr);
	if (curr == NULL || curr[0] != ',')
		return (EXIT_FAILURE);
	curr = next_rgb(&rgb->g, curr + 1);
	if (curr == NULL || curr[0] != ',')
		return (EXIT_FAILURE);
	curr = next_rgb(&rgb->b, curr + 1);
	if (curr == NULL || (curr[0] != '\0' && curr[0] != '\r'))
		return (EXIT_FAILURE);
	errno = 0;
	return (EXIT_SUCCESS);
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
	if (w != Vector)
		return (EXIT_SUCCESS);
	if ((-1.0 <= vector->x && vector->x <= 1.0)
		&& (-1.0 <= vector->y && vector->y <= 1.0)
		&& (-1.0 <= vector->z && vector->z <= 1.0))
		return (EXIT_SUCCESS);
	errno = EINVAL;
	return (EXIT_FAILURE);
}