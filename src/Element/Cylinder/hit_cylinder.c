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
	const t_vector3	a = v3_normalize(circ.axis);
	const t_vector3	c = circ.center;
	const t_vector3	o = ray->origin;
	const t_vector3	d = v3_normalize(ray->direction);

	const float ad = v3_dot_prod(a, d);
	if (ad > -0.001f && ad < 0.001f)
		return 0;
	const float aco = v3_dot_prod(a, v3_sub(c, o));
	const float t = aco / ad;
	if (t < range.min || t > range.max)
		return 0;
	const t_vector3 p = v3_add(v3_mul(d, t), ray->origin);
	if (v3_magnitude(v3_sub(c, p)) > circ.radius)
		return 0;

	record->t = t;
	record->p = p;
	record->normal = a;
	record->normal = get_face_normal(*ray, record->normal);
	return 1;
}

static int hit_body(t_cylinder *this, t_ray *ray, t_range range, t_hit *record)
{
	float radius = this->obj.radius;
	float half_height = this->obj.height * 0.5;
	t_vector3 center = this->obj.position;
	t_vector3 w = v3_sub(ray->origin, center);
	t_vector3 v = v3_normalize(ray->direction);
	t_vector3 h = this->obj.axis;
	float vh = v3_dot_prod(v, h);
	float wh = v3_dot_prod(w, h);
	float a = v3_dot_prod(v, v) - vh * vh;
	float b = 2 * (v3_dot_prod(v, w) - (vh * wh));
	float c = v3_dot_prod(w, w) - (wh * wh) - (radius * radius);
	float d = b * b - 4 * a * c;
	if (d < 0)
		return 0;
	float t = (-b - sqrt(d)) / (2 * a);
	if (t < range.min || t > range.max) {
		t = (-b + sqrt(d)) / (2 * a);
		if (t < range.min || t > range.max)
			return 0;
	}
	t_vector3 p = v3_add(v3_mul(v3_normalize(ray->direction), t), ray->origin);
	float l = v3_dot_prod(v3_sub(p, center), h);
	if (l < -half_height || l > half_height)
		return 0;
	t_vector3 inner_point = v3_add(center, v3_mul(h, l));

	record->t = t;
	record->p = p;
	record->normal = v3_normalize(v3_mul(v3_sub(record->p, inner_point), 1 / radius));
	record->normal = get_face_normal(*ray, record->normal);
	return 1;
}

int	hit_cylinder(void *elem, t_ray *ray, t_range range, t_hit *record)
{
	t_cylinder *const   this = elem;
	const t_point coordinate = this->obj.position;
	const t_vector3 axis = this->obj.axis;
	const float radius = this->obj.radius;
	const float height =  this->obj.height;
	const t_vector3 half_height = v3_mul(axis, height / 2);
	const t_circle top = (t_circle){v3_add(coordinate, half_height), axis, radius};
	const t_circle bottom = (t_circle){v3_sub(coordinate, half_height), v3_reverse(axis), radius};
	int res = 0;
	record->t = range.max;
	res = res | hit_body(elem, ray, range, record);
	range.max = record->t;
	res = res | hit_circle(top, ray, range, record);
	range.max = record->t;	
	res = res | hit_circle(bottom, ray, range, record);
	return res;
}
