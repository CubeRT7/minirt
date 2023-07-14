/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transform_element.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonshin <yonshin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 00:28:06 by yonshin           #+#    #+#             */
/*   Updated: 2023/07/15 00:46:12 by yonshin          ###   ########.fr       */
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
	const t_vector3	right = v3_normalize(v3_cross(front, vector3(0, 1, 0)));
	const t_vector3	camera_up = v3_normalize(v3_cross(right, cam->axis));

	if (type == (Rotation | X))
		self->axis = v3_rotate_axis(self->axis, right, delta.x);
	if (type == (Rotation | Y))
		self->axis = v3_rotate_axis(self->axis, camera_up, delta.x);
	if (type == (Rotation | Z))
		self->axis = v3_rotate_axis(self->axis, v3_reverse(cam->axis), delta.x);
	if (type == (Position | X))
		self->position = v3_add(self->position, v3_mul(right, delta.x));
	if (type == (Position | Y))
		self->position = v3_add(self->position, v3_mul(camera_up, delta.x));
	if (type == (Position | Z))
		self->position = v3_add(self->position, v3_mul(cam->axis, -delta.x));
	return (EXIT_SUCCESS);
}
