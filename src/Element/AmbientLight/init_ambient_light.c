/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_ambient_light.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonshin <yonshin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/02 02:12:26 by yonshin           #+#    #+#             */
/*   Updated: 2023/07/02 02:12:28 by yonshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ambient_light.h"

int	init_ambient_light(t_ambient_light *self)
{
	self->obj.ratio = self->raw.ratio;
	self->obj.color = (t_color){
		(float)self->raw.rgb.r / 255,
		(float)self->raw.rgb.g / 255,
		(float)self->raw.rgb.b / 255
	};
	self->color = self->obj.color;
	return (EXIT_SUCCESS);
}
