/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transform_element.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonshin <yonshin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 00:28:06 by yonshin           #+#    #+#             */
/*   Updated: 2023/07/17 16:53:52 by minjungk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "element_util.h"

int	transform_element(
	t_element *self,
	const t_element *cam,
	enum e_transform_type type,
	t_vector3 delta)
{
	const t_vector3	front = v3_normalize(vector3(cam->axis.x, 0, cam->axis.z));
	const t_vector3	right = v3_normalize(v3_cross(front, v3_preset(V3_UP)));
	const t_vector3	camera_up = v3_normalize(v3_cross(right, cam->axis));

	if (type & Rotation)
	{
		if ((type & 0xf) == None || (type & X))
			self->axis = v3_rotate_axis(self->axis, right, delta.x);
		if ((type & 0xf) == None || (type & Y))
			self->axis = v3_rotate_axis(self->axis, camera_up, delta.y);
		if (type & Z)
			self->axis = v3_rotate_axis(self->axis, cam->axis, delta.z);
	}
	if (type & Position)
	{
		if ((type & 0xf) == None || (type & X))
			self->position = v3_add(self->position, v3_mul(right, delta.x));
		if ((type & 0xf) == None || (type & Y))
			self->position = v3_add(self->position, v3_mul(camera_up, delta.y));
		if (type & Z)
			self->position = v3_add(self->position, v3_mul(cam->axis, delta.z));
	}
	return (EXIT_SUCCESS);
}
