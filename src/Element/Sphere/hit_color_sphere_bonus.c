/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_color_sphere_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonshin <yonshin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 06:55:17 by yonshin           #+#    #+#             */
/*   Updated: 2023/07/26 06:55:20 by yonshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sphere.h"
#include "Element/util/element_util_bonus.h"

static t_color	_checkerboard(t_sphere *self, t_vector3 world_point)
{
	const t_vector3	local = v3_sub(world_point, self->base.position);
	const t_vector3	point = v3_mul(local, 1 / self->obj.radius);
	const t_vector3	local_axis = vector3(
			v3_dot(point, self->base.right),
			v3_dot(point, self->base.up),
			v3_dot(point, self->base.front));
	const double	plane_x = (atan(local_axis.z / local_axis.x) + M_PI_2) / M_PI * 4;
	const double	plane_y = acos(local_axis.y) / M_PI * 4;

	return (get_checkerboard_color(self->base.color, plane_x, plane_y));
}

int	hit_color_sphere(t_sphere *self, t_hit *record)
{
	record->color = _checkerboard(self, record->p);
	return (EXIT_SUCCESS);
}
