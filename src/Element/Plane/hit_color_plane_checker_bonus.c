/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_color_plane_checker_bonus.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonshin <yonshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 12:12:07 by yonshin           #+#    #+#             */
/*   Updated: 2023/07/29 12:23:03 by yonshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "plane.h"
#include "Element/util/element_util_bonus.h"

t_color	hit_color_plane_checker(t_plane *self, t_vector3 world_point)
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
