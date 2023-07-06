/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_cylinder.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonshin <yonshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/02 02:08:42 by yonshin           #+#    #+#             */
/*   Updated: 2023/07/05 07:11:48 by yonshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cylinder.h"

static int	hit_circle(t_circle circ, t_ray *ray, t_range range, t_hit *record)
{
	float		d;
	float		t;
	t_vector3	v;

	d = v3_dot_prod(ray->direction, circ.axis);
	if (close_to_zero(d))
		return (0);
	v = v3_sub(ray->origin, circ.center);
	t = -v3_dot_prod(v, circ.axis) / d;
	if (range_not_in(t, range))
		return (0);
	record->t = t;
	record->p = get_ray_point(ray, t);
	if (v3_magnitude(v3_sub(circ.center, record->p)) > circ.radius)
		return (0);
	record->normal = get_face_normal(*ray, circ.axis);
	return (1);
}

static int	hit_body(t_cylinder *this, t_ray *ray, t_range range, t_hit *record)
{
	const float				half_height = this->obj.height * 0.5;
	t_cylinder_body_alias	alias;
	t_abc					abc;
	t_hit					tmprec;

	alias.r2 = this->obj.radius * this->obj.radius;
	alias.w = v3_sub(ray->origin, this->obj.position);
	alias.vh = v3_dot_prod(ray->direction, this->obj.axis);
	alias.wh = v3_dot_prod(alias.w, this->obj.axis);
	abc = (t_abc){
		v3_dot_prod(ray->direction, ray->direction) - alias.vh * alias.vh,
		v3_dot_prod(ray->direction, alias.w) - (alias.vh * alias.wh),
		v3_dot_prod(alias.w, alias.w) - (alias.wh * alias.wh) - (alias.r2)
	};
	if (quadratic_formula_root(abc, range, &(tmprec.t)))
		return (0);
	tmprec.p = get_ray_point(ray, tmprec.t);
	alias.l = v3_dot_prod(v3_sub(tmprec.p, this->obj.position), this->obj.axis);
	if (range_not_in(alias.l, (t_range){-half_height, half_height}))
		return (0);
	ft_memcpy(record, &tmprec, sizeof(t_hit));
	alias.in = v3_add(this->obj.position, v3_mul(this->obj.axis, alias.l));
	record->normal = v3_normalize(v3_sub(record->p, alias.in));
	record->normal = get_face_normal(*ray, record->normal);
	return (1);
}

int	hit_cylinder(t_cylinder *self, t_ray *ray, t_range range, t_hit *record)
{
	const t_vector3	half = v3_mul(self->obj.axis, self->obj.height * 0.5);
	const t_circle	top = (t_circle){
		v3_add(self->obj.position, half),
		self->obj.axis,
		self->obj.radius
	};
	const t_circle	bottom = (t_circle){
		v3_sub(self->obj.position, half),
		v3_reverse(self->obj.axis),
		self->obj.radius
	};
	int				res;

	res = 0;
	record->t = range.max;
	res = res | hit_body(self, ray, range, record);
	range.max = record->t;
	res = res | hit_circle(top, ray, range, record);
	range.max = record->t;
	res = res | hit_circle(bottom, ray, range, record);
	return (res);
}
