/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_sphere.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonshin <yonshin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 21:42:17 by yonshin           #+#    #+#             */
/*   Updated: 2023/07/02 02:25:32 by yonshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sphere.h"

int	init_sphere(t_sphere *self)
{

	self->obj.color = vector3(
			self->raw.rgb.r / 255.0,
			self->raw.rgb.g / 255.0,
			self->raw.rgb.b / 255.0);
	self->obj.axis = v3_normalize(self->raw.axis);
	self->obj.position = self->raw.coordinate;
	self->obj.radius = self->raw.diameter * 0.5f;
	self->color = self->obj.color;
	return (EXIT_SUCCESS);
}
