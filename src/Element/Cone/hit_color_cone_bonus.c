/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_color_cone_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonshin <yonshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 06:55:17 by yonshin           #+#    #+#             */
/*   Updated: 2023/07/31 19:19:51 by yonshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cone_bonus.h"
#include "Element/util/element_util_bonus.h"

t_color	hit_color_cone_checker(t_cone *self, t_vector3 uv);
t_color	hit_color_cone_bumpmap(
			t_cone *self,
			t_vector3 uv,
			t_hit *record);

static t_color	_body(t_cone *self, t_vector3 world_point)
{
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
	uv.y *= 1 - self->uv_ratio;
	uv.y += self->uv_ratio;
	return (uv);
}

static t_color	_circle(
	t_cone *self,
	t_vector3 world_point,
	t_circle circle)
{
	const t_vector3	local = v3_sub(world_point, circle.center);
	const t_vector3	dot = vector3(
			v3_dot(local, self->base.right),
			v3_dot(local, self->base.up),
			0);
	t_vector3		uv;

	uv.x = (atan(dot.y / dot.x) + M_PI_2) / M_PI;
	uv.y = v3_magnitude(local) / circle.radius;
	uv.y *= self->uv_ratio;
	return (uv);
}

static t_vector3	_uv(t_cone *self, t_vector3 world_point, int hit)
{
	t_vector3	uv;

	uv = v3_preset(V3_ZERO);
	if (hit & HIT_BOTTOM)
		uv = _circle(self, world_point, self->bottom);
	else if (hit & HIT_BODY)
		uv = _body(self, world_point);
	return (uv);
}

int	hit_color_cone(t_cone *self, t_hit *rec)
{
	const t_vector3	uv = _uv(self, rec->p, rec->hit_status);

	if (self->base.mapid)
		rec->color = hit_color_cone_bumpmap(self, uv, rec);
	else
		rec->color = hit_color_cone_checker(self, uv);
	return (EXIT_SUCCESS);
}
