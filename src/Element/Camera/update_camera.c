/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_camera.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonshin <yonshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/09 06:39:36 by yonshin           #+#    #+#             */
/*   Updated: 2023/07/28 20:59:24 by yonshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "camera.h"

static void	_update_viewport(t_camera *self)
{
	const t_vector3	horizontal = vector3(2.0, 0, 0);
	const t_vector3	vertical = vector3(0, self->ratio * horizontal.x, 0);
	const double	fov_half = self->fov_radian * 0.5 + 0.00000001;
	const double	focal_length = cos(fov_half) / sin(fov_half);
	t_point			lower_left_corner;

	self->viewport_horizontal = horizontal;
	self->viewport_vertical = vertical;
	lower_left_corner = v3_mul(horizontal, -0.5);
	lower_left_corner = v3_sub(lower_left_corner, v3_mul(vertical, 0.5));
	lower_left_corner = v3_sub(lower_left_corner, vector3(0, 0, focal_length));
	self->viewport_lower_left = lower_left_corner;
}

int	update_camera(t_camera *self)
{
	_update_viewport(self);
	return (EXIT_SUCCESS);
}
