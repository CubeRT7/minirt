/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   common.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjungk <minjungk@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 04:09:51 by minjungk          #+#    #+#             */
/*   Updated: 2023/06/01 02:36:39 by minjungk         ###   ########.fr       */
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
