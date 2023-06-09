/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjungk <minjungk@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 05:36:34 by minjungk          #+#    #+#             */
/*   Updated: 2023/06/09 19:25:34 by minjungk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "camera.h"

void	parse_debug_camera(void *param)
{
	struct s_camera *const	c = param;

	if (c == NULL || DEBUG == 0)
		return ;
	printf("%s: coordinate[%f, %f, %f]\n", __func__,
		c->raw.coordinate.x, c->raw.coordinate.y, c->raw.coordinate.z);
	printf("%s: axis[%f, %f, %f]\n", __func__,
		c->raw.axis.x, c->raw.axis.y, c->raw.axis.z);
	printf("%s: fov[%f]\n", __func__, c->raw.fov);
}

int	parse_camera(void *param, char **argv)
{
	char					*remain;
	struct s_camera *const	content = param;

	if (!argv || !argv[0] || !argv[1] || !argv[2])
		return (ft_error(__func__, __FILE__, __LINE__, EINVAL));
	content->type = Camera;
	if (parse_vector3(&content->raw.coordinate, argv[0], AllScope))
		return (ft_error(__func__, __FILE__, __LINE__, 0));
	if (parse_vector3(&content->raw.axis, argv[1], UnitScope))
		return (ft_error(__func__, __FILE__, __LINE__, 0));
	content->raw.fov = ft_strtof(argv[2], &remain);
	if (errno || (*remain != '\0' && ft_strchr("\r\n", *remain) == NULL))
		return (ft_error(__func__, __FILE__, __LINE__, EINVAL));
	if (!(0.0 <= content->raw.fov && content->raw.fov <= 180.0))
		return (ft_error(__func__, __FILE__, __LINE__, EINVAL));
	parse_debug_camera(content);
	return (EXIT_SUCCESS);
}

void	*new_camera(void *param)
{
	t_camera *const	obj = ft_calloc(1, sizeof(t_camera));

	if (obj == NULL)
		return (NULL);
	(void)param;
	obj->type = Camera;
	return (obj);
}

void	destroy_camera(void *object)
{
	t_camera *const	obj = object;

	free(obj);
}

int	hit_camera(void *object, t_ray *ray)
{
	t_camera *const	obj = object;

	(void)obj;
	(void)ray;
	return (0);
}
