/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_plane.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonshin <yonshin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 21:42:14 by yonshin           #+#    #+#             */
/*   Updated: 2023/07/07 05:51:11 by minjungk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "plane.h"

static void	_init_func(t_plane *self)
{
	self->base.type_name = "Plane";
	self->base.func[Hit] = hit_plane;
	self->base.func[HitColor] = hit_color_plane;
	self->base.func[Transform] = transform_element;
}

int	init_plane(t_plane *self)
{
	self->base.position = self->raw.coordinate;
	self->base.front = v3_normalize(self->raw.axis);
	self->base.up = v3_preset(V3_UP);
	self->base.right = v3_cross(self->base.front, self->base.up);
	if (close_to_zero(v3_magnitude(self->base.right)))
		self->base.right = v3_preset(V3_RIGHT);
	self->base.up = v3_cross(self->base.right, self->base.front);
	self->base.color = rgb_to_color(self->raw.rgb);
	_init_func(self);
	return (EXIT_SUCCESS);
}
