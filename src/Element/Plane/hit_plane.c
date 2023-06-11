/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_plane.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonshin <yonshin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/02 02:10:05 by yonshin           #+#    #+#             */
/*   Updated: 2023/07/02 02:19:22 by yonshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "plane.h"
#include "material/material.h"

static t_vector3	set_face_normal(t_ray ray, t_vector3 normal)
{
	const int	front_face = v3_dot_prod(ray.direction, normal) < 0;

	if (front_face)
		return (normal);
	return (v3_reverse(normal));
}

int	hit_plane(void *elem, t_ray *ray, t_range range, t_hit *record)
{
	t_plane *const	this = elem;
	const t_point	coordinate = this->raw.coordinate;
	const t_vector3	axis = v3_normalize(this->raw.axis);
	const float		d = v3_dot_prod(ray->direction, axis);
	if (d > -0.001f && d < 0.001f)
		return (0);
	const t_vector3 v2 = v3_sub(ray->origin, coordinate);
	const float t = -v3_dot_prod(v2, axis) / d;
	if (t < 0.001f || t < range.min || t > range.max)
		return (0);
	record->t = t;
	record->p = v3_add(v3_mul(v3_normalize(ray->direction), t), ray->origin);
	record->normal = axis;
	record->normal = set_face_normal(*ray, record->normal);
	record->scatter = scatter(PHONG);
	return (1);
}	
