/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_color_sphere_bumpmap_bonus.c                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonshin <yonshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 12:25:39 by yonshin           #+#    #+#             */
/*   Updated: 2023/07/30 16:16:11 by yonshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sphere.h"
#include "Element/util/element_util_bonus.h"
#include "bumpmap/bumpmap_bonus.h"

t_color	hit_color_sphere_bumpmap(
	t_sphere *self,
	t_vector3 uv,
	t_vector3 *normal)
{
	const t_vector3	n = get_bumpmap_pixel(self->base.mapid, uv, NORMALMAP);
	const t_vector3	theta = vector3(asin(n.y), asin(n.x), 0);
	const t_vector3	tbn_basisx = v3_normalize(v3_cross(self->base.up, *normal));
	const t_vector3	tbn_basisy = v3_cross(*normal, tbn_basisx);

	*normal = v3_rotate_axis(*normal, tbn_basisx, theta.x);
	*normal = v3_rotate_axis(*normal, tbn_basisy, theta.y);
	return (v3_hadamard(
			self->base.color,
			get_bumpmap_pixel(self->base.mapid, uv, BITMAP)));
}
