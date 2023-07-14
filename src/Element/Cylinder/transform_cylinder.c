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
	if (type & Position || type & Rotation)
		transform_element(&(self->base), camera, type, delta);
	if (type == (Scaling | Radius))
	{
		self->obj.radius += delta.x;
		if (self->obj.radius < 0)
			self->obj.radius = 0;
	}
	if (type == (Scaling | Height))
	{
		self->obj.height += delta.x;
		if (self->obj.height < 0)
			self->obj.height = 0;
	}
	return (EXIT_SUCCESS);
}
