/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_plane.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonshin <yonshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 21:42:14 by yonshin           #+#    #+#             */
/*   Updated: 2023/07/28 20:00:23 by yonshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "plane.h"

int	init_plane(t_plane *self)
{
	self->base.func[Hit] = hit_plane;
	self->base.func[HitColor] = hit_color_plane;
	self->base.func[Transform] = transform_element;
	return (EXIT_SUCCESS);
}
