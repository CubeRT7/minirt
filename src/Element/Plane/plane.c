/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjungk <minjungk@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 05:38:22 by minjungk          #+#    #+#             */
/*   Updated: 2023/06/09 19:25:43 by minjungk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "plane.h"

void	parse_debug_plane(void *param)
{
	struct s_plane *const	c = param;

	if (c == NULL || DEBUG == 0)
		return ;
	printf("%s: coordinate[%f, %f, %f]\n", __func__,
		c->raw.coordinate.x, c->raw.coordinate.y, c->raw.coordinate.z);
	printf("%s: axis[%f, %f, %f]\n", __func__,
		c->raw.axis.x, c->raw.axis.y, c->raw.axis.z);
	printf("%s: rgb[%d, %d, %d]\n", __func__,
		c->raw.rgb.r, c->raw.rgb.g, c->raw.rgb.b);
}

int	parse_plane(void *param, char **argv)
{
	struct s_plane *const	content = param;

	if (!argv || !argv[0] || !argv[1] || !argv[2])
		return (ft_error(__func__, __FILE__, __LINE__, EINVAL));
	content->type = Plane;
	if (parse_vector3(&content->raw.coordinate, argv[0], AllScope))
		return (ft_error(__func__, __FILE__, __LINE__, 0));
	if (parse_vector3(&content->raw.axis, argv[1], UnitScope))
		return (ft_error(__func__, __FILE__, __LINE__, 0));
	if (parse_rgb(&content->raw.rgb, argv[2]))
		return (ft_error(__func__, __FILE__, __LINE__, 0));
	parse_debug_plane(content);
	return (EXIT_SUCCESS);
}

void	*new_plane(void *param)
{
	t_plane *const	obj = ft_calloc(1, sizeof(t_plane));

	if (obj == NULL)
		return (NULL);
	(void)param;
	obj->type = Plane;
	return (obj);
}

void	destroy_plane(void *object)
{
	t_plane *const	obj = object;

	free(obj);
}

int	hit_plane(void *object, t_ray *ray)
{
	t_plane *const	obj = object;

	(void)obj;
	(void)ray;
	return (0);
}
