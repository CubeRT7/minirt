/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjungk <minjungk@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 05:38:49 by minjungk          #+#    #+#             */
/*   Updated: 2023/06/09 18:46:41 by minjungk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cylinder.h"

void	parse_debug_cylinder(void *param)
{
	struct s_parsed_cylinder *const	c = param;

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
	char							*remain;
	struct s_parsed_cylinder *const	content = param;

	if (!argv || !argv[0] || !argv[1] || !argv[2] || !argv[3] || !argv[4])
		return (ft_error(__func__, __FILE__, __LINE__, EINVAL));
	if (parse_vector3(&content->coordinate, argv[0], AllScope))
		return (ft_error(__func__, __FILE__, __LINE__, 0));
	if (parse_vector3(&content->axis, argv[1], UnitScope))
		return (ft_error(__func__, __FILE__, __LINE__, 0));
	content->diameter = ft_strtof(argv[2], &remain);
	if (errno || (*remain != '\0' && ft_strchr("\r\n", *remain) == NULL))
		return (ft_error(__func__, __FILE__, __LINE__, EINVAL));
	content->height = ft_strtof(argv[3], &remain);
	if (errno || (*remain != '\0' && ft_strchr("\r\n", *remain) == NULL))
		return (ft_error(__func__, __FILE__, __LINE__, EINVAL));
	if (parse_rgb(&content->rgb, argv[4]))
		return (ft_error(__func__, __FILE__, __LINE__, 0));
	parse_debug_cylinder(content);
	return (EXIT_SUCCESS);
}

void	*new_cylinder(void *param)
{
	t_cylinder *const	obj = ft_calloc(1, sizeof(t_cylinder));

	if (obj == NULL)
		return (NULL);
	(void)param;
	obj->type = Cylinder;
	return (obj);
}

void	destroy_cylinder(void *object)
{
	t_cylinder *const	obj = object;

	free(obj);
}

int	hit_cylinder(void *object, t_ray *ray)
{
	t_cylinder *const	obj = object;

	(void)obj;
	(void)ray;
	return (0);
}
