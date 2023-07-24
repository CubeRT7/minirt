/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_sphere_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonshin <yonshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/02 02:11:24 by yonshin           #+#    #+#             */
/*   Updated: 2023/07/05 07:08:28 by yonshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sphere.h"
#include "Element/util/element_util_bonus.h"

static t_color	_checkerboard(t_sphere *self, t_vector3 world_point)
{
	const t_vector3	local = v3_sub(world_point, self->base.position);
	const t_vector3	point = v3_mul(local, 1 / self->obj.radius);
	const t_vector3	dot = vector3(
			v3_dot(point, self->base.right),
			v3_dot(point, self->base.up),
			v3_dot(point, self->base.front));
	const double	plane_x = (atan(dot.z / dot.x) + M_PI_2) / M_PI * 4;
	const double	plane_y = acos(dot.y) / M_PI * 4;

	return (get_checkerboard_color(self->base.color, plane_x, plane_y));
}

int	hit_sphere(t_sphere *self, t_ray *ray, t_range range, t_hit *record)
{
	const t_vector3	dir = ray->direction;
	const t_vector3	oc = v3_sub(ray->origin, self->base.position);
	const t_abc		abc = (t_abc){
		v3_dot(dir, dir),
		v3_dot(oc, ray->direction),
		v3_dot(oc, oc) - self->obj.radius * self->obj.radius
	};

	if (quadratic_formula_root(abc, range, &(record->t)) == NO_VALUE)
		return (0);
	record->p = get_ray_point(ray, record->t);
	record->normal = v3_normalize(v3_sub(record->p, self->base.position));
	record->normal = get_face_normal(*ray, record->normal);
	record->color = _checkerboard(self, record->p);
	return (1);
}
