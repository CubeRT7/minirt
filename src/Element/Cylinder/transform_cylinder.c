/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transform_cylinder.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonshin <yonshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 08:48:15 by yonshin           #+#    #+#             */
/*   Updated: 2023/07/14 08:48:17 by yonshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cylinder.h"

int	transform_cylinder(
	t_cylinder *self,
	const t_element *camera,
	enum e_transform_type type,
	t_vector3 delta)
{
	const t_vector3 front = v3_normalize(vector3(camera->axis.x, 0, camera->axis.z));
	const t_vector3 right = v3_normalize(v3_cross(front, vector3(0, 1, 0)));
	const t_vector3 camera_up = v3_normalize(v3_cross(right, camera->axis));
	if (type == (Rotation | X))
		self->base.axis = v3_rotate_axis(self->base.axis, right, delta.x);
	if (type == (Rotation | Y))
		self->base.axis = v3_rotate_axis(self->base.axis, camera_up, delta.x);
	if (type == (Rotation | Z))
		self->base.axis = v3_rotate_axis(self->base.axis, v3_reverse(camera->axis), delta.x);
	return (EXIT_SUCCESS);
}
