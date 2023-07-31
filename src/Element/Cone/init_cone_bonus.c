/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_cone.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonshin <yonshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 21:42:04 by yonshin           #+#    #+#             */
/*   Updated: 2023/07/28 19:26:00 by yonshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cone_bonus.h"

int	init_cone(t_cone *self)
{
	self->base.func[Hit] = hit_cone;
	self->base.func[HitColor] = hit_color_cone;
	self->base.func[Transform] = transform_cone;
	self->base.func[Update] = update_cone;
	return (EXIT_SUCCESS);
}
