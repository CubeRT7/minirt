/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   common.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjungk <minjungk@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 04:09:51 by minjungk          #+#    #+#             */
/*   Updated: 2023/06/05 06:57:25 by minjungk         ###   ########.fr       */
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
	if (curr[0] != '\0' && ft_strchr(",\r\n", curr[0]) == NULL)
		return (NULL);
	return (curr);
}

int	parse_rgb(struct s_rgb *rgb, char *curr)
{
	curr = next_rgb(&rgb->r, curr);
	if (curr == NULL || curr[0] != ',')
		return (ft_error(__func__, __FILE__, __LINE__, EINVAL));
	curr = next_rgb(&rgb->g, curr + 1);
	if (curr == NULL || curr[0] != ',')
		return (ft_error(__func__, __FILE__, __LINE__, EINVAL));
	curr = next_rgb(&rgb->b, curr + 1);
	if (curr == NULL || (curr[0] != '\0' && ft_strchr("\r\n", curr[0]) == NULL))
		return (ft_error(__func__, __FILE__, __LINE__, EINVAL));
	return (EXIT_SUCCESS);
}

int	parse_vector3(struct s_vector4 *vector, char *curr, float w)
{
	vector->x = ft_strtof(curr, &curr);
	if (errno || curr[0] != ',')
		return (ft_error(__func__, __FILE__, __LINE__, EINVAL));
	vector->y = ft_strtof(curr + 1, &curr);
	if (errno || curr[0] != ',')
		return (ft_error(__func__, __FILE__, __LINE__, EINVAL));
	vector->z = ft_strtof(curr + 1, &curr);
	if (errno || (curr[0] != '\0' && ft_strchr("\r\n", curr[0]) == NULL))
		return (ft_error(__func__, __FILE__, __LINE__, EINVAL));
	vector->w = w;
	if (w != Vector)
		return (EXIT_SUCCESS);
	if ((-1.0 <= vector->x && vector->x <= 1.0)
		&& (-1.0 <= vector->y && vector->y <= 1.0)
		&& (-1.0 <= vector->z && vector->z <= 1.0))
		return (EXIT_SUCCESS);
	return (ft_error(__func__, __FILE__, __LINE__, EINVAL));
}
