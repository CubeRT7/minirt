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

static void	_move_elem(t_element *elem, t_vector3 delta)
{
	elem->position = v3_add(elem->position, delta);
}

int	transform_element(
	t_element *self,
	const t_element *cam,
	enum e_transform_type type,
	t_vector3 delta)
{
	const t_vector3	xz_plane = vector3(cam->front.x, 0, cam->front.z);
	const t_vector3	xz_front = v3_normalize(xz_plane);
	const t_vector3	right = v3_normalize(v3_cross(xz_front, v3_preset(V3_UP)));

	if (type & Rotation)
	{
		if ((type & 0xf) == None || (type & X))
			rotate_element(self, right, delta.x);
		if ((type & 0xf) == None || (type & Y))
			rotate_element(self, cam->up, delta.y);
		if (type & Z)
			rotate_element(self, cam->front, delta.z);
	}
	if (type & Position)
	{
		if ((type & 0xf) == None || (type & X))
			_move_elem(self, v3_mul(right, delta.x));
		if ((type & 0xf) == None || (type & Y))
			_move_elem(self, v3_mul(cam->up, delta.y));
		if (type & Z)
			_move_elem(self, v3_mul(cam->front, delta.z));
	}
	return (EXIT_SUCCESS);
}
