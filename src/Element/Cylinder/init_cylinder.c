/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_cylinder.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonshin <yonshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 21:42:04 by yonshin           #+#    #+#             */
/*   Updated: 2023/08/02 02:08:35 by minjungk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cylinder.h"

extern int	hit_cylinder(t_cylinder *self, t_ray *r, t_range ra, t_hit *h);
extern int	hit_color_cylinder(t_cylinder *self, t_hit *record);
extern int	transform_cylinder(
				t_cylinder *self,
				const t_element *camera,
				enum e_transform_type type,
				t_vector3 delta);
extern int	update_cylinder(t_cylinder *self);
extern int	serialize_cylinder(int fd, t_element *element);

int	init_cylinder(t_cylinder *self)
{
	self->base.func[Hit] = hit_cylinder;
	self->base.func[HitColor] = hit_color_cylinder;
	self->base.func[Transform] = transform_cylinder;
	self->base.func[Update] = update_cylinder;
	self->base.func[Serialize] = serialize_cylinder;
	return (EXIT_SUCCESS);
}
