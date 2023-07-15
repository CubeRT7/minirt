/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transform_sphere.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonshin <yonshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 08:48:50 by yonshin           #+#    #+#             */
/*   Updated: 2023/07/14 08:50:28 by yonshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sphere.h"

int	transform_sphere(
	t_sphere *self,
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
	return (EXIT_SUCCESS);
}
