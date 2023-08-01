/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_plane.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonshin <yonshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 21:42:14 by yonshin           #+#    #+#             */
/*   Updated: 2023/08/02 02:08:50 by minjungk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "plane.h"

extern int	hit_plane(t_plane *self, t_ray *r, t_range ra, t_hit *h);
extern int	hit_color_plane(t_plane *self, t_hit *record);
extern int	serialize_plane(int fd, t_element *element);

int	init_plane(t_plane *self)
{
	self->base.func[Hit] = hit_plane;
	self->base.func[HitColor] = hit_color_plane;
	self->base.func[Transform] = transform_element;
	self->base.func[Serialize] = serialize_plane;
	return (EXIT_SUCCESS);
}
