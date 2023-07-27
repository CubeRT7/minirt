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
	self->base.type_name = "Cylinder";
	self->base.func[Hit] = hit_cylinder;
	self->base.func[HitColor] = hit_color_cylinder;
	self->base.func[Transform] = transform_cylinder;
	self->base.func[Update] = update_cylinder;
}

int	init_cylinder(t_cylinder *self)
{
	self->base.position = self->raw.coordinate;
	self->base.front = v3_normalize(self->raw.axis);
	self->base.up = v3_preset(V3_UP);
	self->base.right = v3_cross(self->base.front, self->base.up);
	if (close_to_zero(v3_magnitude(self->base.right)))
		self->base.right = v3_preset(V3_RIGHT);
	self->base.up = v3_cross(self->base.right, self->base.front);
	self->base.color = rgb_to_color(self->raw.rgb);
	self->obj.radius = self->raw.diameter * 0.5;
	self->obj.height = self->raw.height;
	_init_func(self);
	return (EXIT_SUCCESS);
}
