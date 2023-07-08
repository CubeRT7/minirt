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
	self->base.func[Hit] = hit_plane;
}

int	init_plane(t_plane *self)
{
	self->base.position = self->raw.coordinate;
	self->base.axis = v3_normalize(self->raw.axis);
	self->base.color = vector3(
			self->raw.rgb.r / 255.0,
			self->raw.rgb.g / 255.0,
			self->raw.rgb.b / 255.0);
	_init_func(self);
	return (EXIT_SUCCESS);
}
