/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_cylinder.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonshin <yonshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/09 06:39:36 by yonshin           #+#    #+#             */
/*   Updated: 2023/07/12 06:00:20 by yonshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cylinder.h"

static void	_update_circle(t_cylinder *self)
{
	const t_vector3	half = v3_mul(self->base.front, self->obj.height * 0.5);
	const t_circle	top = (t_circle){
		v3_add(self->base.position, half),
		self->base.front,
		self->obj.radius
	};
	const t_circle	bottom = (t_circle){
		v3_sub(self->base.position, half),
		v3_reverse(self->base.front),
		self->obj.radius
	};

	self->obj.top = top;
	self->obj.bottom = bottom;
}

int	update_cylinder(t_cylinder *self)
{
	_update_circle(self);
	return (EXIT_SUCCESS);
}
