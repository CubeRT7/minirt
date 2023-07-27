/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_color_plane_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonshin <yonshin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 06:55:17 by yonshin           #+#    #+#             */
/*   Updated: 2023/07/26 06:55:20 by yonshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "plane.h"
#include "Element/util/element_util_bonus.h"

static t_color	_checkerboard(t_plane *self, t_vector3 world_point)
{
	static const double	rate = 0.1;
	const t_vector3		local = v3_sub(world_point, self->base.position);
	const t_vector3		right = self->base.right;
	const t_vector3		up = self->base.up;
	const t_vector3		uv = vector3(
			v3_dot(local, right) * rate,
			v3_dot(local, up) * rate,
			0);

	return (get_checkerboard_color(self->base.color, uv.x, uv.y));
}

int	hit_color_plane(t_plane *self, t_hit *record)
{
	record->color = _checkerboard(self, record->p);
	return (EXIT_SUCCESS);
}
