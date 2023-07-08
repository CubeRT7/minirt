/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_sphere.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonshin <yonshin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 21:42:17 by yonshin           #+#    #+#             */
/*   Updated: 2023/07/07 05:51:23 by minjungk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sphere.h"

int	init_sphere(t_sphere *self)
{
	self->base.position = self->raw.coordinate;
	self->base.axis = v3_normalize(self->raw.axis);
	self->base.color = vector3(
			self->raw.rgb.r / 255.0,
			self->raw.rgb.g / 255.0,
			self->raw.rgb.b / 255.0);
	self->obj.radius = self->raw.diameter * 0.5f;
	return (EXIT_SUCCESS);
}
