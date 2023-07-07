/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_camera.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonshin <yonshin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 21:42:00 by yonshin           #+#    #+#             */
/*   Updated: 2023/07/07 05:50:48 by minjungk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "camera.h"

int	init_camera(t_camera *self)
{
	self->obj.axis = v3_normalize(self->raw.axis);
	self->obj.position = self->raw.coordinate;
	self->obj.fov_radian = self->raw.fov / 180 * M_PI;
	self->base.color = vector3(0, 0, 0);
	return (EXIT_SUCCESS);
}
