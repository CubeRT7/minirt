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
	self->base.axis = v3_normalize(self->raw.axis);
	self->base.axis.z -= 0.00000001;
	self->base.axis = v3_normalize(self->base.axis);
	self->obj.fov_radian = self->raw.fov / 180 * M_PI;
	_init_func(self);
	return (EXIT_SUCCESS);
}
