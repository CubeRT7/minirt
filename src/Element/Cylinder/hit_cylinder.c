/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_cylinder.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonshin <yonshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/02 02:08:42 by yonshin           #+#    #+#             */
/*   Updated: 2023/07/28 20:59:46 by yonshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cylinder.h"

static t_abc	_calc_abc(
	t_cylinder *self,
	t_vector3 w,
	t_vector3 direction,
	t_vector3 axis)
{
	const double	da = v3_dot(direction, axis);
	const double	wa = v3_dot(w, axis);

	return ((t_abc){
		v3_dot(direction, direction) - da * da,
		v3_dot(direction, w) - (da * wa),
		v3_dot(w, w) - (wa * wa) - (self->r_pow_2)
	});
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
	const t_abc	abc = _calc_abc(
			self, v3_sub(ray->origin, self->base.position),
			ray->direction, self->base.front);
	double		t;
	double		h;
	t_vector3	p;
	t_vector3	in;

	if (quadratic_formula_root(abc, range, &t))
		return (0);
	p = get_ray_point(ray, t);
	h = v3_dot(v3_sub(p, self->base.position), self->base.front);
	if (range_not_in(h, (t_range){-self->half_height, self->half_height}))
		return (0);
	record->t = t;
	record->p = p;
	in = v3_add(self->base.position, v3_mul(self->base.front, h));
	record->normal = v3_normalize(v3_sub(record->p, in));
	record->normal = get_face_normal(*ray, record->normal);
	return (1);
}

int	hit_cylinder(t_cylinder *self, t_ray *ray, t_range range, t_hit *record)
{
	int	res;

	res = 0;
	record->t = range.max;
	res = res | (hit_body(self, ray, range, record) * HIT_BODY);
	range.max = record->t;
	res = res | (hit_circle(self->top, ray, range, record) * HIT_TOP);
	range.max = record->t;
	res = res | (hit_circle(self->bottom, ray, range, record) * HIT_BOTTOM);
	record->hit_status = res;
	return (res);
}
