/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_cylinder.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonshin <yonshin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 21:42:04 by yonshin           #+#    #+#             */
/*   Updated: 2023/07/02 02:23:17 by yonshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cylinder.h"

int	init_cylinder(t_cylinder *self)
{
	self->obj.position = self->raw.coordinate;
	self->obj.axis = v3_normalize(self->raw.axis);
	self->obj.radius = self->raw.diameter * 0.5f;
	self->obj.height = self->raw.height;
	self->obj.color = vector3(
			self->raw.rgb.r / 255.0,
			self->raw.rgb.g / 255.0,
			self->raw.rgb.b / 255.0);
	self->color = self->obj.color;
	return (EXIT_SUCCESS);
}
