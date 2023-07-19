/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_ambient_light.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonshin <yonshin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/02 02:12:26 by yonshin           #+#    #+#             */
/*   Updated: 2023/07/07 05:50:34 by minjungk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ambient_light.h"

static void	_init_func(t_ambient_light *self)
{
	(void)self;
}

int	init_ambient_light(t_ambient_light *self)
{
	self->base.color = rgb_to_color(self->raw.rgb);
	self->obj.ratio = self->raw.ratio;
	_init_func(self);
	return (EXIT_SUCCESS);
}
