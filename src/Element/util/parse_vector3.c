/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_vector3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonshin <yonshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 14:30:01 by yonshin           #+#    #+#             */
/*   Updated: 2023/08/02 02:00:28 by minjungk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse_util.h"

int	parse_vector3(t_vector3 *vector, char *curr, int scope)
{
	double	axis_len;

	vector->x = ft_strtof(curr, &curr);
	if (errno || curr[0] != ',')
		return (ft_error(__func__, __FILE__, __LINE__, EINVAL));
	vector->y = ft_strtof(curr + 1, &curr);
	if (errno || curr[0] != ',')
		return (ft_error(__func__, __FILE__, __LINE__, EINVAL));
	vector->z = ft_strtof(curr + 1, &curr);
	if (errno || (curr[0] != '\0' && ft_strchr("\r\n", curr[0]) == NULL))
		return (ft_error(__func__, __FILE__, __LINE__, EINVAL));
	if (scope == AllScope)
		return (EXIT_SUCCESS);
	if (!((-1.0 <= vector->x && vector->x <= 1.0)
			&& (-1.0 <= vector->y && vector->y <= 1.0)
			&& (-1.0 <= vector->z && vector->z <= 1.0)))
		return (ft_error(__func__, __FILE__, __LINE__, EINVAL));
	axis_len = v3_magnitude(*vector);
	if (!(0.9 < axis_len && axis_len < 1.1))
		return (ft_error(__func__, __FILE__, __LINE__, EINVAL));
	return (EXIT_SUCCESS);
}
