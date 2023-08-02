/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_color_cylinder_bonus.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonshin <yonshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 06:55:17 by yonshin           #+#    #+#             */
/*   Updated: 2023/07/30 13:35:25 by yonshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cylinder.h"
#include "Element/util/element_util_bonus.h"

t_color	hit_color_cylinder_checker(t_cylinder *self, t_vector3 uv);
t_color	hit_color_cylinder_bumpmap(
			t_cylinder *self,
			t_vector3 uv,
			t_hit *record);

static double	_get_uv_ratio(t_cylinder *self)
{
	const double	total = self->radius * 2 + self->height;

	return (self->radius / total);
}

static t_color	_body(t_cylinder *self, t_vector3 world_point)
{
	const double	uv_ratio = _get_uv_ratio(self);
	const t_vector3	bottom_center = v3_sub(
			self->base.position,
			v3_mul(self->base.front, self->height * 0.5));
	const t_vector3	local = v3_sub(world_point, bottom_center);
	const t_vector3	dot = vector3(
			v3_dot(local, self->base.right),
			v3_dot(local, self->base.up),
			0);
	t_vector3		uv;

	uv.x = (atan(dot.y / dot.x) + M_PI_2) / M_PI;
	uv.y = v3_dot(self->base.front, local) / self->height;
	uv.y *= 1 - uv_ratio * 2;
	uv.y += uv_ratio;
	return (uv);
}

static t_color	_circle(
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
	uv.y = v3_magnitude(local) / circle.radius;
	if (is_top)
		uv.y = 1 - uv.y;
	uv.y *= uv_ratio;
	if (is_top)
		uv.y += (1 - uv_ratio);
	return (uv);
}

static t_vector3	_uv(t_cylinder *self, t_vector3 world_point, int hit)
{
	t_vector3	uv;

	uv = v3_preset(V3_ZERO);
	if (hit & HIT_BOTTOM)
		uv = _circle(self, world_point, self->bottom);
	else if (hit & HIT_TOP)
		uv = _circle(self, world_point, self->top);
	else if (hit & HIT_BODY)
		uv = _body(self, world_point);
	return (uv);
}

int	hit_color_cylinder(t_cylinder *self, t_hit *rec)
{
	const t_vector3	uv = _uv(self, rec->p, rec->hit_status);

	if (self->base.mapid)
		rec->color = hit_color_cylinder_bumpmap(self, uv, rec);
	else
		rec->color = hit_color_cylinder_checker(self, uv);
	return (EXIT_SUCCESS);
}
