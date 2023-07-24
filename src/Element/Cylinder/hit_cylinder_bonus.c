/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_cylinder_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonshin <yonshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/02 02:08:42 by yonshin           #+#    #+#             */
/*   Updated: 2023/07/07 05:49:15 by minjungk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cylinder.h"
#include "Element/util/element_util_bonus.h"

static t_color	_checkerboard_body(t_cylinder *self, t_vector3 world_point)
{
	// const double	r = s->obj.radius / (s->obj.radius + s->obj.height * 0.5);
	const t_vector3	bottom_center = v3_add(self->base.position, v3_mul(self->base.front, self->obj.height * 0.5));
	const t_vector3	local = v3_sub(world_point, bottom_center);
	const t_vector3	dot = vector3(
			v3_dot(local, self->base.right),
			v3_dot(local, self->base.up),
			0);
	t_vector3		uv;
	
	uv.x = (atan(dot.y / dot.x) + M_PI_2) / M_PI * 4;
	uv.y = v3_dot(self->base.front, local) / self->obj.height * 4;
	return (get_checkerboard_color(self->base.color, uv.x, uv.y));
}

static t_color	_checkerboard_circle(
	t_cylinder *self,
	t_vector3 world_point,
	t_circle circle)
{
	// const double	r = s->obj.radius / (s->obj.radius + s->obj.height * 0.5);
	const t_vector3	local = v3_sub(world_point, circle.center);
	const t_vector3	dot = vector3(
			v3_dot(local, self->base.right),
			v3_dot(local, self->base.up),
			0);
	t_vector3		uv;
	
	uv.x = (atan(dot.y / dot.x) + M_PI_2) / M_PI * 4;
	uv.y = v3_magnitude(local) / circle.radius;
	return (get_checkerboard_color(self->base.color, uv.x, uv.y));
}

static int	hit_circle(t_circle circ, t_ray *ray, t_range range, t_hit *record)
{
	double		d;
	double		t;
	t_vector3	v;
	t_vector3	p;

	d = v3_dot(ray->direction, circ.axis);
	if (close_to_zero(d))
		return (0);
	v = v3_sub(ray->origin, circ.center);
	t = -v3_dot(v, circ.axis) / d;
	if (range_not_in(t, range))
		return (0);
	p = get_ray_point(ray, t);
	if (v3_magnitude(v3_sub(circ.center, p)) > circ.radius)
		return (0);
	record->t = t;
	record->p = p;
	record->normal = get_face_normal(*ray, circ.axis);
	return (1);
}

static int	hit_body(t_cylinder *self, t_ray *ray, t_range range, t_hit *record)
{
	const double			half_height = self->obj.height * 0.5;
	t_cylinder_body_alias	alias;
	t_abc					abc;
	t_hit					rec;

	alias.r2 = self->obj.radius * self->obj.radius;
	alias.w = v3_sub(ray->origin, self->base.position);
	alias.vh = v3_dot(ray->direction, self->base.front);
	alias.wh = v3_dot(alias.w, self->base.front);
	abc = (t_abc){
		v3_dot(ray->direction, ray->direction) - alias.vh * alias.vh,
		v3_dot(ray->direction, alias.w) - (alias.vh * alias.wh),
		v3_dot(alias.w, alias.w) - (alias.wh * alias.wh) - (alias.r2)
	};
	if (quadratic_formula_root(abc, range, &(rec.t)))
		return (0);
	rec.p = get_ray_point(ray, rec.t);
	alias.l = v3_dot(v3_sub(rec.p, self->base.position), self->base.front);
	if (range_not_in(alias.l, (t_range){-half_height, half_height}))
		return (0);
	ft_memcpy(record, &rec, sizeof(t_hit));
	alias.in = v3_add(self->base.position, v3_mul(self->base.front, alias.l));
	record->normal = v3_normalize(v3_sub(record->p, alias.in));
	record->normal = get_face_normal(*ray, record->normal);
	return (1);
}

int	hit_cylinder(t_cylinder *self, t_ray *ray, t_range range, t_hit *record)
{
	const t_vector3	half = v3_mul(self->base.front, self->obj.height * 0.5);
	const t_circle	top = (t_circle){
		v3_add(self->base.position, half), self->base.front, self->obj.radius
	};
	const t_circle	bottom = (t_circle){
		v3_sub(self->base.position, half), v3_reverse(self->base.front),
		self->obj.radius
	};
	int				res;

	res = 0;
	record->t = range.max;
	res = res | (hit_body(self, ray, range, record) << 0);
	range.max = record->t;
	res = res | (hit_circle(top, ray, range, record) << 1);
	range.max = record->t;
	res = res | (hit_circle(bottom, ray, range, record) << 2);
	if (res & 0b100)
		record->color = _checkerboard_circle(self, record->p, bottom);
	else if (res & 0b10)
		record->color = _checkerboard_circle(self, record->p, top);
	else if (res & 0b1)
		record->color = _checkerboard_body(self, record->p);
	return (res);
}
