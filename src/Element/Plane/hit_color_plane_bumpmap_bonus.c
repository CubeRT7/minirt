/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_color_plane_bumpmap_bonus.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonshin <yonshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 12:16:18 by yonshin           #+#    #+#             */
/*   Updated: 2023/07/30 16:16:06 by yonshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "plane.h"
#include "Element/util/element_util_bonus.h"
#include "bumpmap/bumpmap_bonus.h"

t_color	hit_color_plane_bumpmap(
	t_plane *self,
	t_vector3 uv,
	t_vector3 *normal)
{
	const t_vector3	n = get_bumpmap_pixel(self->base.mapid, uv, NORMALMAP);
	const t_vector3	theta = vector3(asin(n.y), asin(n.x), 0);

	*normal = v3_rotate_axis(*normal, self->base.right, theta.x);
	*normal = v3_rotate_axis(*normal, v3_reverse(self->base.up), theta.y);
	return (v3_hadamard(
			self->base.color,
			get_bumpmap_pixel(self->base.mapid, uv, BITMAP)));
}
