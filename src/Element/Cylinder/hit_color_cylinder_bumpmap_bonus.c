/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_color_cylinder_bumpmap_bonus.c                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonshin <yonshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 12:47:50 by yonshin           #+#    #+#             */
/*   Updated: 2023/07/30 16:15:58 by yonshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cylinder.h"
#include "Element/util/element_util_bonus.h"
#include "bumpmap/bumpmap_bonus.h"

static t_color	_body(
	t_cylinder *self,
	t_vector3 uv,
	t_vector3 *normal)
{
	const t_vector3	n = get_bumpmap_pixel(self->base.mapid, uv, NORMALMAP);
	const t_vector3	theta = vector3(asin(n.y), asin(n.x), 0);
	const t_vector3	tbn_basis_y = self->base.up;
	const t_vector3	tbn_basis_x = v3_cross(self->base.up, *normal);

	*normal = v3_rotate_axis(*normal, tbn_basis_x, theta.x);
	*normal = v3_rotate_axis(*normal, tbn_basis_y, theta.y);
	return (v3_hadamard(
			self->base.color,
			get_bumpmap_pixel(self->base.mapid, uv, BITMAP)));
}

static t_color	_circle(
	t_cylinder *self,
	t_vector3 uv,
	t_hit *record,
	t_circle circle)
{
	const t_vector3	local = v3_sub(record->p, circle.center);
	const t_vector3	n = get_bumpmap_pixel(self->base.mapid, uv, NORMALMAP);
	const t_vector3	theta = vector3(asin(n.y), asin(n.x), 0);
	t_vector3		tbn_basis_y;
	t_vector3		tbn_basis_x;

	if (uv.y < 0.5)
		tbn_basis_y = v3_normalize(v3_reverse(local));
	else
		tbn_basis_y = v3_normalize(local);
	tbn_basis_x = v3_cross(tbn_basis_y, record->normal);
	record->normal = v3_rotate_axis(record->normal, tbn_basis_x, theta.x);
	record->normal = v3_rotate_axis(record->normal, tbn_basis_y, theta.y);
	return (v3_hadamard(
			self->base.color,
			get_bumpmap_pixel(self->base.mapid, uv, BITMAP)));
}

t_color	hit_color_cylinder_bumpmap(
	t_cylinder *self,
	t_vector3 uv,
	t_hit *record)
{
	t_color	res;

	res = v3_preset(V3_ZERO);
	if (record->hit_status & HIT_BOTTOM)
		res = _circle(self, uv, record, self->bottom);
	else if (record->hit_status & HIT_TOP)
		res = _circle(self, uv, record, self->top);
	else if (record->hit_status & HIT_BODY)
		res = _body(self, uv, &(record->normal));
	return (res);
}
