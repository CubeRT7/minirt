/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_cylinder.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjungk <minjungk@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 05:38:49 by minjungk          #+#    #+#             */
/*   Updated: 2023/07/07 05:52:07 by minjungk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Element/Cylinder/cylinder.h"

static int	_debug_cylinder(void *param)
{
	struct s_cylinder *const	c = param;

	if (c == NULL || DEBUG == 0)
		return (EXIT_SUCCESS);
	printf("%s: coordinate[%f, %f, %f]\n", __func__,
		c->raw.coordinate.x, c->raw.coordinate.y, c->raw.coordinate.z);
	printf("%s: axis[%f, %f, %f]\n", __func__,
		c->raw.axis.x, c->raw.axis.y, c->raw.axis.z);
	printf("%s: diameter[%f]\n", __func__, c->raw.diameter);
	printf("%s: height[%f]\n", __func__, c->raw.height);
	printf("%s: rgb[%d, %d, %d]\n", __func__,
		c->raw.rgb.r, c->raw.rgb.g, c->raw.rgb.b);
	return (EXIT_SUCCESS);
}

int	parse_cylinder(void *param, char **argv)
{
	char						*remain;
	struct s_cylinder *const	content = param;

	if (!argv || !argv[0] || !argv[1] || !argv[2] || !argv[3] || !argv[4])
		return (ft_error(__func__, __FILE__, __LINE__, EINVAL));
	content->base.type = Cylinder;
	if (parse_vector3(&content->raw.coordinate, argv[0], AllScope))
		return (ft_error(__func__, __FILE__, __LINE__, 0));
	if (parse_vector3(&content->raw.axis, argv[1], UnitScope))
		return (ft_error(__func__, __FILE__, __LINE__, 0));
	content->raw.diameter = ft_strtof(argv[2], &remain);
	if (errno || (*remain != '\0' && ft_strchr("\r\n", *remain) == NULL))
		return (ft_error(__func__, __FILE__, __LINE__, EINVAL));
	content->raw.height = ft_strtof(argv[3], &remain);
	if (errno || (*remain != '\0' && ft_strchr("\r\n", *remain) == NULL))
		return (ft_error(__func__, __FILE__, __LINE__, EINVAL));
	if (parse_rgb(&content->raw.rgb, argv[4]))
		return (ft_error(__func__, __FILE__, __LINE__, 0));
	_debug_cylinder(content);
	return (EXIT_SUCCESS);
}
