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
#define DENSITY 4

static t_color	_checkerboard(t_sphere *self, t_vector3 world_point)
{
	const t_vector3	local = v3_sub(world_point, self->base.position);
	const t_vector3	point = v3_mul(local, 1 / self->obj.radius);
	const t_vector3	local_axis = vector3(
			v3_dot(point, self->base.right),
			v3_dot(point, self->base.up),
			v3_dot(point, self->base.front));
	const t_vector3	uv = vector3(
			(atan(local_axis.z / local_axis.x) + M_PI_2) / M_PI * DENSITY,
			acos(local_axis.y) / M_PI * DENSITY,
			0);

	return (get_checkerboard_color(self->base.color, uv.x, uv.y));
}

int	hit_color_sphere(t_sphere *self, t_hit *record)
{
	record->color = _checkerboard(self, record->p);
	return (EXIT_SUCCESS);
}
