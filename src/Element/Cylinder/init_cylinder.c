/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_cylinder.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonshin <yonshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 21:42:04 by yonshin           #+#    #+#             */
/*   Updated: 2023/07/28 19:26:00 by yonshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cylinder.h"

int	init_cylinder(t_cylinder *self)
{
	self->base.func[Hit] = hit_cylinder;
	self->base.func[HitColor] = hit_color_cylinder;
	self->base.func[Transform] = transform_cylinder;
	self->base.func[Update] = update_cylinder;
	return (EXIT_SUCCESS);
}
