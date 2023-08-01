/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_cone_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonshin <yonshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 21:42:04 by yonshin           #+#    #+#             */
/*   Updated: 2023/08/02 02:08:26 by minjungk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cone_bonus.h"

extern int	serialize_cone(int fd, t_element *element);

int	init_cone(t_cone *self)
{
	self->base.func[Hit] = hit_cone;
	self->base.func[HitColor] = hit_color_cone;
	self->base.func[Transform] = transform_cone;
	self->base.func[Update] = update_cone;
	self->base.func[Serialize] = serialize_cone;
	return (EXIT_SUCCESS);
}
