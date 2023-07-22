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

static void	_init_func(t_light *self)
{
	self->base.type_name = "Light";
	self->base.func[Transform] = transform_element;
}

int	init_light(t_light *self)
{
	self->base.position = self->raw.coordinate;
	self->base.axis = v3_normalize(self->raw.axis);
	self->base.color = rgb_to_color(self->raw.rgb);
	self->obj.ratio = self->raw.ratio;
	_init_func(self);
	return (EXIT_SUCCESS);
}
