/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_cylinder.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonshin <yonshin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 21:42:04 by yonshin           #+#    #+#             */
/*   Updated: 2023/07/07 05:51:01 by minjungk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cylinder.h"

static void	_init_func(t_cylinder *self)
{
	self->base.func[Hit] = hit_cylinder;
}

int	init_cylinder(t_cylinder *self)
{
	self->base.position = self->raw.coordinate;
	self->base.axis = v3_normalize(self->raw.axis);
	self->base.color = vector3(
			self->raw.rgb.r / 255.0,
			self->raw.rgb.g / 255.0,
			self->raw.rgb.b / 255.0);
	self->obj.radius = self->raw.diameter * 0.5f;
	self->obj.height = self->raw.height;
	_init_func(self);
	return (EXIT_SUCCESS);
}
