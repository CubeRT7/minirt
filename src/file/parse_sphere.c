/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_sphere.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonshin <yonshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 05:37:44 by minjungk          #+#    #+#             */
/*   Updated: 2023/07/28 14:04:04 by yonshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "file_private.h"
#include "../Element/Sphere/sphere.h"

static int	_debug_sphere(void *param)
{
	struct s_sphere *const	c = param;

	if (c == NULL || DEBUG == 0)
		return (EXIT_SUCCESS);
	printf("%s: coordinate[%f, %f, %f]\n", __func__,
		c->raw.coordinate.x, c->raw.coordinate.y, c->raw.coordinate.z);
	printf("%s: diameter[%f]\n", __func__, c->raw.diameter);
	printf("%s: rgb[%d, %d, %d]\n", __func__,
		c->raw.rgb.r, c->raw.rgb.g, c->raw.rgb.b);
	return (EXIT_SUCCESS);
}

int	parse_sphere(void *param, char **argv)
{
	char					*remain;
	struct s_sphere *const	content = param;

	if (!argv || !argv[0] || !argv[1] || !argv[2])
		return (ft_error(__func__, __FILE__, __LINE__, EINVAL));
	content->base.type = Sphere;
	if (parse_vector3(&content->raw.coordinate, argv[0], AllScope))
		return (ft_error(__func__, __FILE__, __LINE__, 0));
	content->raw.diameter = ft_strtof(argv[1], &remain);
	if (errno || (*remain != '\0' && ft_strchr("\r\n", *remain) == NULL))
		return (ft_error(__func__, __FILE__, __LINE__, EINVAL));
	if (parse_rgb(&content->raw.rgb, argv[2]))
		return (ft_error(__func__, __FILE__, __LINE__, 0));
	_debug_sphere(content);
	return (EXIT_SUCCESS);
}
