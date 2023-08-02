/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_cylinder.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonshin <yonshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/09 06:39:36 by yonshin           #+#    #+#             */
/*   Updated: 2023/07/28 20:59:45 by yonshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cylinder.h"

static void	_update_circle(t_cylinder *self)
{
	const t_vector3	half = v3_mul(self->base.front, self->height * 0.5);
	const t_circle	top = (t_circle){
		v3_add(self->base.position, half),
		self->base.front,
		self->radius
	};
	const t_circle	bottom = (t_circle){
		v3_sub(self->base.position, half),
		v3_reverse(self->base.front),
		self->radius
	};

	self->top = top;
	self->bottom = bottom;
}

static void	_update_constant_for_hit(t_cylinder *self)
{
	self->r_pow_2 = self->radius * self->radius;
	self->half_height = self->height * 0.5;
}

int	update_cylinder(t_cylinder *self)
{
	_update_circle(self);
	_update_constant_for_hit(self);
	return (EXIT_SUCCESS);
}
