/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_plane.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonshin <yonshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/02 02:10:05 by yonshin           #+#    #+#             */
/*   Updated: 2023/07/05 07:09:05 by yonshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "plane.h"

int	hit_plane(void *elem, t_ray *ray, t_range range, t_hit *record)
{
	t_plane *const	this = elem;
	const t_point	position = this->obj.position;
	const t_vector3	axis = this->obj.axis;
	const float		d = v3_dot_prod(ray->direction, axis);
	if (d > -0.001f && d < 0.001f)
		return (0);
	const t_vector3 v2 = v3_sub(ray->origin, position);
	const float t = -v3_dot_prod(v2, axis) / d;
	if (t < 0.001f || t < range.min || t > range.max)
		return (0);
	record->t = t;
	record->p = get_ray_point(ray, t);
	record->normal = axis;
	record->normal = get_face_normal(*ray, record->normal);
	return (1);
}	
