/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_light.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonshin <yonshin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 21:42:10 by yonshin           #+#    #+#             */
/*   Updated: 2023/07/07 05:51:05 by minjungk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "light.h"

int	init_light(t_light *self)
{
	self->base.position = self->raw.coordinate;
	self->base.axis = v3_normalize(self->raw.axis);
	self->base.color = vector3(
			self->raw.rgb.r / 255.0,
			self->raw.rgb.g / 255.0,
			self->raw.rgb.b / 255.0);
	self->obj.ratio = self->raw.ratio;
	return (EXIT_SUCCESS);
}
