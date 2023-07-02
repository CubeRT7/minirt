/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_sphere.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonshin <yonshin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/02 02:11:24 by yonshin           #+#    #+#             */
/*   Updated: 2023/07/02 02:31:42 by yonshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sphere.h"
#include "material/material.h"

static t_vector3	set_face_normal(t_ray ray, t_vector3 normal)
{
	const int	front_face = v3_dot_prod(ray.direction, normal) < 0;

	if (front_face)
		return (normal);
	return (v3_reverse(normal));
}

int	hit_sphere(void *this, t_ray *ray, t_range range, t_hit *record)
{
	t_sphere *const sphere = this;
	const t_point center = sphere->obj.position;
	const float radius = sphere->obj.radius;

	t_vector3 oc = v3_sub(ray->origin, center);
	float a = v3_magnitude(ray->direction) * v3_magnitude(ray->direction);
	float half_b = v3_dot_prod(oc, ray->direction);
	float c = v3_magnitude(oc) * v3_magnitude(oc) - radius * radius;
	float discrimiant = half_b * half_b - a * c;
	if (discrimiant < 0)
		return 0;

	float sqrtd = sqrt(discrimiant);
	float root = (-half_b - sqrtd) / a;
	
	if (root < range.min || root > range.max) {
		root = (-half_b + sqrtd) / a;
		if (root < range.min || root > range.max)
			return 0;
	}
	
	record->t = root;
	record->p = v3_add(v3_mul(v3_normalize(ray->direction), root), ray->origin);
	record->normal = v3_normalize(v3_mul(v3_sub(record->p, center), 1 / radius));
	record->normal = set_face_normal(*ray, record->normal);
	record->scatter = scatter(PHONG);
	return 1;
}
