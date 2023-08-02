/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_cone_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonshin <yonshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/02 02:08:42 by yonshin           #+#    #+#             */
/*   Updated: 2023/07/31 19:28:40 by yonshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cone_bonus.h"

static t_abc	_calc_abc(t_cone *self, t_vector3 w, t_vector3 d, t_vector3 a)
{
	const double	dd = v3_dot(d, d);
	const double	da = v3_dot(d, a);
	const double	dw = v3_dot(d, w);
	const double	wa = v3_dot(w, a);
	const double	ww = v3_dot(w, w);

	return ((t_abc){
		dd - pow(da, 2) * self->r1,
		dw - da * wa * self->r1 + da * self->r2 * 0.5,
		ww - pow(wa, 2) * self->r1 + wa * self->r2 - pow(self->radius, 2)
	});
}

static t_vector3	_calc_normal(t_cone *self, t_hit *rec, double h)
{
	t_vector3	q;
	t_vector3	v;
	t_vector3	axis;

	q = v3_add(self->base.position, v3_mul(self->base.front, h));
	v = v3_normalize(v3_sub(rec->p, q));
	axis = v3_cross(v, self->base.front);
	return (v3_rotate_axis(v, axis, M_PI_2 - self->theta));
}

static int	hit_body(t_cone *self, t_ray *ray, t_range range, t_hit *rec)
{
	const t_abc	abc = _calc_abc(
			self, v3_sub(ray->origin, self->base.position),
			ray->direction, self->base.front);
	double		t;
	double		h;
	t_vector3	p;

	if (quadratic_formula_root(abc, range, &t))
		return (0);
	p = get_ray_point(ray, t);
	h = v3_dot(v3_sub(p, self->base.position), self->base.front);
	if (h < 0 || h > self->height)
		return (0);
	rec->t = t;
	rec->p = p;
	rec->normal = _calc_normal(self, rec, h);
	rec->normal = get_face_normal(*ray, rec->normal);
	return (1);
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

int	hit_cone(t_cone *self, t_ray *ray, t_range range, t_hit *record)
{
	int	res;

	res = 0;
	record->t = range.max;
	res = res | (hit_body(self, ray, range, record) * HIT_BODY);
	range.max = record->t;
	res = res | (hit_circle(self->bottom, ray, range, record) * HIT_BOTTOM);
	record->hit_status = res;
	return (res);
}
