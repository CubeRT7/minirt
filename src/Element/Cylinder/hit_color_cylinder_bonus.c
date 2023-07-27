/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_color_cylinder_bonus.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonshin <yonshin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 06:55:17 by yonshin           #+#    #+#             */
/*   Updated: 2023/07/26 06:55:20 by yonshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cylinder.h"
#include "Element/util/element_util_bonus.h"
#define DENSITY 4

static double	_get_uv_ratio(t_cylinder *self)
{
	const double	total = self->obj.radius * 2 + self->obj.height;

	return (self->obj.radius / total);
}

static t_color	_checkerboard_body(t_cylinder *self, t_vector3 world_point)
{
	const double	uv_ratio = _get_uv_ratio(self);
	const t_vector3	bottom_center = v3_sub(
			self->base.position,
			v3_mul(self->base.front, self->obj.height * 0.5));
	const t_vector3	local = v3_sub(world_point, bottom_center);
	const t_vector3	dot = vector3(
			v3_dot(local, self->base.right),
			v3_dot(local, self->base.up),
			0);
	t_vector3		uv;

	uv.x = (atan(dot.y / dot.x) + M_PI_2) / M_PI;
	uv.x *= DENSITY;
	uv.y = v3_dot(self->base.front, local) / self->obj.height;
	uv.y *= 1 - uv_ratio * 2;
	uv.y += uv_ratio;
	uv.y *= DENSITY;
	return (get_checkerboard_color(self->base.color, uv.x, uv.y));
}

static t_color	_checkerboard_circle(
	t_cylinder *self,
	t_vector3 world_point,
	t_circle circle)
{
	const double	uv_ratio = _get_uv_ratio(self);
	const t_vector3	local = v3_sub(world_point, circle.center);
	const t_vector3	dot = vector3(
			v3_dot(local, self->base.right),
			v3_dot(local, self->base.up),
			0);
	const double	is_top = v3_dot(self->base.front, circle.axis) > 0;
	t_vector3		uv;

	uv.x = (atan(dot.y / dot.x) + M_PI_2) / M_PI;
	uv.x *= DENSITY;
	uv.y = v3_magnitude(local) / circle.radius;
	if (is_top)
		uv.y = 1 - uv.y;
	uv.y *= uv_ratio;
	if (is_top)
		uv.y += (1 - uv_ratio);
	uv.y *= DENSITY;
	return (get_checkerboard_color(self->base.color, uv.x, uv.y));
}

int	hit_color_cylinder(t_cylinder *self, t_hit *record)
{
	if (record->hit_status & HIT_BOTTOM)
		record->color = _checkerboard_circle(self, record->p, self->obj.bottom);
	else if (record->hit_status & HIT_TOP)
		record->color = _checkerboard_circle(self, record->p, self->obj.top);
	else if (record->hit_status & HIT_BODY)
		record->color = _checkerboard_body(self, record->p);
	return (EXIT_SUCCESS);
}
