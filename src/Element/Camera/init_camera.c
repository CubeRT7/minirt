/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_camera.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonshin <yonshin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 21:42:00 by yonshin           #+#    #+#             */
/*   Updated: 2023/07/09 09:35:44 by minjungk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "camera.h"

static void	_init_func(t_camera *self)
{
	self->base.type_name = "Camera";
	self->base.func[Update] = update_camera;
}

int	init_camera(t_camera *self)
{
	self->base.position = self->raw.coordinate;
	self->base.front = v3_normalize(self->raw.axis);
	self->base.up = v3_preset(V3_UP);
	self->base.right = v3_cross(self->base.front, self->base.up);
	if (close_to_zero(v3_magnitude(self->base.right)))
		self->base.right = v3_preset(V3_RIGHT);
	self->base.up = v3_cross(self->base.right, self->base.front);
	self->obj.fov_radian = self->raw.fov / 180 * M_PI;
	_init_func(self);
	return (EXIT_SUCCESS);
}
