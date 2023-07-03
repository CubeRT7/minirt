/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_camera.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonshin <yonshin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 21:42:00 by yonshin           #+#    #+#             */
/*   Updated: 2023/07/02 02:14:03 by yonshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "camera.h"

int	init_camera(t_camera *self)
{
	const t_vector3	normalized_axis = v3_normalize(self->raw.axis);

	self->obj.angle = vector3(
			acosf(v3_dot_prod(vector3(1, 0, 0), normalized_axis)),
			acosf(v3_dot_prod(vector3(0, 1, 0), normalized_axis)),
			acosf(v3_dot_prod(vector3(0, 0, 1), normalized_axis)));
	self->obj.position = self->raw.coordinate;
	self->obj.fov_radian = self->raw.fov / 180 * M_PI;
	self->color = vector3(0, 0, 0);
	return (EXIT_SUCCESS);
}
