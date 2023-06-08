/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjungk <minjungk@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 05:36:34 by minjungk          #+#    #+#             */
/*   Updated: 2023/06/07 04:19:11 by minjungk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "camera.h"

void	parse_debug_camera(void *param)
{
	struct s_parsed_camera *const	c = param;

	if (c == NULL || DEBUG == 0)
		return ;
	printf("%s: coordinate[%f, %f, %f]\n", __func__,
		c->coordinate.x, c->coordinate.y, c->coordinate.z);
	printf("%s: axis[%f, %f, %f]\n", __func__, c->axis.x, c->axis.y, c->axis.z);
	printf("%s: fov[%f]\n", __func__, c->fov);
}

int	parse_camera(void *param, char **argv)
{
	char							*remain;
	struct s_parsed_camera *const	content = param;

	if (!argv || !argv[0] || !argv[1] || !argv[2])
		return (ft_error(__func__, __FILE__, __LINE__, EINVAL));
	if (parse_vector3(&content->coordinate, argv[0], Coordinate))
		return (ft_error(__func__, __FILE__, __LINE__, 0));
	if (parse_vector3(&content->axis, argv[1], Vector))
		return (ft_error(__func__, __FILE__, __LINE__, 0));
	content->fov = ft_strtof(argv[2], &remain);
	if (errno || (*remain != '\0' && ft_strchr("\r\n", *remain) == NULL))
		return (ft_error(__func__, __FILE__, __LINE__, EINVAL));
	if (!(0.0 <= content->fov && content->fov <= 180.0))
		return (ft_error(__func__, __FILE__, __LINE__, EINVAL));
	parse_debug_camera(content);
	return (EXIT_SUCCESS);
}
