/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_cone.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonshin <yonshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/09 06:39:36 by yonshin           #+#    #+#             */
/*   Updated: 2023/07/28 20:59:45 by yonshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cone_bonus.h"

static void	_update_circle(t_cone *self)
{
	const t_circle	bottom = (t_circle){
		self->base.position,
		v3_reverse(self->base.front),
		self->radius
	};

	self->bottom = bottom;
}

static void	_update_constant_for_hit(t_cone *self)
{
	self->r1 = 1 + pow(self->radius, 2) / pow(self->height, 2);
	self->r2 = 2 * pow(self->radius, 2) / self->height;
	self->theta = atan(self->height / self->radius);
}

static void	_update_constant_for_color(t_cone *self)
{
	self->uv_ratio = self->radius / (self->radius + self->height);
	self->top_vertice = v3_add(
			self->base.position,
			v3_mul(self->base.front, self->height));
}

int	update_cone(t_cone *self)
{
	_update_circle(self);
	_update_constant_for_hit(self);
	_update_constant_for_color(self);
	return (EXIT_SUCCESS);
}
