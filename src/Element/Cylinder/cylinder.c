/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjungk <minjungk@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 05:38:49 by minjungk          #+#    #+#             */
/*   Updated: 2023/06/05 06:07:27 by minjungk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cylinder.h"

void	debug_cylinder(void *param)
{
	struct s_cylinder *const	c = param;

	if (c == NULL || DEBUG == 0)
		return ;
	printf("%s: coordinate[%f, %f, %f]\n", __func__,
		c->coordinate.x, c->coordinate.y, c->coordinate.z);
	printf("%s: axis[%f, %f, %f]\n", __func__, c->axis.x, c->axis.y, c->axis.z);
	printf("%s: diameter[%f]\n", __func__, c->diameter);
	printf("%s: height[%f]\n", __func__, c->height);
	printf("%s: rgb[%d, %d, %d]\n", __func__, c->rgb.r, c->rgb.g, c->rgb.b);
}

int	parse_cylinder(void *param, char **argv)
{
	struct s_cylinder *const	content = param;

	errno = EINVAL;
	if (!argv || !argv[0] || !argv[1] || !argv[2] || !argv[3] || !argv[4])
		return (ft_error(__func__, __FILE__, __LINE__));
	if (parse_vector3(&content->coordinate, argv[0], Coordinate)
		|| parse_vector3(&content->axis, argv[1], Vector))
		return (ft_error(__func__, __FILE__, __LINE__));
	content->diameter = ft_strtof(argv[2], NULL);
	content->height = ft_strtof(argv[3], NULL);
	if (parse_rgb(&content->rgb, argv[4]))
		return (ft_error(__func__, __FILE__, __LINE__));
	debug_cylinder(content);
	errno = 0;
	return (EXIT_SUCCESS);
}
