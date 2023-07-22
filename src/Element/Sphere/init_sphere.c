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

static void	_init_func(t_sphere *self)
{
	self->base.type_name = "Sphere";
	self->base.func[Hit] = hit_sphere;
	self->base.func[Transform] = transform_sphere;
}

int	init_sphere(t_sphere *self)
{
	self->base.position = self->raw.coordinate;
	self->base.axis = v3_normalize(self->raw.axis);
	self->base.color = rgb_to_color(self->raw.rgb);
	self->obj.radius = self->raw.diameter * 0.5;
	_init_func(self);
	return (EXIT_SUCCESS);
}
