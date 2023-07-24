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

	// TODO
	// t_vector3 p = v3_sub(record->p, self->base.position);
	// t_vector3 uv = v3_mul(p, sqrt(v3_dot(p, p)) * 30);
	// record->color = get_checkerboard_color(vector3(1, 1, 1), uv.x, uv.y);

	return (1);
}
