/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   common.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjungk <minjungk@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 04:09:51 by minjungk          #+#    #+#             */
/*   Updated: 2023/05/31 20:46:52 by minjungk         ###   ########.fr       */
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
