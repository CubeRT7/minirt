/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_plane_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonshin <yonshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/02 02:10:05 by yonshin           #+#    #+#             */
/*   Updated: 2023/07/05 07:09:05 by yonshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "plane.h"
#include "Element/util/element_util_bonus.h"

static t_color	_checkerboard(t_plane *self, t_vector3 world_point)
{
	static const double	rate = 0.1;
	const t_vector3		local = v3_sub(world_point, self->base.position);
	const t_vector3		right = self->base.right;
	const t_vector3		up = self->base.up;
	const t_vector3		uv = vector3(
			v3_dot(local, right) * rate,
			v3_dot(local, up) * rate,
			0);

	return (get_checkerboard_color(self->base.color, uv.x, uv.y));
}

int	hit_plane(t_plane *self, t_ray *ray, t_range range, t_hit *record)
{
	double		d;
	double		t;
	t_vector3	v;

	d = v3_dot(ray->direction, self->base.front);
	if (close_to_zero(d))
		return (0);
	v = v3_sub(ray->origin, self->base.position);
	t = -v3_dot(v, self->base.front) / d;
	if (range_not_in(t, range))
		return (0);
	record->t = t;
	record->p = get_ray_point(ray, t);
	record->normal = get_face_normal(*ray, self->base.front);
	record->color = _checkerboard(self, record->p);
	return (1);
}	
