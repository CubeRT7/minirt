/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_color_plane_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonshin <yonshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 06:55:17 by yonshin           #+#    #+#             */
/*   Updated: 2023/07/30 13:36:03 by yonshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "plane.h"
#include "Element/util/element_util_bonus.h"
#include "mlx.h"
#define DENSITY 0.1

t_color	hit_color_plane_checker(t_plane *self, t_vector3 uv);
t_color	hit_color_plane_bumpmap(t_plane *self, t_vector3 uv, t_vector3 *normal);

static t_vector3	_uv(t_plane *self, t_vector3 world_point)
{
	const t_vector3		local = v3_sub(world_point, self->base.position);
	const t_vector3		right = self->base.right;
	const t_vector3		up = self->base.up;
	const t_vector3		uv = vector3(
			v3_dot(local, right) * DENSITY,
			v3_dot(local, up) * DENSITY,
			0);

	return (uv);
}

int	hit_color_plane(t_plane *self, t_hit *rec)
{
	const t_vector3	uv = _uv(self, rec->p);

	if (self->base.mapid)
		rec->color = hit_color_plane_bumpmap(self, uv, &(rec->normal));
	else
		rec->color = hit_color_plane_checker(self, uv);
	return (EXIT_SUCCESS);
}
