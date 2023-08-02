/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_sphere.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonshin <yonshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/02 02:11:24 by yonshin           #+#    #+#             */
/*   Updated: 2023/07/28 20:59:44 by yonshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sphere.h"

int	hit_sphere(t_sphere *self, t_ray *ray, t_range range, t_hit *record)
{
	const t_vector3	dir = ray->direction;
	const t_vector3	oc = v3_sub(ray->origin, self->base.position);
	const t_abc		abc = (t_abc){
		v3_dot(dir, dir),
		v3_dot(oc, ray->direction),
		v3_dot(oc, oc) - self->radius * self->radius
	};

	if (quadratic_formula_root(abc, range, &(record->t)) == NO_VALUE)
		return (0);
	record->p = get_ray_point(ray, record->t);
	record->normal = v3_normalize(v3_sub(record->p, self->base.position));
	record->normal = get_face_normal(*ray, record->normal);
	record->hit_status = HIT;
	return (HIT);
}
