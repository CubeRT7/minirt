/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_color_sphere_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonshin <yonshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 06:55:17 by yonshin           #+#    #+#             */
/*   Updated: 2023/07/30 13:36:23 by yonshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sphere.h"
#include "Element/util/element_util_bonus.h"

t_color	hit_color_sphere_checker(t_sphere *self, t_vector3 uv);
t_color	hit_color_sphere_bumpmap(t_sphere *self, t_vector3 uv, t_vector3 *norm);

static t_vector3	_uv(t_sphere *self, t_vector3 world_point)
{
	const t_vector3	local = v3_sub(world_point, self->base.position);
	const t_vector3	point = v3_mul(local, 1 / self->radius);
	const t_vector3	local_axis = vector3(
			v3_dot(point, self->base.right),
			v3_dot(point, self->base.up),
			v3_dot(point, self->base.front));
	const t_vector3	uv = vector3(
			(atan(local_axis.z / local_axis.x) + M_PI_2) / M_PI,
			acos(local_axis.y) / M_PI,
			0);

	return (uv);
}

int	hit_color_sphere(t_sphere *self, t_hit *rec)
{
	const t_vector3	uv = _uv(self, rec->p);

	if (self->base.mapid)
		rec->color = hit_color_sphere_bumpmap(self, uv, &(rec->normal));
	else
		rec->color = hit_color_sphere_checker(self, uv);
	return (EXIT_SUCCESS);
}
